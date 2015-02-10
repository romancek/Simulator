#include "StdAfx.h"

using namespace BeepingModel;
using namespace System::Drawing;

Visualizer::Visualizer(void)
{

}

Visualizer::Visualizer(Controller^ c, Graphics^ gr)
{
	//•`‰æ—p
	//silent,beep,collision
	this->pen_line = gcnew array<Pen^>(3) ;
	this->pen_line[0] = gcnew Pen(Color::Black,PEN_WIDTH);
	this->pen_line[1] = gcnew Pen(Color::DarkOrange,PEN_WIDTH);
	this->pen_line[2] = gcnew Pen(Color::Red,PEN_WIDTH);
	//sleep,inactive,competing,MIS
	this->pen_node = gcnew array<Pen^>(4);
	this->pen_node[0] = gcnew Pen(Color::White,PEN_WIDTH); 
	this->pen_node[1] = gcnew Pen(Color::Black,PEN_WIDTH);
	this->pen_node[2] = gcnew Pen(Color::HotPink,PEN_WIDTH);
	this->pen_node[3] = gcnew Pen(Color::Red,PEN_WIDTH);
	this->brush = gcnew array<SolidBrush^>(2);
	this->brush[0] = gcnew SolidBrush( Color::Gainsboro );
	this->brush[1] = gcnew SolidBrush( Color::Red );
	
	this->controller = c;
	this->g = gr;
}

void Visualizer::Draw(void)
{
	//Double Buffering
	BufferedGraphicsContext^ currentContext = BufferedGraphicsManager::Current;
	BufferedGraphics^ grafx = currentContext->Allocate(this->g,  Rectangle( 0, 0, this->controller->x, this->controller->y ));
	grafx->Graphics->Clear( Color::White );

	//AA
	if ( this->AA )
	{
		grafx->Graphics->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
	}
	else
	{
		grafx->Graphics->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::None;
	}

	int type = 0;	// 0:silent, 1:beep, 2:collision
	for each(Channel^ ch in this->controller->channels)
	{
		array<int>^ ep = ch->EndPoint;
		if (ep[0] < 0) {
			throw std::logic_error("Channel has node id of invalid number");
		}
		array<int>^ p1 = this->controller->nodes[ep[0]]->GetPosition();
		array<int>^ p2 = this->controller->nodes[ep[1]]->GetPosition();
#ifdef _DEBUG
		String^ a = String::Format("DrawLine,channel id:{4} , p1[{0},{1}], p2[{2},{3}]", p1[0], p1[1], p2[0], p2[1],ch->Id);
		//System::Diagnostics::Debug::WriteLine(a);
#endif

		if ( ( this->controller->nodes[ep[0]]->ActionState == listen  || this->controller->nodes[ep[0]]->ActionState ==sleep ) 
			&& ( this->controller->nodes[ep[1]]->ActionState == listen || this->controller->nodes[ep[1]]->ActionState == sleep ) ) //silent or sleep
		{ 
			type = 0;
		}
		else if ( this->controller->nodes[ep[0]]->ActionState == beeping 
			&& this->controller->nodes[ep[1]]->ActionState == beeping ) //collision
		{ 
			type = 2;
		}
		else //beep
		{
			type = 1;
		}
		grafx->Graphics->DrawLine(this->pen_line[type], p1[0]+NODE_SIZE/2, p1[1]+NODE_SIZE/2, p2[0]+NODE_SIZE/2, p2[1]+NODE_SIZE/2);
	}

	for each ( Node^ n in this->controller->nodes )
	{
		if ( n->NodeState == sleep ){
			type = 0;
		}
		else if ( n->NodeState == inactive )
		{
			type = 1;
		}
		else if ( n->NodeState == competing )
		{
			type = 2;
		}
		else if ( n->NodeState == MIS )
		{
			type = 3;
		}
		array<int>^ pos = n->GetPosition();
		Rectangle rect = Rectangle(pos[0],pos[1],NODE_SIZE,NODE_SIZE);
		grafx->Graphics->FillEllipse( this->brush[type/3], rect );
		grafx->Graphics->DrawEllipse( this->pen_node[type], rect );
	}
	//Render & Release Double Buffer
	grafx->Render();
	grafx->~BufferedGraphics();
}

void Visualizer::Clear()
{
	this->g->Clear( Color::White );
}

void Visualizer::SetParameter(Settings* settings)
{
	this->AA = settings->AA;
}

