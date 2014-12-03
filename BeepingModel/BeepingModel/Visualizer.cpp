#include "StdAfx.h"
#include "Visualizer.h"
#include "Channel.h"
#include "Form1.h"
#include <boost/random.hpp>
#include "Controller.h"
#include "Node.h"
#include <map>
#include <ctime>

using namespace BeepingModel;
using namespace System::Drawing;
using namespace boost;
Visualizer::Visualizer(void)
{

}

Visualizer::Visualizer(Controller^ c, Graphics^ gr, int x, int y)
{
	//ï`âÊóp
	this->pen_line = gcnew array<Pen^>(3) ;
	this->pen_line[0] = gcnew Pen(Color::Black,0.5f);
	this->pen_line[1] = gcnew Pen(Color::DarkOrange,0.5f);
	this->pen_line[2] = gcnew Pen(Color::Red,0.5f);
	this->pen_node = gcnew array<Pen^>(2);
	this->pen_node[0] = this->pen_line[0];
	this->pen_node[1] = this->pen_line[1];
	this->brush = gcnew SolidBrush( Color::Gainsboro );
	
	this->controller = c;
	this->g = gr;
	this->x = x;
	this->y = y;
}

void Visualizer::Set(void)
{
	using namespace std;
	int dx=0;
	int dy=0;
	int i = 0;
	bool selected = false;
	multimap<int,int> exist_area;

	random::mt19937 gen( static_cast<unsigned long>(time(0)) );
	this->controller->Updated = false;
	random::uniform_int_distribution<> distX(0,this->x-1);
	random::uniform_int_distribution<> distY(0,this->y-1);
	
	while(i < this->controller->N)
	{
		dx = distX(gen);
		dy = distY(gen);
		if(dx + NODE_SIZE > this->x || dx - NODE_SIZE < 0 
			|| dy + NODE_SIZE > this->y || dy - NODE_SIZE < 0) continue;
		
		for(multimap<int,int>::iterator itr = exist_area.begin(); itr != exist_area.end(); ++itr){
			//èdÇ»ÇËîªíË TODO distance(p1,p2) <= NODE_SIZE*2
			if( ((*itr).first + NODE_SIZE* this->controller->Density > dx && (*itr).first - NODE_SIZE*this->controller->Density < dx)
				&& ((*itr).second + NODE_SIZE*this->controller->Density > dy && (*itr).second - NODE_SIZE*this->controller->Density < dy)){
					selected = true;
					break;
			} else {
				selected = false;
			}
		}
		//node not exists
		if(!selected){
			array<int>^ position = {dx,dy};
			this->controller->nodes[i]->SetPosition(position);
			exist_area.insert(pair <int, int> (dx, dy));
			selected = false;
			i++;
		}else{//node already exists
			continue;
		}
	}
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
		System::Diagnostics::Debug::WriteLine(a);
#endif

		if(this->controller->nodes[ch->EndPoint[0]]->ActionState == listen 
			&& this->controller->nodes[ch->EndPoint[1]]->ActionState == listen){ //silent
			type = 0;
		}else if(this->controller->nodes[ch->EndPoint[0]]->ActionState == beeping 
			&& this->controller->nodes[ch->EndPoint[1]]->ActionState == beeping){ //collision
			type = 2;
		}else{ //beep
			type = 1;
		}
		this->g->DrawLine(pen_line[type], p1[0]+NODE_SIZE/2, p1[1]+NODE_SIZE/2, p2[0]+NODE_SIZE/2, p2[1]+NODE_SIZE/2);
	}

	for each(Node^ n in this->controller->nodes)
	{
		if(n->ActionState == listen){
			type = 0;
		}else{
			type = 1;
		}
		array<int>^ pos = n->GetPosition();
		Rectangle rect = Rectangle(pos[0],pos[1],NODE_SIZE,NODE_SIZE);
		this->g->FillRectangle( this->brush, rect );
		this->g->DrawEllipse( this->pen_node[type], rect );
	}
}

void Visualizer::Clear()
{
	this->g->Clear( Color::Gainsboro );
}

void Visualizer::AA(bool aa)
{
	if(aa){
		this->g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
	}else{
		this->g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::None;
	}
}