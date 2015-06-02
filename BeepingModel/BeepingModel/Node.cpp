#include "StdAfx.h"


using namespace BeepingModel;
Node::Node(void)
{
	this->id = -1;
	this->local_round = 1;
	this->states = gcnew array<int>{sleep,sleep,silent};
}

Node::Node(int id, int F)
{
	Reset();
	this->id = id;
	this->current_step = 1;
	this->state = "Lonely";
	this->candidate = NULL;
	this->neighbors.clear();
	this->channels.clear();
	this->local_round = 1;
	this->states = gcnew array<int>{sleep,sleep,silent};
	this->MIS_state = 0;
	this->udk_r = UDK_R;
	//Multi-Channel Mode
	this->global_freq = F;
	this->available_freq = gcnew array<int>(F){ 1 };
}

void Node::SetNeighbor(int id)
{
	this->neighbors.push_back(id);
}

void Node::SetChannel(int ch_id)
{
	this->channels.push_back(id);
}

array<int>^ Node::GetState(void)
{
	return this->states;
}

void Node::SetPosition(array<int>^ p)
{
	this->position = p;
}

array<int>^ Node::GetPosition(void)
{
	return this->position;
}

void Node::Reset(void)
{
	this->listenround = 1;
	this->phase = 1;
	this->step = 1;
}
