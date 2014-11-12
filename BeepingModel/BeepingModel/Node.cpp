#include "StdAfx.h"


using namespace BeepingModel;
Node::Node(void)
{
	this->id = -1;
	this->ch_num = 0;
	this->states = gcnew array<int>{listen,inactive,silent};
}

Node::Node(int id)
{
	this->id = id;
	this->ch_num = 1;
	this->states = gcnew array<int>{listen,inactive,silent};
}

array<int>^ Node::GetState(void){
	return this->states;
}