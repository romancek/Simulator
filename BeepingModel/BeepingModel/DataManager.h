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
		void FirstRecord(void);
		void Record(void);
		void LoadController(Controller^);
		System::String^ OutPutJSON(void);
		System::String^ OutPutJSONrefController(void);
		picojson::object* WriteGraphInfo();
		picojson::array WriteNodeInfo();
		picojson::object* WriteChannelInfo();

	};
}

