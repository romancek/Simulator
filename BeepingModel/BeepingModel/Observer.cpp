#include "stdafx.h"
using namespace BeepingModel;
Observer::Observer(void)
{
	this->stop = true;
	this->drawing = true;
}

Observer::Observer(Controller^ controller, Visualizer^ visualizer, DataManager^ datamanager)
{
	this->stop = true;
	this->drawing = true;
	this->_cnt = controller;
	this->_vis = visualizer;
	this->_dmg = datamanager;
}

void Observer::SetCondition(Settings* settings)
{
	this->drawing = settings->Drawing;
	this->exec_times = settings->execution_times;
	this->exec_start = settings->execution_condition[0];
	this->exec_end = settings->execution_condition[1];
	this->exec_interval = settings->execution_condition[2];
	this->same_topology = settings->isSameTopology;
	this->algorithm_type = settings->algorithm_type;
}

void Observer::Run()
{
	while (true)
	{
		this->_cnt->Run();
		TimeWatch t;
		if ( this->drawing ) this->_vis->Draw();
		System::Diagnostics::Debug::WriteLine(String::Format("{0}ms/round", t.elapsed()));
		if ( this->stop )break;
		if (_cnt->DetectTerminate())break;
		//Thread::Sleep(_Run_Speed_ms);
	}
	this->_vis->Draw();
	this->stop = false;
}

void Observer::Simulate()
{
	this->drawing = false;
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
			if (_cnt->DetectTerminate())break;
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
			if (_cnt->DetectTerminate())break;
		}
		delete this->_dmg;
		this->_dmg = gcnew DataManager(this->_cnt);
		String^ path = String::Format("{0}/different_{1}.json", dir, count);
		StreamWriter^ writer = gcnew StreamWriter(path, false, System::Text::Encoding::GetEncoding("UTF-8"));
		writer->WriteLine(this->_dmg->OutPutJSONrefController());
		writer->Close();
	}
}

void Observer::Demonstrate()
{
	this->stop = false;
	while (!this->stop)
	{
		if (this->stop)break;
		if (!this->same_topology)
		{
			this->_cnt->InitializeGraph(this->_cnt->N, MAXIMUM_CHANNEL, this->_cnt->Density);
		}
		else
		{
			this->_cnt->Initialize();
		}
		this->_vis->Draw();
		while (true)
		{
			if (this->stop)break;
			if (this->drawing) this->_vis->Draw();
			this->_cnt->Run();
			if (_cnt->DetectTerminate())break;
		}
		this->_vis->Draw();
		Thread::Sleep(_DrawTerminateState_Interval_ms);
		if(this->algorithm_type == 1 /* MM */ )
		{
			this->_vis->DrawOnlyMatchedPair();
			Thread::Sleep(_DrawTerminateState_Interval_ms * 3 / 2);
		}
	}
}
