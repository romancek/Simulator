#pragma once
#include "StdAfx.h"
#include "Channel.h"
#include <vector>

namespace BeepingModel{
	using namespace System;
	using namespace std;
	ref class Node
	{
	private:
		int id;
		int ch_num;
		array<int>^ states;
	public:
		Node();
		Node(int);
		array<int>^ GetState(void);
	public:
		property int Id {
			int get() { return this->id; }
			void set( int value ) { this->id = value; }
		}
	};
}
