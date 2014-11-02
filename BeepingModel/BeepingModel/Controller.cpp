#include "StdAfx.h"
#include "Controller.h"
#include <iostream>
#include <boost/random.hpp>
#include <ctime>

using namespace BeepingModel;

Controller::Controller(void)
{
	boost::random::hellekalek1995 gen( 100 );
	boost::random::bernoulli_distribution<> dst( 0.8 );
	boost::random::variate_generator< hellekalek1995&, bernoulli_distribution<> > rand( gen, dst );
	int count = 0;
	for( int i=0; i<10; ++i ){
		if( rand() == 1 )count++;
	}
	System::Diagnostics::Debug::WriteLine(count);
}
