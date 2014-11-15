#include "StdAfx.h"
#include "Visualizer.h"
#include "Channel.h"
#include "Form1.h"
#include <boost/random.hpp>
#include "Controller.h"
#include "Node.h"

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
	Pen^ p = gcnew Pen(Color::Black,0.5f);
	this->g->DrawEllipse(p, Rectangle(100,100,5,5));
	int dx=0;
	int dy=0;
	random::mt19937 gen( 100 );	//TODO seed use devicecontext
	random::uniform_int_distribution<> distX(0,this->x-1);
	random::uniform_int_distribution<> distY(0,this->y-1);
	for each(Node^ n in this->controller->nodes)
	{
		dx = distX(gen);
		dy = distY(gen);
		this->g->DrawEllipse(p,Rectangle(dx,dy,5,5));
	}
}