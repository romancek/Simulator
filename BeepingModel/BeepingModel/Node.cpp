#include "StdAfx.h"


using namespace BeepingModel;
Node::Node(void)
{
	this->id = -1;
	this->ch_num = 0;
	this->local_round = 1;
	this->states = gcnew array<int>{listen,inactive,silent};
}

Node::Node(int id)
{
	this->id = id;
	this->ch_num = 0;
	this->local_round = 1;
	this->states = gcnew array<int>{listen,inactive,silent};
	this->listenround = 1;
	this->phase = 1;
	this->step = 1;
}

void Node::SetNeighbor(int id)
{
	this->neighbors.push_back(id);
	this->ch_num++;
}

array<int>^ Node::GetState(void)
{
	return this->states;
}

void Node::SetPosition(array<int>^ p)
{
	this->position = p;
#ifdef _DEBUG
	String^ a = String::Format("node:[{0}],[x,y]:[{1},{2}]",this->id,p[0],p[1]);
	System::Diagnostics::Debug::WriteLine(a);
#endif
}

array<int>^ Node::GetPosition(void)
{
	return this->position;
#ifdef _DEBUG
	String^ a = String::Format("GetPosition:[{0}],[x,y]:[{1},{2}]",this->id,this->position[0],this->position[1]);
	System::Diagnostics::Debug::WriteLine(a);
#endif
}

void Node::Reset(void)
{
	this->listenround = 1;
	this->phase = 1;
	this->step = 1;
}
