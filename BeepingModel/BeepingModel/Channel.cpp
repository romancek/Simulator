#include "StdAfx.h"
#include "Channel.h"

using namespace BeepingModel;
Channel::Channel(void)
{

}

Channel::Channel(int id)
{
	this->id = id;
	this->endpoint = gcnew array<int>(2);
}