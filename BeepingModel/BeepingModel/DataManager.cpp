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


void DataManager::FirstRecord()
{

}

void DataManager::Record()
{

}

void DataManager::LoadController(Controller^ cnt)
{

}

/* 
 * Test OutPut
 */

String^ DataManager::OutPutJSON()
{
	object *graph = new object;
	graph->insert(make_pair("D", value((double)(2.55))));
	graph->insert(make_pair("Global_Round", value((double)(5.55))));
	graph->insert(make_pair("Radius", value((double)(50))));
	graph->insert(make_pair("F", value((double)(15))));
	graph->insert(make_pair("Delta", value((double)(10))));
	obj->insert(make_pair("N", value((double)(100))));
	obj->insert(make_pair("M", value((double)(200))));
	obj->insert(make_pair("GraphInformation", value(*graph)));

	return gcnew String(value(*obj).serialize().c_str());
}

String^ DataManager::OutPutJSONrefController()
{
	object *graph = WriteGraphInfo();
	array nodes = WriteNodeInfo();
	object *channels = WriteChannelInfo();

	obj->insert(make_pair("GraphInformation", value(*graph)));
	obj->insert(make_pair("Nodes", value(nodes)));
	return gcnew String(value(*obj).serialize().c_str());

	delete graph;
	delete &nodes;
	delete channels;
}

object* DataManager::WriteGraphInfo()
{
	object* _graph = new object;
	
	std::string topology;
	if (this->cnt->graph_topology == 0)
	{
		topology = "Random";
	}
	else if (this->cnt->graph_topology == 1)
	{
		topology = "UnitDisk";
	}

	picojson::array fieldsize;
	fieldsize.push_back(value((double)this->cnt->x));
	fieldsize.push_back(value((double)this->cnt->y));

	_graph->insert(make_pair("Field_Size", value(fieldsize)));
	_graph->insert(make_pair("Topology", value(topology)));
	//_graph->insert(make_pair("D", value((double)())));
	//_graph->insert(make_pair("Delta", value((double)(10))));
	_graph->insert(make_pair("Global_Round", value((double)(this->cnt->GlobalRound))));
	_graph->insert(make_pair("Radius", value((double)(this->cnt->unitdisk_r))));
	_graph->insert(make_pair("F", value((double)(this->cnt->F))));

	return _graph;
}

array DataManager::WriteNodeInfo()
{
	object* _nodes = new object;
	picojson::array _narr;
	for each (Node^ _n in this->cnt->nodes)
	{
		std::string _state;
		switch (_n->NodeState){
		case inactive:
			_state = "inactive";
			break;
		case competing:
			_state = "competing";
			break;
		case MIS:
			_state = "MIS";
			break;
		case sleep:
			_state = "sleep";
			break;
		default:
			break;
		}
		
		cli::array<int>^ _posOfCliArray = _n->GetPosition();
		picojson::object* _position = new object;
		_position->insert(make_pair("x", value((double)_posOfCliArray[0])));
		_position->insert(make_pair("y", value((double)_posOfCliArray[1])));

		object* _node = new object;
		object* _nodeSet = new object;
		_node->insert(make_pair("Round", value((double)_n->local_round)));
		_node->insert(make_pair("State", value(_state)));
		_node->insert(make_pair("Position", value(*_position)));
		char _id[10] = { 0 };
		sprintf_s(_id, 10, "%d", _n->Id);
		_nodeSet->insert(make_pair(_id,value(*_node)));
		_narr.push_back(value(*_nodeSet));
	}
	return _narr;
}

object* DataManager::WriteChannelInfo()
{
	object* _channels = new object;

	return _channels;
}