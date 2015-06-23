#include "StdAfx.h"

using namespace BeepingModel;
using namespace System::Drawing;

Visualizer::Visualizer(void)
{

}

Visualizer::Visualizer(Controller^ c, Graphics^ gr)
{
	this->AllocatePens();
	this->controller = c;
	this->g = gr;
}

void Visualizer::AllocatePens()
{
	//silent,beep,collision
	this->pen_line = gcnew array<Pen^>(3);
	this->pen_line[0] = gcnew Pen(Color::Black, PEN_WIDTH);
	this->pen_line[1] = gcnew Pen(Color::DarkOrange, PEN_WIDTH);
	this->pen_line[2] = gcnew Pen(Color::Red, PEN_WIDTH);
	//sleep,inactive,competing,MIS
	this->pen_node = gcnew array<Pen^>(4);
	this->pen_node[0] = gcnew Pen(Color::White, PEN_WIDTH);
	this->pen_node[1] = gcnew Pen(Color::Black, PEN_WIDTH);
	this->pen_node[2] = gcnew Pen(Color::HotPink, PEN_WIDTH);
	this->pen_node[3] = gcnew Pen(Color::Red, PEN_WIDTH);
	this->brush = gcnew array<SolidBrush^>(2);
	this->brush[0] = gcnew SolidBrush(Color::Gainsboro);
	this->brush[1] = gcnew SolidBrush(Color::Red);

}

void Visualizer::Draw(void)
{
	//Double Buffering
	BufferedGraphicsContext^ currentContext = BufferedGraphicsManager::Current;
	BufferedGraphics^ grafx = currentContext->Allocate(this->g, Rectangle(0, 0, this->controller->x, this->controller->y));
	grafx->Graphics->Clear(Color::White);

	//AA
	if (this->AA)
	{
		grafx->Graphics->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
	}
	else
	{
		grafx->Graphics->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::None;
	}

	switch (channel_mode)
	{
	case 0:
		this->DrawSingleChannel(grafx);
		break;
	case 1:
		this->DrawMultiChannel(grafx);
		break;
	default:
		break;
	}

	//Render & Release Double Buffer
	grafx->Render();
	grafx->~BufferedGraphics();
}

void Visualizer::DrawSingleChannel(BufferedGraphics^ grafx)
{
	int type = 0;	// 0:silent, 1:beep, 2:collision
	for each(Channel^ ch in this->controller->channels)
	{
		array<int>^ ep = ch->EndPoint;
		if (ep[0] == CH_EMPTY)
		{
#ifdef _DEBUG
			System::Diagnostics::Debug::Fail("Channel has not endpoints node");
#endif
		}
		else if (ep[0] < 0)
		{
			continue;
		}
		array<int>^ p1 = this->controller->nodes[ep[0]]->GetPosition();
		array<int>^ p2 = this->controller->nodes[ep[1]]->GetPosition();
#ifdef _DEBUG
		String^ a = String::Format("DrawLine,channel id:{4} , p1[{0},{1}], p2[{2},{3}]", p1[0], p1[1], p2[0], p2[1], ch->Id);
		//System::Diagnostics::Debug::WriteLine(a);
#endif

		if ((this->controller->nodes[ep[0]]->ActionState == listen || this->controller->nodes[ep[0]]->ActionState == sleep)
			&& (this->controller->nodes[ep[1]]->ActionState == listen || this->controller->nodes[ep[1]]->ActionState == sleep)) //silent or sleep
		{
			type = 0;
		}
		else if (this->controller->nodes[ep[0]]->ActionState == beeping
			&& this->controller->nodes[ep[1]]->ActionState == beeping) //collision
		{
			type = 2;
		}
		else //beep
		{
			type = 1;
		}
		grafx->Graphics->DrawLine(this->pen_line[type], p1[0] + NODE_SIZE / 2, p1[1] + NODE_SIZE / 2, p2[0] + NODE_SIZE / 2, p2[1] + NODE_SIZE / 2);
	}

	for each (Node^ n in this->controller->nodes)
	{
		if (n->NodeState == sleep){
			type = 0;
		}
		else if (n->NodeState == inactive)
		{
			type = 1;
		}
		else if (n->NodeState == competing)
		{
			type = 2;
		}
		else if (n->NodeState == MIS)
		{
			type = 3;
		}
		array<int>^ pos = n->GetPosition();
		Rectangle rect = Rectangle(pos[0], pos[1], NODE_SIZE, NODE_SIZE);
		grafx->Graphics->FillEllipse(this->brush[type / 3], rect);
		grafx->Graphics->DrawEllipse(this->pen_node[type], rect);
	}
}

void Visualizer::DrawMultiChannel(BufferedGraphics^ grafx)
{
	int type = 0;	// 0:silent, 1:beep, 2:collision
	for each(Channel^ ch in this->controller->channels)
	{
		array<int>^ ep = ch->EndPoint;
		if (ep[0] == CH_EMPTY)
		{
#ifdef _DEBUG
			System::Diagnostics::Debug::Fail("Channel has not endpoints node");
#endif
		}
		else if (ep[0] < 0)
		{
			continue;
		}
		array<int>^ p1 = this->controller->nodes[ep[0]]->GetPosition();
		array<int>^ p2 = this->controller->nodes[ep[1]]->GetPosition();
#ifdef _DEBUG
		String^ a = String::Format("DrawLine,channel id:{4} , p1[{0},{1}], p2[{2},{3}]", p1[0], p1[1], p2[0], p2[1], ch->Id);
		//System::Diagnostics::Debug::WriteLine(a);
#endif

		if ((this->controller->nodes[ep[0]]->ActionState == listen || this->controller->nodes[ep[0]]->ActionState == sleep)
			&& (this->controller->nodes[ep[1]]->ActionState == listen || this->controller->nodes[ep[1]]->ActionState == sleep)) //silent or sleep
		{
			type = 0;
		}
		else if (this->controller->nodes[ep[0]]->ActionState == beeping
			&& this->controller->nodes[ep[1]]->ActionState == beeping
			&& this->controller->nodes[ep[0]]->current_ch == this->controller->nodes[ep[1]]->current_ch) //collision
		{
			type = 2;
		}
		else //beep
		{
			type = 1;
		}

		if (type == 1)
		{
			if ((this->controller->nodes[ep[0]]->ActionState == beeping
				&& this->controller->nodes[ep[1]]->ActionState == listen)
				|| (this->controller->nodes[ep[0]]->ActionState == listen
				&& this->controller->nodes[ep[1]]->ActionState == beeping))
			{
				int _ch_color = 0;
				if (this->controller->nodes[ep[0]]->ActionState == beeping)
				{
					_ch_color = this->controller->nodes[ep[0]]->current_ch;
				}
				else
				{
					_ch_color = this->controller->nodes[ep[1]]->current_ch;
				}
				grafx->Graphics->DrawLine(this->pen_line_multi[_ch_color], p1[0] + NODE_SIZE / 2, p1[1] + NODE_SIZE / 2, p2[0] + NODE_SIZE / 2, p2[1] + NODE_SIZE / 2);
			}
			else
			{
				int _xc = (p1[0] + p2[0] + NODE_SIZE) / 2, _yc = (p1[1] + p2[1] + NODE_SIZE) / 2;
				int _ch_color0 = 0, _ch_color1 = 0;
				_ch_color0 = this->controller->nodes[ep[0]]->current_ch;
				_ch_color1 = this->controller->nodes[ep[1]]->current_ch;
				grafx->Graphics->DrawLine(this->pen_line_multi[_ch_color0], p1[0] + NODE_SIZE / 2, p1[1] + NODE_SIZE / 2, _xc, _yc);
				grafx->Graphics->DrawLine(this->pen_line_multi[_ch_color1], _xc, _yc, p2[0] + NODE_SIZE / 2, p2[1] + NODE_SIZE / 2);
			}
		}
		else
		{
			grafx->Graphics->DrawLine(this->pen_line[type], p1[0] + NODE_SIZE / 2, p1[1] + NODE_SIZE / 2, p2[0] + NODE_SIZE / 2, p2[1] + NODE_SIZE / 2);
		}
	}

	for each (Node^ n in this->controller->nodes)
	{
		if (n->NodeState == Lonely){
			type = 1;
		}
		else if (n->NodeState == ( MIS || MM ))
		{
			type = 3;
		}
		array<int>^ pos = n->GetPosition();
		Rectangle rect = Rectangle(pos[0], pos[1], NODE_SIZE, NODE_SIZE);
		grafx->Graphics->FillEllipse(this->brush[type / 3], rect);
		grafx->Graphics->DrawEllipse(this->pen_node[type], rect);
	}
}

void Visualizer::MakeMultiColors()
{
	this->pen_line_multi = gcnew array<Pen^>(this->F);
	boost::random_device rd;
	boost::random::mt19937 gen(rd());
	boost::random::uniform_int_distribution<> dist(0, 2^24-1);
	int _color;
	for (unsigned int i = 0; i < F;i++)
	{
		_color = dist(gen);
		if (_color == (0xFF0000 || 0x000000 || 0xFFFFFF))continue;
		this->pen_line_multi[i] = gcnew Pen(Color::FromArgb(_color), PEN_WIDTH);
	}
}

void Visualizer::Clear()
{
	this->g->Clear( Color::White );
}

void Visualizer::SetParameter(Settings* settings)
{
	this->AA = settings->AA;
	this->NODE_SIZE = settings->NODE_SIZE;
	this->PEN_WIDTH = settings->PEN_WIDTH;
	this->F = settings->F;
	if (this->F == 1)
	{
		this->channel_mode = 0;
	}
	else
	{
		this->channel_mode = 1;
		this->MakeMultiColors();
	}
	this->AllocatePens();
}


