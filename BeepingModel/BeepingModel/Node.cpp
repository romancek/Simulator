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
	this->ch_num = 0;
	this->states = gcnew array<int>{listen,inactive,silent};
}

void Node::SetNeighbor(int id)
{
	this->neighbors.push_back(id);
	this->ch_num++;
}

array<int>^ Node::GetState(void){
	return this->states;
}