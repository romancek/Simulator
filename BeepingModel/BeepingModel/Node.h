#pragma once
#include "StdAfx.h"
namespace BeepingModel{
	using namespace System;
	ref class Node
	{
	private:
		int id;
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
