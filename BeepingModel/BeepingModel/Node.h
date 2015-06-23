#pragma once
#include "StdAfx.h"

namespace BeepingModel{
	using namespace System;
	ref class Node
	{
	private:
		int id;
	public:
		cli::array<int>^ states;
		cli::array<int>^ position;
		String^ state;
		int current_step;				// 0 : terminated
		int local_round;
		int listenround;
		int phase;						// i : 1 to clogN
		int step;						// 1 to logN
		int MIS_state;					// 0:if,1:listen,2:else,3:beep
		int udk_r;						// UnitDisk radius
		int candidate;					// matching candidate channel number
	public:
		int global_freq;						// 1~F channels
		cli::array<bool>^ available_freq;		// 1:available, 0:not available	
		cliext::vector<int> neighbors;			// neighbor ids
		cliext::vector<unsigned int> channels;	// connected ch ids
		int current_ch;
		int match_ch;
		cli::array<unsigned __int8>^ slot;		// 3 slot in step 2
		bool succ_pattern;
		unsigned int transit_state;
	public:
		Node();
		Node(int,int);
		void SetNeighbor(int);
		void SetChannel(int);
		cli::array<int>^ GetState(void);
		void BEEP(int);					//-1 : not select
		void LISTEN(int);
		void WAIT();
		void SetPosition(cli::array<int>^);
		cli::array<int>^ GetPosition(void);

		void Reset(void);
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
			int get() { return this->local_round; }
			void set( int value ) { this->local_round = value; }
		}
		property int ListenRound {
			int get() { return this->listenround; }
			void set( int value ) { this->listenround = value; }
		}
		property int Phase {
			int get() { return this->phase; }
			void set( int value ) { this->phase = value; }
		}
		property int Step {
			int get() { return this->step; }
			void set( int value ) { this->step = value; }
		}
		property int next_MIS_state {
			int get() { return this->MIS_state; }
			void set( int value ) { this->MIS_state = value; }
		}
	};
}
