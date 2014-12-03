#include "StdAfx.h"
#include "Form1.h" //boostg‚¤‚Æ‚«‚É•K—v?
#include <iostream>
#include <boost/random.hpp>
#include <ctime>
#include <map>

using namespace BeepingModel;
using namespace boost;
using namespace System::Diagnostics;

Controller::Controller(void)
{
	this->n = N_SIZE;
	this->m = M_SIZE;
	this->density = _DENSITY;
	this->updated = true;
	this->graph_topology = "random";
}

void Controller::InitializeGraph(void)
{
	//‰Šú‰»ˆ—
	nodes = gcnew array<Node^>(this->n);
	channels = gcnew array<Channel^>(this->m);
	for(int i = 0;i < n;i++){
		nodes[i] = gcnew Node(i);
	}
	for(int i = 0;i < m;i++){
		channels[i] = gcnew Channel(i);
	}
#ifdef _DEBUG
	for each( Node^ n in nodes){
		Debug::WriteLine(n->Id);
	}
	this->CreateRandomGraph();
#endif
}

void Controller::InitializeGraph(int n, int m, int density)
{
	this->n = n;
	this->m = m;
	this->density = density;
	this->updated = true;
	//‰Šú‰»ˆ—
	nodes = nullptr;
	channels = nullptr;
	nodes = gcnew array<Node^>(this->n);
	channels = gcnew array<Channel^>(this->m);
	for(int i = 0;i < n;i++){
		nodes[i] = gcnew Node(i);
	}
	for(int i = 0;i < m;i++){
		channels[i] = gcnew Channel(i);
	}
	this->CreateRandomGraph();
}

void Controller::CreateGraph(String^ topology)
{
	this->graph_topology = topology;
	if(graph_topology == "random"){
		this->CreateRandomGraph();
	}
}

void Controller::CreateRandomGraph(void)
{
	using namespace std;
	int i = 0;
	bool selected = false;
	//M_SIZE edges random selected and add
	array<int>^ rand_edge = gcnew array<int>(2);
	multimap<int,int> created_edge;
	random::mt19937 gen( static_cast<unsigned long>(time(0)) );	// or nondet_random.hpp->random_device
	random::uniform_int_distribution<> dist(0,this->n-1);

	while(i < this->m){
		rand_edge[0] = dist(gen);
		rand_edge[1] = dist(gen);
		if(rand_edge[0] == rand_edge[1]) continue;
		//exists channel same endpoint node
		for(multimap<int,int>::iterator itr = created_edge.begin(); itr != created_edge.end(); ++itr){
			if( ((*itr).first == rand_edge[0] && (*itr).second == rand_edge[1] )
				|| ((*itr).first == rand_edge[1] && (*itr).second == rand_edge[0])){
					selected = true;
					break;
			} else {
				selected = false;
			}
		}
		//edges not selected
		if(!selected){//TODO
			channels[i]->SetEndPoint(rand_edge[0],rand_edge[1]);
			nodes[rand_edge[0]]->SetNeighbor(rand_edge[1]);
			nodes[rand_edge[1]]->SetNeighbor(rand_edge[0]);
			created_edge.insert(pair <int, int> (rand_edge[0], rand_edge[1]));
#ifdef _DEBUG
			String^ a = String::Format("channel[{0}]:({1},{2})",i,rand_edge[0],rand_edge[1]);
			Debug::WriteLine(a);
#endif
			selected = false;
			i++;
		}else{//edges already selected
			continue;
		}
	}
}

void Controller::Run_UpperN(void)
{
	
}
