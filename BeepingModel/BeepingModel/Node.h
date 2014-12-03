#pragma once
#include "StdAfx.h"
#include "Channel.h"
#include <cliext/vector>

namespace BeepingModel{
	using namespace System;
	ref class Node
	{
	private:
		int id;
		int ch_num;
		cliext::vector<int> neighbors;
		array<int>^ states;
		array<int>^ position;
		int round;
	public:
		Node();
		Node(int);
		void SetNeighbor(int);
		array<int>^ GetState(void);
		void SetPosition(array<int>^);
		array<int>^ GetPosition(void);
	public:
		property int Id {
			int get() { return this->id; }
			void set( int value ) { this->id = value; }
		}		
		property int ActionState {
			int get() { return this->states[0]; }
			void set( int value ) { this->states[0] = value; }
		}
		property int NodeState {
			int get() { return this->states[1]; }
			void set( int value ) { this->states[1] = value; }
		}
		property int ListenState {
			int get() { return this->states[2]; }
			void set( int value ) { this->states[2] = value; }
		}
		property int Round {
			int get() { return this->round; }
			void set( int value ) { this->round = value; }
		}
	};
}
