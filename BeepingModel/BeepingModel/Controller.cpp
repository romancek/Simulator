#include "StdAfx.h"
#include "Form1.h" //boost�g���Ƃ��ɕK�v?
#include <iostream>
#include <boost/random.hpp>
#include <ctime>


using namespace BeepingModel;
using namespace boost;
using namespace System::Diagnostics;
Controller::Controller(void)
{
	this->n = N_SIZE;
	hellekalek1995 gen( 100 );
	bernoulli_distribution<> dst( 0.5 );
	variate_generator< hellekalek1995&, bernoulli_distribution<> > rand( gen, dst );
	int count = 0;
	for( int i=0; i<100000; ++i ){
		if( rand() == 1 )count++;
	}
	Debug::WriteLine(count);
}

void Controller::InitializeGraph(void)
{
	//����������
	nodes = gcnew array<Node^>(n);
	for(int i = 0;i < n;i++){
		nodes[i] = gcnew Node(i);
	}
	for each( Node^ n in nodes){
		Debug::WriteLine(n->Id);
	}
}
