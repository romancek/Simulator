#include "StdAfx.h"
#include "Form1.h" //boost使うときに必要?
#include <iostream>
#include <boost/random.hpp>
#include <ctime>
#include <map>
#include <math.h>

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
	this->UpperN = 1000;
	this->c = 3;
	this->global_round = 1;
}

void Controller::InitializeGraph(void)
{
	//初期化処理
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
	this->global_round = 1;
	//初期化処理
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

void Controller::Run(void)
{
	this->Run_UpperN();
}
/*
 * Algorithm 1
 */
void Controller::Run_UpperN(void)
{
	//First action
	for each(Node^ n in this->nodes)
	{
		if(n->NodeState == inactive){ //Algorithm 1
			n->ActionState = listen;
		}else if(n->NodeState == competing){ //Algorithm 3-6
			hellekalek1995 gen( static_cast<unsigned long>(time(0)) );
			double bp = Math::Pow(2.0,n->Phase)/(8*UpperN);
			bernoulli_distribution<> dst( bp );
			variate_generator< hellekalek1995&, bernoulli_distribution<> > rand( gen, dst );
			if( rand() == 1 ){
				n->ActionState = beeping;
			}else{
				n->ActionState = listen;
			}
		}else if(n->NodeState == MIS){ //Algorithm 7-8
			hellekalek1995 gen( static_cast<unsigned long>(time(0)) );
			bernoulli_distribution<> dst( 0.5 );
			variate_generator< hellekalek1995&, bernoulli_distribution<> > rand( gen, dst );
			if( rand() == 1 || n->ActionState == listen/*前回listenしてたら今回beep*/){
				n->ActionState = beeping;
			}else {
				n->ActionState = listen;
			}
		}
	}
	//Second action
	for each(Node^ n in this->nodes)
	{
		bool hearbeep = false;
		for each(int id in n->neighbors){
			if(this->nodes[id]->ActionState == beeping){
				hearbeep = true;
				break;
			}
		}
		if(hearbeep){
			n->NodeState = inactive;
			n->Reset();
			continue;
		}
		if(n->NodeState == inactive){ //Algorithm 1
			n->ListenRound++;
			if(c*Math::Pow(Math::Log(UpperN,2.0),2.0) < n->ListenRound){
				n->NodeState = competing;
			}
		}else if(n->NodeState == competing){ //Algorithm 3-6
			if(c * Math::Log(UpperN,2.0) < n->Step) n->Phase++;
			n->Step++;
			if(Math::Log(UpperN,2.0) < n->Phase && c*Math::Log(UpperN,2.0) < n->Step){
				n->NodeState = MIS;
#ifdef _DEBUG
				Debug::WriteLine(String::Format("*****************\n MIS Node appear, ID[{0}] \n*****************",n->Id));
#endif
			}
		}
		n->Round++;
	}
	this->global_round++;
}
