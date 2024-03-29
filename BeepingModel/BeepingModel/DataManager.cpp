#include "stdafx.h"

using namespace BeepingModel;
using namespace picojson;
using namespace std;

DataManager::DataManager()
{
	
}


DataManager::DataManager(Controller^ cnt)
{
	this->cnt = cnt;
}


DataManager::~DataManager()
{
	
}

String^ DataManager::OutPutJSONrefController()
{
	object *obj = new object;
	object *graph = WriteGraphInfo();
	array nodes = WriteNodeInfo();
	//array channels = WriteChannelInfo();

	obj->insert(make_pair("GraphInformation", value(*graph)));
	obj->insert(make_pair("Nodes", value(nodes)));
	//obj->insert(make_pair("Channels", value(channels)));

	delete graph;
	String^ output = gcnew String(value(*obj).serialize().c_str());
	delete obj;
	return output;
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
	//_graph->insert(make_pair("Diameter", value((double)())));
	_graph->insert(make_pair("Delta", value((double)(this->cnt->delta))));
	_graph->insert(make_pair("Global_Round", value((double)(this->cnt->GlobalRound))));
	_graph->insert(make_pair("Radius", value((double)(this->cnt->unitdisk_r))));
	_graph->insert(make_pair("F", value((double)(this->cnt->F))));
	_graph->insert(make_pair("M", value((double)(this->cnt->M))));
	_graph->insert(make_pair("N", value((double)(this->cnt->N))));

	return _graph;
}

array DataManager::WriteNodeInfo()
{
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
		case MM:
			_state = "MM";
			break;
		case Lonely:
			_state = "Lonely";
			break;
		default:
			break;
		}
		
		std::string _alg_state;
		if (_n->state == "Executing")
		{
			_alg_state = "Executing";
		}
		else if (_n->state == "Terminate")
		{
			_alg_state = "Terminate";
		}

		cli::array<int>^ _posOfCliArray = _n->GetPosition();
		picojson::object* _position = new object;
		_position->insert(make_pair("x", value((double)_posOfCliArray[0])));
		_position->insert(make_pair("y", value((double)_posOfCliArray[1])));

		object* _node = new object;
		picojson::array neighborsId;
		for each(int id in _n->neighbors) neighborsId.push_back(value((double)id));
		_node->insert(make_pair("Neighbor", value(neighborsId)));
		_node->insert(make_pair("Round", value((double)_n->local_round)));
		_node->insert(make_pair("Node State", value(_state)));
		_node->insert(make_pair("Algorithm State", value(_alg_state)));
		_node->insert(make_pair("Position", value(*_position)));
		_node->insert(make_pair("Id", value((double)_n->Id)));
		_node->insert(make_pair("Match Channel", value((double)_n->match_ch)));
		_narr.push_back(value(*_node));
	}
	return _narr;
}

array DataManager::WriteChannelInfo()
{
	picojson::array _carr;
	for each (Channel^ _c in this->cnt->channels)
	{
		std::string _state;
		switch (_c->State){
		case silent:
			_state = "silent";
			break;
		case beep:
			_state = "beep";
			break;
		case collision:
			_state = "collision";
			break;
		default:
			break;
		}

		cli::array<int>^ _posOfCliArray = _c->EndPoint;
		picojson::object* _endpoint = new object;
		_endpoint->insert(make_pair("ep1", value((double)_posOfCliArray[0])));
		_endpoint->insert(make_pair("ep2", value((double)_posOfCliArray[1])));

		object* _channel = new object;
		_channel->insert(make_pair("State", value(_state)));
		_channel->insert(make_pair("EndPoint", value(*_endpoint)));
		_channel->insert(make_pair("Id", value((double)_c->Id)));
		_carr.push_back(value(*_channel));
	}

	return _carr;
}