#include "StdAfx.h"
#include "TimeWatch.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <MMSystem.h>
#pragma comment( lib, "winmm.lib" )

using namespace BeepingModel;
TimeWatch::TimeWatch(void)
{
	this->restart();
}

void TimeWatch::restart()
{
	m_start = timeGetTime();
}

double TimeWatch::elapsed()
{
	double end = timeGetTime();
	return (double)(end - m_start) / 1000;	//ms->s
}