#pragma once
#include "Node.h"
#include "Channel.h"

namespace BeepingModel{
	using namespace System;
	
	ref class Controller
	{
	private:
		int n;		//network size
		int m;	//channel size
		String^ graph_topology;
		array<Node^>^ nodes;
		array<Channel^>^ channels;
	public:
		Controller(void);
		void InitializeGraph(void);
		void CreateGraph(String^);
		void CreateRandomGraph(void);
	};
}