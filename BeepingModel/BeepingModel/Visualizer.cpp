#include "StdAfx.h"
#include "Visualizer.h"
#include "Channel.h"
#include "Form1.h"

#include "Controller.h"
#include "Node.h"


using namespace BeepingModel;
using namespace System::Drawing;
using namespace boost;
Visualizer::Visualizer(void)
{

}

Visualizer::Visualizer(Controller^ c, Graphics^ gr)
{
	//•`‰æ—p
	//silent,beep,collision
	this->pen_line = gcnew array<Pen^>(3) ;
	this->pen_line[0] = gcnew Pen(Color::Black,0.5f);
	this->pen_line[1] = gcnew Pen(Color::DarkOrange,0.5f);
	this->pen_line[2] = gcnew Pen(Color::Red,0.5f);
	//sleep,inactive,competing,MIS
	this->pen_node = gcnew array<Pen^>(4);
	this->pen_node[0] = gcnew Pen(Color::White,0.5f); 
	this->pen_node[1] = gcnew Pen(Color::Black,0.5f);
	this->pen_node[2] = gcnew Pen(Color::HotPink,0.5f);
	this->pen_node[3] = gcnew Pen(Color::Red,0.5f);
	this->brush = gcnew array<SolidBrush^>(2);
	this->brush[0] = gcnew SolidBrush( Color::Gainsboro );
	this->brush[1] = gcnew SolidBrush( Color::Red );
	
	this->controller = c;
	this->g = gr;
	this->stop = false;
}

void Visualizer::Draw(void)
{
	int type = 0;	// 0:silent, 1:beep, 2:collision
	for each(Channel^ ch in this->controller->channels)
	{
		array<int>^ p1 = this->controller->nodes[ch->EndPoint[0]]->GetPosition();
		array<int>^ p2 = this->controller->nodes[ch->EndPoint[1]]->GetPosition();
#ifdef _DEBUG
		String^ a = String::Format("DrawLine,channel id:{4} , p1[{0},{1}], p2[{2},{3}]", p1[0], p1[1], p2[0], p2[1],ch->Id);
		//System::Diagnostics::Debug::WriteLine(a);
#endif

		if((this->controller->nodes[ch->EndPoint[0]]->ActionState == listen  || this->controller->nodes[ch->EndPoint[0]]->ActionState ==sleep) 
			&& (this->controller->nodes[ch->EndPoint[1]]->ActionState == listen || this->controller->nodes[ch->EndPoint[1]]->ActionState == sleep)){ //silent or sleep
			type = 0;
		}else if(this->controller->nodes[ch->EndPoint[0]]->ActionState == beeping 
			&& this->controller->nodes[ch->EndPoint[1]]->ActionState == beeping){ //collision
			type = 2;
		}else{//beep
			type = 1;
		}
		this->g->DrawLine(this->pen_line[type], p1[0]+NODE_SIZE/2, p1[1]+NODE_SIZE/2, p2[0]+NODE_SIZE/2, p2[1]+NODE_SIZE/2);
	}

	for each(Node^ n in this->controller->nodes)
	{
		if(n->NodeState == sleep){
			type = 0;
		}else if(n->NodeState == inactive){
			type = 1;
		}else if(n->NodeState == competing){
			type = 2;
		}else if(n->NodeState == MIS){
			type = 3;
		}
		array<int>^ pos = n->GetPosition();
		Rectangle rect = Rectangle(pos[0],pos[1],NODE_SIZE,NODE_SIZE);
		this->g->FillEllipse( this->brush[type/3], rect );
		this->g->DrawEllipse( this->pen_node[type], rect );
	}
}

void Visualizer::Clear()
{
	this->g->Clear( Color::Gainsboro );
}

void Visualizer::SetParameter(Settings* setting)
{
	if(setting->AA){
		this->g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
	}else{
		this->g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::None;
	}

}

void Visualizer::Run(void)
{
	while(1){
		this->controller->Run();
		this->Clear();
		this->Draw();
#ifdef _DEBUG
		System::Diagnostics::Debug::WriteLine(String::Format("global round:{0}",this->controller->GlobalRound));
#endif
		if( this->stop )break;
		Thread::Sleep(_run_speed_ms);
	}
}
