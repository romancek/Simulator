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
	this->endpoint = gcnew array<int>{-1,-1};
}

void Channel::SetEndPoint(int v1, int v2)
{
	array<int>^ ep = gcnew array<int>{v1,v2};
	this->endpoint = ep;
}