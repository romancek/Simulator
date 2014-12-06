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
		bool updated;
		int global_round;
		int UpperN;
		int c;
	public:
		array<Node^>^ nodes;
		array<Channel^>^ channels;
	public:
		Controller(void);
		void InitializeGraph(void);
		void InitializeGraph(int,int,int);
		void CreateGraph(String^);
		void CreateRandomGraph(void);
		void CreateUnitDiskGraph(void);
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
		//Network‚ª•ÏX‚³‚ê‚½‚çtrue
		property bool Updated {
				bool get(){return this->updated;}
				void set(bool updated){this->updated = updated;}
		}
		property int GlobalRound {
				int get(){return this->global_round;}
				void set(int value){this->global_round = value;}
		}
	};
}