#pragma once
#include "stdafx.h"

namespace BeepingModel{
	using namespace System;
	ref class Controller
	{
	private:
		int n;		//network size
		int m;	//channel size
		double density;
		int global_round;
		unsigned int NODE_SIZE;
	public:
		int unitdisk_r;
		int graph_topology;
		bool updated;
		int UpperN;
		int c;
		int F;	//available number of channels
	public:
		int x,y;
		int channel_num;
		int diameter;
		int delta;
		cli::array<Node^>^ nodes;
		cli::array<Channel^>^ channels;
	public:
		Controller(int,int);
		void InitializeGraph(int);		//remake graph
		void InitializeGraph(int,int,double);
		void Initialize(void);			//init node's & channel's value
		void ChangeGraph(void);
		void ResizeField(int,int);
		void CreateGraph();
		void CreateRandomGraph(void);	//Random graph only
		void CreateUnitDiskGraph(void);	//UnitDisk graph only
		void CreateRandomEdge(void);
		void SetRandomizedPosition(void);
		void SetUnitDiskEdge(void);
		double GetNodeDistance(int,int,int,int);
		void SetGraphParameter(Settings*);
		unsigned int Random_Device(void);
		void ComputeAttribute(void);
		void RefleshFrequency(void);
		void Run(void);
		void Run_UpperN(void);
		void Run_MM(void);

		property int N {
				int get(){return this->n;}
				void set(int n){this->n = n;}
		}
		property int M {
				int get(){return this->m;}
				void set(int m){this->m = m;}
		}
		property double Density {
				double get(){return this->density;}
				void set(double density){this->density = density;}
		}
		property int GlobalRound {
				int get(){return this->global_round;}
				void set(int value){this->global_round = value;}
		}
	};
}