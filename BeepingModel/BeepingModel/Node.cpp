#include "StdAfx.h"


using namespace BeepingModel;
Node::Node(void)
{
	this->id = -1;
	this->local_round = 1;
	this->states = gcnew array<int>{sleep,sleep,silent};
	this->current_ch = 0;
}

Node::Node(int id, int F, unsigned int alg_type)
{
	Reset();
	this->id = id;
	this->position = nullptr;
	this->current_step = 1;
	this->state = "Executing";
	this->candidate = -1;
	this->neighbors.clear();
	this->channels.clear();
	this->local_round = 1;
	this->MIS_state = 0;
	this->udk_r = UDK_R;
	//Multi-Channel Mode
	this->global_freq = F;
	this->available_freq = gcnew array<bool>(F);
	for (int f = 0; f < F; f++)this->available_freq[f] = true;

	this->current_ch = -1;
	this->match_ch = -1;
	this->slot = nullptr;
	this->succ_pattern = false;
	//Using for DFS
	this->marked = -1;
	//use different states for each algorithm
	unsigned int act, node, lsn;
	switch (alg_type){
	case 0: //MIS
		act = sleep, node = sleep, lsn = silent;
		break;
	case 1: //MM
		act = sleep, node = Lonely, lsn = silent;
		break;
	case 2: //LE
		act = sleep, node = sleep, lsn = silent;
		break;
	default:
		act = sleep, node = sleep, lsn = silent;
		break;
	}
	this->states = gcnew array<int>{act,node,lsn};
}

void Node::BEEP(int ch_num)
{
	this->states[0] = beeping;
	this->current_ch = ch_num;

}

void Node::LISTEN(int ch_num)
{
	this->states[0] = listen;
	this->current_ch = ch_num;
}

void Node::WAIT()
{
	this->states[0] = listen;
	this->current_ch = -1;
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

void Node::Reset()
{
	this->listenround = 1;
	this->phase = 1;
	this->step = 1;
}

void Node::Reset(int F,unsigned int alg_type)
{
	this->listenround = 1;
	this->phase = 1;
	this->step = 1;

	this->current_step = 1;
	this->state = "Executing";
	this->candidate = -1;
	this->local_round = 1;
	this->MIS_state = 0;
	//Multi-Channel Mode
	this->global_freq = F;
	for (int f = 0; f < this->global_freq; f++)this->available_freq[f] = true;

	this->current_ch = -1;
	this->match_ch = -1;
	this->slot = nullptr;
	this->succ_pattern = false;
	this->marked = -1;
	//use different states for each algorithm
	unsigned int act, node, lsn;
	switch (alg_type){
	case 0: //MIS
		act = sleep, node = sleep, lsn = silent;
		break;
	case 1: //MM
		act = sleep, node = Lonely, lsn = silent;
		break;
	case 2: //LE
		act = sleep, node = sleep, lsn = silent;
		break;
	default:
		act = sleep, node = sleep, lsn = silent;
		break;
	}
	this->states = gcnew array<int>{act, node, lsn};
}
