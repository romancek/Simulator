#pragma once
#include "StdAfx.h"
#include "Channel.h"

namespace BeepingModel{
	using namespace System;
	ref class Node
	{
	private:
		int id;
		int ch_num;
		array<Channel^>^ channels;
		array<int>^ states;
	public:
		Node();
		Node(int);
		Node(int,Channel^);
		array<int>^ GetState(void);
	public:
		property int Id {
			int get() { return this->id; }
			void set( int value ) { this->id = value; }
		}
	};
}
