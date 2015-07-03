#include "stdafx.h"
using namespace BeepingModel;
Observer::Observer(void)
{
	this->stop = true;
	this->_can_draw = true;
}

Observer::Observer(Controller^ controller, Visualizer^ visualizer, DataManager^ datamanager)
{
	this->stop = true;
	this->_can_draw = true;
	this->_cnt = controller;
	this->_vis = visualizer;
	this->_dmg = datamanager;
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

bool Observer::isFinishAlgorithm()
{
	for each(Node^ n in this->_cnt->nodes)
	{
		if (n->state == "Executing")return false;
	}
	return true;
}

/*
 *	Lonely and at least 1 neighbor is Lonely too -> BAD
 *	MM and at least 2 neighbor is same matching channel -> BAD
 */

bool Observer::CheckValid()
{
	for each(Node^ n in this->_cnt->nodes)
	{
		if (n->NodeState == Lonely)
		{
			for each(int id in n->neighbors)
			{
				if (this->_cnt->nodes[id]->NodeState == Lonely)return false;
			}
		}
		else if (n->NodeState == MM)
		{
			int _num_same_match_ch = 0;
			for each(int id in n->neighbors)
			{
				if (this->_cnt->nodes[id]->match_ch == n->match_ch)_num_same_match_ch++;
			}
			if (_num_same_match_ch > 1 || _num_same_match_ch == 0)return false;
		}
	}
	return true;
}

void Observer::Simulate()
{
	this->_can_draw = false;
	int n = this->_cnt->N;
	int m = n*(n-1)/2+1;
	for (int count = 0; count < SIMULATE_COUNT; count++)
	{
		this->_cnt->InitializeGraph(n, m, 1);
		this->_cnt->F = 2*(this->_cnt->delta - 1);
		this->_cnt->RefleshFrequency();
		while (!isFinishAlgorithm() && !CheckValid())
		{
			this->_cnt->Run();
		}
		System::DateTime moment = System::DateTime::Now;
		String^ path = String::Format("simulation_data_{0}{1:D2}{2:D2}{3:D2}{4:D2}{5:D2}.json", moment.Year, moment.Month, moment.Day, moment.Hour, moment.Minute, moment.Second);
		StreamWriter^ writer = gcnew StreamWriter(path, false, System::Text::Encoding::GetEncoding("UTF-8"));
		writer->WriteLine(this->_dmg->OutPutJSONrefController());
		writer->Close();
	}
}