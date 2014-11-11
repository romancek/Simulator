#include "StdAfx.h"


using namespace BeepingModel;
Node::Node(void)
{
	this->id = 12345;
	this->states = gcnew array<int>{listen,inactive,silent};
}

Node::Node(int id)
{
	this->id = id;
}

array<int>^ Node::GetState(void){
	return this->states;
}