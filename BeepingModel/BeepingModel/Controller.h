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
		int density;
		String^ graph_topology;
	public:
		array<Node^>^ nodes;
		array<Channel^>^ channels;
	public:
		Controller(void);
		void InitializeGraph(void);
		void InitializeGraph(int,int,int);
		void CreateGraph(String^);
		void CreateRandomGraph(void);
		property int N {
				int get(){return this->n;}
				void set(int n){this->n = n;}
		}
		property int M {
				int get(){return this->m;}
				void set(int m){this->m = m;}
		}
		property int Density {
				int get(){return this->density;}
				void set(int density){this->density = density;}
		}
	};
}