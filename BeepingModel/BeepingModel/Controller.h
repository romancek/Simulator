#pragma once
#include "Node.h"
#include "Channel.h"
#include "StdAfx.h"

namespace BeepingModel{
	using namespace System;
	ref class Controller
	{
	private:
		int n;		//network size
		int m;	//channel size
		int density;
		int x,y;
		int graph_topology;
		bool updated;
		int global_round;
		int UpperN;
		int c;
	public:
		array<Node^>^ nodes;
		array<Channel^>^ channels;
	public:
		Controller(int,int);
		void InitializeGraph(int);
		void InitializeGraph(int,int,int,int);
		void CreateGraph();
		void CreateRandomGraph(void);
		void CreateUnitDiskGraph(void);
		void SetRandomizedPosition(void);		//Random graph only
		void SetGraphParameter(Settings*);
		void Run(void);
		void Run_UpperN(void);

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
		property int GlobalRound {
				int get(){return this->global_round;}
				void set(int value){this->global_round = value;}
		}
	};
}