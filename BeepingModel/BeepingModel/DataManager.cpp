#include "stdafx.h"

using namespace BeepingModel;
using namespace picojson;
using namespace std;
DataManager::DataManager()
{
	this->obj = new object;
}


DataManager::DataManager(Controller^ cnt)
{
	this->obj = new object;
	this->cnt = cnt;
}


DataManager::~DataManager()
{
	delete this->obj;
}

String^ DataManager::OutPutJSON()
{
	object *graph = new object;
	graph->insert(make_pair("D", value(Convert::ToDouble(2.55))));
	graph->insert(make_pair("Global_Round", value(Convert::ToDouble(5.55))));
	graph->insert(make_pair("Radius", value(Convert::ToDouble(50))));
	graph->insert(make_pair("F", value(Convert::ToDouble(15))));
	graph->insert(make_pair("Delta", value(Convert::ToDouble(10))));
	obj->insert(make_pair("N", value(Convert::ToDouble(100))));
	obj->insert(make_pair("M", value(Convert::ToDouble(200))));
	obj->insert(make_pair("GraphInformation", value(*graph)));

	return gcnew String(value(*obj).serialize().c_str());
}

String^ DataManager::OutPutJSONrefController()
{
	object *graph = new object;
	graph->insert(make_pair("D", value(Convert::ToDouble(2.55))));
	graph->insert(make_pair("Global_Round", value(Convert::ToDouble(5.55))));
	graph->insert(make_pair("Radius", value(Convert::ToDouble(50))));
	graph->insert(make_pair("F", value(Convert::ToDouble(15))));
	graph->insert(make_pair("Delta", value(Convert::ToDouble(10))));
	obj->insert(make_pair("N", value(Convert::ToDouble(100))));
	obj->insert(make_pair("M", value(Convert::ToDouble(200))));
	obj->insert(make_pair("GraphInformation", value(*graph)));

	return gcnew String(value(*obj).serialize().c_str());
}

void DataManager::FirstRecord()
{

}

void DataManager::Record()
{

}