#include "StdAfx.h"
#include "Visualizer.h"
#include "Channel.h"
#include "Form1.h"

using namespace BeepingModel;
using namespace System::Drawing;
Visualizer::Visualizer(void)
{

}

Visualizer::Visualizer(Controller^ c,Graphics^ gr)
{
	this->controller = c;
	this->g = gr;
}

void Visualizer::Draw(void)
{
	Pen^ p = gcnew Pen(Color::Blue,3.0f);
	Rectangle rect = Rectangle(100,100,50,50);
	this->g->DrawLine(p, 100.0F,240.0F,160.0F,20.0F);
}