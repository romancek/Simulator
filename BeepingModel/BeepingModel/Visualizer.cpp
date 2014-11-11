#include "StdAfx.h"
#include "Visualizer.h"
#include "Channel.h"
#include "Form1.h"

using namespace BeepingModel;
Visualizer::Visualizer(void)
{

}

Visualizer::Visualizer(Controller^ c)
{
	this->controller = c;
}

void Visualizer::Draw(void)
{

}