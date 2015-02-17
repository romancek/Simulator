#pragma once
#include "stdafx.h"

namespace BeepingModel{
	ref class DataManager
	{
	private:
		picojson::object *obj;
	public:
		Controller^ cnt;
	public:
		DataManager(void);
		DataManager(Controller^);
		~DataManager(void);
		System::String^ OutPutJSON(void);
		System::String^ OutPutJSONrefController(void);
		void FirstRecord(void);
		void Record(void);
	};
}

