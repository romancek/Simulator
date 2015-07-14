#pragma once
#include "stdafx.h"
namespace BeepingModel{
	ref class Observer
	{
	private:
		bool stop;
		bool _can_draw; //true:draw,false:undraw
	public:
		Visualizer^ _vis;
		Controller^ _cnt;
		DataManager^ _dmg;
	public:
		Observer(void);
		Observer(Controller^, Visualizer^, DataManager^);
		void Run();
		void Simulate();
		bool DetectTerminate();
		bool isFinished();
		bool isValid();

	public:
		property bool Stop
		{
				bool get(){return this->stop;}
				void set(bool value){this->stop = value;}
		}
		property bool CanDraw
		{
				bool get(){return this->_can_draw;}
				void set(bool value){this->_can_draw = value;}
		}
	};
}
