#include "stdafx.h"

using namespace System;

DataManager::DataManager()
{
	this->obj = new picojson::object;
}


DataManager::~DataManager()
{
	delete this->obj;
}

void DataManager::OutPutJSON()
{
	obj->insert(std::make_pair("N", picojson::value(Convert::ToDouble(100))));
	System::Diagnostics::Debug::WriteLine(gcnew String(picojson::value(*obj).serialize().c_str()));
}