#include "stdafx.h"
using namespace BeepingModel;
Observer::Observer(void)
{
	this->stop = true;
	this->_can_draw = true;
}

Observer::Observer(Controller^ controller, Visualizer^ visualizer)
{
	this->stop = true;
	this->_can_draw = true;
	this->_cnt = controller;
	this->_vis = visualizer;
}

void Observer::Run()
{
	while(1)
	{
		this->_cnt->Run();
		TimeWatch t;
		if ( _can_draw ) this->_vis->Draw();
		System::Diagnostics::Debug::WriteLine(String::Format("{0}ms/round", t.elapsed()));
		if ( this->stop )break;
		Thread::Sleep(_Run_Speed_ms);
	}
}

void Observer::Record()
{

}