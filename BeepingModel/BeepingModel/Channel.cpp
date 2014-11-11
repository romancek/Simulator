#include "StdAfx.h"
#include "Channel.h"

using namespace BeepingModel;
Channel::Channel(void)
{
	this->id = -1;
	this->endpoint = gcnew array<int>(2);
}

Channel::Channel(int id)
{
	this->id = id;
	this->endpoint = gcnew array<int>(2);
}