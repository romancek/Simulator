#pragma once
#include "stdafx.h"
namespace BeepingModel{
	ref class Observer
	{
	private:
		bool stop;
		bool drawing; //true:draw,false:undraw
		unsigned int exec_times;
		unsigned int exec_start;
		unsigned int exec_end;
		unsigned int exec_interval;
		bool same_topology;
	public:
		Visualizer^ _vis;
		Controller^ _cnt;
		DataManager^ _dmg;
	public:
		Observer(void);
		Observer(Controller^, Visualizer^, DataManager^);
		void Run();
		void SetCondition(Settings*);
		void Simulate();
		void SimulateWithSame(int);
		void SimulateWithDifferent(int);
		void Demonstrate();

	public:
		property bool Stop
		{
				bool get(){return this->stop;}
				void set(bool value){this->stop = value;}
		}
	};
}
