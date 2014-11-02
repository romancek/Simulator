#pragma once

namespace BeepingModel{
	using namespace System;
	
	ref class Node
	{
	private:
		int id;
	public:
		Node();
	public:
		property int Id {
			int get() { return this->id; }
			void set( int value ) { this->id = value; }
		}
	};
}
