#include "StdAfx.h"
#include "Controller.h"
#include "Form1.h" //boostŽg‚¤‚Æ‚«‚É•K—v?
#include <iostream>
#include <boost/random.hpp>
#include <ctime>

using namespace BeepingModel;
using namespace boost;
using namespace System::Diagnostics;
Controller::Controller(void)
{
	hellekalek1995 gen( 100 );
	bernoulli_distribution<> dst( 0.5 );
	variate_generator< hellekalek1995&, bernoulli_distribution<> > rand( gen, dst );
	int count = 0;
	for( int i=0; i<100000; ++i ){
		if( rand() == 1 )count++;
	}
	Debug::WriteLine(count);
}
