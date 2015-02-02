#pragma once
#include "StdAfx.h"
namespace BeepingModel{
	ref class TimeWatch
	{
	private:
		double m_start;
	public:
		TimeWatch(void);
		void restart();
		double elapsed(void);
	};
}
