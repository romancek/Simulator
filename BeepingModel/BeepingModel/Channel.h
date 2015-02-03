#pragma once
#include "stdafx.h"

namespace BeepingModel{
	ref class Channel
	{
	private:
		int id;
		int state;	//0:silent,1:beep,<2:collision
		array<int>^ endpoint;
	public:
		Channel(void);
		Channel(int);
		void SetEndPoint(int,int);
	public:
		property int Id {
			int get() { return this->id; }
			void set( int value ) { this->id = value; }
		}
		property array<int>^ EndPoint {
			array<int>^ get(){return this->endpoint;}
			void set(array<int>^ ep){this->endpoint = ep;}
		}
		property int State {
			int get(){return this->state;}
			void set(int state){this->state = state;}
		}
	};
}
