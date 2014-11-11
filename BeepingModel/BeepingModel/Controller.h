#pragma once
#include "Node.h"
namespace BeepingModel{
	using namespace System;
	
	ref class Controller
	{
	private:
		int n;
		String^ graph_topology;
		array<Node^>^ nodes;
	public:
		Controller(void);
		void InitializeGraph(void);
	};
}