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
	this->controller = c;
	this->g = gr;
	this->x = x;
	this->y = y;
}

void Visualizer::Draw(void)
{
	using namespace std;
	Pen^ pen_node = gcnew Pen(Color::Black,0.5f);
	Pen^ dammy = gcnew Pen(Color::Gainsboro,0.1f);
	SolidBrush^ brush = gcnew SolidBrush( Color::Gainsboro );
	this->g->DrawEllipse(dammy, Rectangle(100,100,5,5));
	int dx=0;
	int dy=0;
	int i = 0;
	bool selected = false;
	multimap<int,int> exist_area;
	//if( this->controller->Updated ) {
		random::mt19937 gen( static_cast<unsigned long>(time(0)) );
		this->controller->Updated = false;
	//}
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
	for each(Channel^ ch in this->controller->channels)
	{
		array<int>^ p1 = this->controller->nodes[ch->EndPoint[0]]->GetPosition();
		array<int>^ p2 = this->controller->nodes[ch->EndPoint[1]]->GetPosition();
#ifdef _DEBUG
		String^ a = String::Format("DrawLine,channel id:{4} , p1[{0},{1}], p2[{2},{3}]", p1[0], p1[1], p2[0], p2[1],ch->Id);
		System::Diagnostics::Debug::WriteLine(a);
#endif
		this->g->DrawLine(pen_node, p1[0]+NODE_SIZE/2, p1[1]+NODE_SIZE/2, p2[0]+NODE_SIZE/2, p2[1]+NODE_SIZE/2);
	}

	for each(Node^ n in this->controller->nodes)
	{
		array<int>^ pos = n->GetPosition();
		Rectangle rect = Rectangle(pos[0],pos[1],NODE_SIZE,NODE_SIZE);
		this->g->FillRectangle( brush, rect );
		this->g->DrawEllipse( pen_node, rect );
	}
}
