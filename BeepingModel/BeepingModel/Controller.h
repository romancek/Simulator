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
		int unitdisk_r;
		int graph_topology;
		bool updated;
		int global_round;
		int UpperN;
		int c;
		int F;	//available number of channels
	public:
		int x,y;
		int channel_num;
		array<Node^>^ nodes;
		array<Channel^>^ channels;
	public:
		Controller(int,int);
		void InitializeGraph(int);
		void InitializeGraph(int,int,int);
		void CreateGraph();
		void CreateRandomGraph(void);	//Random graph only
		void CreateUnitDiskGraph(void);	//UnitDisk graph only
		void CreateRandomEdge(void);
		void SetRandomizedPosition(void);
		void SetUnitDiskEdge(void);
		double GetNodeDistance(int,int,int,int);
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