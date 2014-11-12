#include "StdAfx.h"
#include "Form1.h" //boost�g���Ƃ��ɕK�v?
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
	this->graph_topology = "random";
#ifdef _DEBUG
	hellekalek1995 gen( 100 );
	bernoulli_distribution<> dst( 0.5 );
	variate_generator< hellekalek1995&, bernoulli_distribution<> > rand( gen, dst );
	int count = 0;
	for( int i=0; i<100000; ++i ){
		if( rand() == 1 )count++;
	}
	Debug::WriteLine(count);
#endif
}

void Controller::InitializeGraph(void)
{
	//����������
	nodes = gcnew array<Node^>(n);
	channels = gcnew array<Channel^>(m);
	for(int i = 0;i < n;i++){
		nodes[i] = gcnew Node(i);
		channels[i] = gcnew Channel(i);
	}
#ifdef _DEBUG
	for each( Node^ n in nodes){
		Debug::WriteLine(n->Id);
	}
	this->CreateRandomGraph();
#endif
}

void Controller::CreateGraph(String^ topology)
{
	this->graph_topology = topology;
	if(graph_topology == "random"){
		this->CreateRandomGraph();
	}
}

//multiset��val1��val2�̃y�A���܂܂�Ă�����false��Ԃ�
template <typename C, class T1, class T2> bool findit(const C& c, T1 val1, T2 val2) {
    auto result1 = c.find(val1);
	auto result2 = c.find(val2);
	std::multimap<int,int>::iterator it;
    if (result1 ==  c.end() && result2 == c.end()) {
       return true;
    } else{
		if(result1 != c.end() && result2 == c.end()){
			for(it = c.lower_bound(val1);it != c.upper_bound(val1); it++){
				if((*it).second == val2)return false;
			}
		} else if(result1 == c.end() && result2 != c.end()){
			for(it = c.lower_bound(val2);it != c.upper_bound(val2); it++){
				if((*it).second == val1)return false;
			}
		}
		return true;
	}
}
void Controller::CreateRandomGraph(void)
{
	using namespace std;
	int i = 0;
	//M_SIZE edges random selected and add
	array<int>^ rand_edge = gcnew array<int>(2);
	multimap<int,int> created_edge;
	random::mt19937 gen;
	random::uniform_int_distribution<> dist(0,M_SIZE);
	while(i < M_SIZE){
		rand_edge[0] = dist(gen);
		rand_edge[1] = dist(gen);
		if(rand_edge[0] == rand_edge[1]) continue;
		//edges already selected
		if(true){//TODO
			channels[i]->EndPoint = rand_edge;
			created_edge.insert(pair <int, int> (rand_edge[0], rand_edge[1]));
#ifdef _DEBUG
			String^ a = String::Format("channel{0}:({1},{2})",i,rand_edge[0],rand_edge[1]);
			Debug::WriteLine(a);
#endif
			i++;
		}else{//edges not selected
			continue;
		}
	}
}

