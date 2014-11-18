#include "StdAfx.h"
#include "Visualizer.h"
#include "Channel.h"
#include "Form1.h"
#include <boost/random.hpp>
#include "Controller.h"
#include "Node.h"
#include <map>

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
	Pen^ p = gcnew Pen(Color::Black,0.5f);
	Pen^ dammy = gcnew Pen(Color::Gainsboro,0.1f);
	this->g->DrawEllipse(dammy, Rectangle(100,100,5,5));
	int dx=0;
	int dy=0;
	int i = 0;
	bool selected = false;
	multimap<int,int> exist_area;
	random::mt19937 gen( 100 );	//TODO seed use devicecontext
	random::uniform_int_distribution<> distX(0,this->x-1);
	random::uniform_int_distribution<> distY(0,this->y-1);
	while(i < N_SIZE)
	{
		dx = distX(gen);
		dy = distY(gen);
		for(multimap<int,int>::iterator itr = exist_area.begin(); itr != exist_area.end(); ++itr){
			//èdÇ»ÇËîªíË TODO distance(p1,p2) <= NODE_SIZE*2
			if( ((*itr).first + NODE_SIZE*_DENSITY > dx && (*itr).first - NODE_SIZE*_DENSITY < dx)
				&& ((*itr).second + NODE_SIZE*_DENSITY > dy && (*itr).second - NODE_SIZE*_DENSITY < dy)){
					selected = true;
					break;
			} else {
				selected = false;
			}
		}
		//node already exists
		if(!selected){
			this->g->DrawEllipse(p,Rectangle(dx,dy,NODE_SIZE,NODE_SIZE));
			array<int>^ position = {dx,dy};
			this->controller->nodes[i]->SetPosition(position);
			exist_area.insert(pair <int, int> (dx, dy));
			selected = false;
			i++;
		}else{//node not exists
			continue;
		}
	}
}