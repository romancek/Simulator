#pragma once
#include "stdafx.h"

namespace BeepingModel{
	ref class Channel
	{
	private:
		int id;
		int state;	//6:silent,5:beep,7:collision
		cli::array<int>^ endpoint;
	public:
		Channel(void);
		Channel(int);
		void SetEndPoint(int,int);
		void Reset(void);
	public:
		property int Id {
			int get() { return this->id; }
			void set( int value ) { this->id = value; }
		}
		property cli::array<int>^ EndPoint {
			cli::array<int>^ get(){return this->endpoint;}
			void set(cli::array<int>^ ep){this->endpoint = ep;}
		}
		property int State {
			int get(){return this->state;}
			void set(int state){this->state = state;}
		}
	};
}
