#include "StdAfx.h"


using namespace BeepingModel;
Node::Node(void)
{
	this->id = 12345;
	this->ch_num = 0;
	this->states = gcnew array<int>{listen,inactive,silent};
	this->channels = gcnew array<Channel^>(M_SIZE);
}
Node::Node(int id)
{
	this->id = id;
	this->ch_num = 1;
	this->states = gcnew array<int>{listen,inactive,silent};
	this->channels = gcnew array<Channel^>(M_SIZE);
}
Node::Node(int id,Channel^ ch)
{
	this->id = id;
	this->channels[ch_num++] = ch;
}

array<int>^ Node::GetState(void){
	return this->states;
}