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

void Observer::SetCondition(Settings* settings)
{
	this->_can_draw = settings->Can_Draw;
	this->exec_times = settings->execution_times;
	this->exec_start = settings->execution_condition[0];
	this->exec_end = settings->execution_condition[1];
	this->exec_interval = settings->execution_condition[2];
	this->same_topology = settings->isSameTopology;
}

void Observer::Run()
{
	while (true)
	{
		this->_cnt->Run();
		TimeWatch t;
		if ( _can_draw ) this->_vis->Draw();
		System::Diagnostics::Debug::WriteLine(String::Format("{0}ms/round", t.elapsed()));
		if ( this->stop )break;
		if (DetectTerminate())break;
		//Thread::Sleep(_Run_Speed_ms);
	}
	this->_vis->Draw();
}

bool Observer::DetectTerminate()
{
	if (isFinished())
	{
		if (!isValid())
		{
			System::Diagnostics::Debug::Fail("Unsatisfy matching");
		}
		else
		{
			return true;
		}
	}
	return false;
}

bool Observer::isFinished()
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

bool Observer::isValid()
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
	for (unsigned int i = exec_start; i <= exec_end; i += exec_interval)
	{
		if (this->same_topology)
		{
			SimulateWithSame(i);
		}
		else
		{
			SimulateWithDifferent(i);
		}
	}
}

void Observer::SimulateWithSame(int n)
{
	String^ dir = String::Format("n={0}",n);
	Directory::CreateDirectory(dir);
	this->_cnt->InitializeGraph(n, MAXIMUM_CHANNEL, 1);
	/* Simulate in Same Graph */
	for (unsigned int count = 0; count < exec_times; count++)
	{
		while (true)
		{
			this->_cnt->Run();
			if (DetectTerminate())break;
		}
		delete this->_dmg;
		this->_dmg = gcnew DataManager(this->_cnt);
		String^ path = String::Format("{0}/same_{1}.json", dir, count);
		StreamWriter^ writer = gcnew StreamWriter(path, false, System::Text::Encoding::GetEncoding("UTF-8"));
		writer->WriteLine(this->_dmg->OutPutJSONrefController());
		writer->Close();
		this->_cnt->Initialize();
	}
}

void Observer::SimulateWithDifferent(int n)
{
	String^ dir = String::Format("n={0}", n);
	Directory::CreateDirectory(dir);
	/* Simulate in Different Graph but n is uniform*/
	for (unsigned int count = 0; count < exec_times; count++)
	{
		this->_cnt->InitializeGraph(n, MAXIMUM_CHANNEL, 1);
		while (true)
		{
			this->_cnt->Run();
			if (DetectTerminate())break;
		}
		delete this->_dmg;
		this->_dmg = gcnew DataManager(this->_cnt);
		String^ path = String::Format("{0}/different_{1}.json", dir, count);
		StreamWriter^ writer = gcnew StreamWriter(path, false, System::Text::Encoding::GetEncoding("UTF-8"));
		writer->WriteLine(this->_dmg->OutPutJSONrefController());
		writer->Close();
	}
}