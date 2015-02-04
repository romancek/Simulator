#include "stdafx.h"

using namespace BeepingModel;
using namespace System::Diagnostics;

Controller::Controller(int x, int y)
{
	this->n = N_SIZE;
	this->m = M_SIZE;
	this->density = _DENSITY;
	this->updated = true;
	this->graph_topology = 0;
	this->UpperN = 1000;
	this->c = 3;
	this->global_round = 1;
	this->x = x;
	this->y = y;
}

void Controller::InitializeGraph(int topology)
{
	//初期化処理
	this->graph_topology = topology;
	nodes = gcnew array<Node^>(this->n);
	channels = gcnew array<Channel^>(this->m);
	for ( int i = 0;i < n;i++ )
	{
		nodes[i] = gcnew Node(i);
	}
	for ( int i = 0;i < m;i++ )
	{
		channels[i] = gcnew Channel(i);
	}
#ifdef _DEBUG
	for each ( Node^ n in nodes )
	{
		Debug::WriteLine(n->Id);
	}
	this->CreateGraph();
#endif
}

void Controller::InitializeGraph(int n, int m, int density)
{
	this->n = n;
	this->m = m;
	this->density = density;
	this->updated = true;
	this->global_round = 1;
	nodes = nullptr;
	channels = nullptr;
	nodes = gcnew array<Node^>(this->n);
	channels = gcnew array<Channel^>(this->m);
	for ( int i = 0;i < n;i++ )
	{
		nodes[i] = gcnew Node(i);
	}
	for ( int i = 0;i < m;i++ )
	{
		channels[i] = gcnew Channel(i);
	}
	this->CreateGraph();
}

void Controller::ResizeField(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Controller::CreateGraph()
{
	if ( graph_topology == 0 /*Random*/ )
	{
		this->CreateRandomGraph();
	}
	else if ( graph_topology == 1 /*UnitDisk*/ )
	{
		this->CreateUnitDiskGraph();
	}
}

void Controller::CreateRandomGraph(void)
{
	this->CreateRandomEdge();
	this->SetRandomizedPosition();
}

void Controller::CreateUnitDiskGraph(void)
{
	this->SetRandomizedPosition();
	this->SetUnitDiskEdge();
}

void Controller::CreateRandomEdge(void)
{
	using namespace std;
	int i = 0;
	bool selected = false;
	//M_SIZE edges random selected and add
	array<int>^ rand_edge = gcnew array<int>(2);
	multimap<int,int> created_edge;

	/*
	 * Random Value Create with Boost
	 */
	ProcessStartInfo^ psi = gcnew ProcessStartInfo( "random_device.exe" );
	psi->WindowStyle = ProcessWindowStyle::Hidden;
	Process^ p = Process::Start(psi);
	p->WaitForExit();
	int rd = p->ExitCode;
	p->Close();
	Debug::WriteLine(String::Format("random_device = {0}",rd));
	boost::random::mt19937 gen(rd);
	boost::random::uniform_int_distribution<> dist(0,this->n-1);
	boost::variate_generator< boost::mt19937&, boost::random::uniform_int_distribution<> > random(gen, dist);

	while ( i < this->m )
	{
		rand_edge[0] = random();
		rand_edge[1] = random();
		if ( rand_edge[0] == rand_edge[1] ) continue;
		//exists channel same endpoint node
		for ( multimap<int,int>::iterator itr = created_edge.begin(); itr != created_edge.end(); ++itr )
		{
			if ( ((*itr).first == rand_edge[0] && (*itr).second == rand_edge[1] )
				|| ((*itr).first == rand_edge[1] && (*itr).second == rand_edge[0]) )
			{
				selected = true;
				break;
			}
			else
			{
				selected = false;
			}
		}
		//edges not selected
		if ( !selected ) //TODO
		{
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
		}
		else //edges already selected
		{
			continue;
		}
	}
}

void Controller::SetRandomizedPosition(void)
{
	using namespace std;
	int dx=0;
	int dy=0;
	int i = 0;
	bool selected = false;
	multimap<int,int> exist_area;

	boost::random::mt19937 gen( static_cast<unsigned long>(time(0)) );
	boost::random::uniform_int_distribution<> distX(NODE_SIZE,this->x-1-NODE_SIZE);
	boost::random::uniform_int_distribution<> distY(NODE_SIZE,this->y-1-NODE_SIZE);
	
	while ( i < this->n )
	{
		dx = distX(gen);
		dy = distY(gen);

		for ( multimap<int,int>::iterator itr = exist_area.begin(); itr != exist_area.end(); ++itr )
		{
			//重なり判定 TODO distance(p1,p2) <= NODE_SIZE*2
			if ( ((*itr).first + NODE_SIZE * this->density > dx && (*itr).first - NODE_SIZE * this->density < dx )
				&& ((*itr).second + NODE_SIZE * this->density > dy && (*itr).second - NODE_SIZE * this->density < dy) )
			{
				selected = true;
				break;
			}
			else
			{
				selected = false;
			}
		}
		//node not exists
		if ( !selected )
		{
			array<int>^ position = {dx,dy};
			this->nodes[i]->SetPosition(position);
			exist_area.insert(pair <int, int> (dx, dy));
			selected = false;
			i++;
		}
		else //node already exists
		{
			continue;
		}
	}
}

void Controller::SetUnitDiskEdge(void)
{
	using namespace std;
	int i = 0;
	channel_num = 0;
	bool selected = false;
	while( i < this->n )
	{	
		array<int>^ p1 = this->nodes[i]->GetPosition();
		for ( int j = 0;j < this->n;j++ )
		{
			if( j == i )continue;
			//チャネルが既に存在しているかチェック
			for ( int nr = 0; nr < this->nodes[i]->ch_num;nr++ )
			{
				if ( this->nodes[i]->neighbors[nr] == j ) selected = true;
			}
			if ( selected )
			{
				selected = false;
				continue;
			}
			array<int>^ p2 = this->nodes[j]->GetPosition();
			//距離unitdisk_r以内に配置
			if ( GetNodeDistance( p1[0]+NODE_SIZE/2, p1[1]+NODE_SIZE/2, p2[0]+NODE_SIZE/2, p2[1]+NODE_SIZE/2 ) < unitdisk_r )
			{
					this->channels[channel_num++]->SetEndPoint(i,j);
					this->nodes[i]->SetNeighbor(j);
					this->nodes[j]->SetNeighbor(i);
			}
		}
		i++;
	}
}

double Controller::GetNodeDistance(int p1x, int p1y, int p2x, int p2y)
{
	return sqrt(pow(fabs(double(p1x-p2x)),2)+pow(fabs(double(p1y-p2y)),2));
}

void Controller::SetGraphParameter(Settings* setting)
{
	this->graph_topology = setting->topology;
	this->unitdisk_r = setting->unitdisk_r;
	this->F = setting->F;
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
	using namespace System::Threading;
	//Adversal Wake-Up
	boost::random::mt19937 gen( static_cast<unsigned long>(time(0)) );	// or nondet_random.hpp->random_device
	boost::random::uniform_int_distribution<> dist(0,this->n-1);
	int i = 0;
	while(1)
	{
		if ( this->n < i )break;
		int rand_wake_id = dist(gen);
		if ( this->nodes[rand_wake_id]->NodeState == sleep )
		{
			this->nodes[rand_wake_id]->NodeState = inactive;
			break;
		}
		i++;
	}
	//First action
	for each ( Node^ n in this->nodes )
	{
		if ( n->NodeState == inactive ) //Algorithm 1
		{
			n->ActionState = listen;
		}
		else if ( n->NodeState == competing ) //Algorithm 3-6
		{ 
			boost::hellekalek1995 gen( static_cast<unsigned long>(time(0)) );
			double bp = Math::Pow(2.0,n->Phase)/(8*UpperN);
			boost::bernoulli_distribution<> dst( bp );
			boost::variate_generator< boost::hellekalek1995&, boost::bernoulli_distribution<> > rand( gen, dst );
			if ( rand() == 1 )
			{
				n->ActionState = beeping;
			}
			else
			{
				n->ActionState = listen;
			}
		}
		else if ( n->NodeState == MIS ) //Algorithm 7-8
		{
			boost::hellekalek1995 gen( static_cast<unsigned long>(time(0)) );
			boost::bernoulli_distribution<> dst( 0.5 );
			boost::variate_generator< boost::hellekalek1995&, boost::bernoulli_distribution<> > rand( gen, dst );
			if ( n->next_MIS_state == 0 )
			{
				if ( rand() == 1 )
				{
					n->ActionState = beeping;
					n->next_MIS_state = 1;
				}
				else
				{
					n->ActionState = listen;
					n->next_MIS_state = 3;
				}
			}
			else if ( n->next_MIS_state == 1 )
			{
				n->ActionState = listen;
				n->next_MIS_state = 0;
			}
			else if ( n->next_MIS_state == 3 )
			{
				n->ActionState = beeping;
				n->next_MIS_state = 0;
			}
		}
	}
	//Second action
	for each ( Node^ n in this->nodes )
	{
		bool hearbeep = false;
		if ( n->ActionState == listen )
		{
			for each ( int id in n->neighbors )
			{
				if ( this->nodes[id]->ActionState == beeping )
				{
					hearbeep = true;
					break;
				}
			}
		}
		if ( hearbeep )
		{
			n->NodeState = inactive;
			n->Reset();
			continue;
		}
		if ( n->NodeState == inactive) //Algorithm 1
		{ 
			n->ListenRound++;
			if ( c*Math::Pow(Math::Log(UpperN,2.0),2.0) < n->ListenRound )
			{
				n->NodeState = competing;
			}
		}
		else if ( n->NodeState == competing ) //Algorithm 3-6
		{
			if ( c * Math::Log(UpperN,2.0) < n->Step )
			{
				n->Phase++;
				n->Step = 0;
			}
			n->Step++;
			if ( Math::Log(UpperN,2.0) < n->Phase && c*Math::Log(UpperN,2.0) < n->Step )
			{
				n->NodeState = MIS;
#ifdef _DEBUG
				Debug::WriteLine(String::Format("*****************\n MIS Node appear, ID[{0}],Phase[{1}],Step[{2}] \n*****************",n->Id,n->Phase,n->Step));
#endif
				Thread::Sleep(_MIS_Apper_Stop_ms);
			}
		}
		if ( n->NodeState != sleep ) n->Round++;
	}
	this->global_round++;
}

void Controller::Run_MM()
{
	/*
	 * Send Action
	 */
	for each ( Node^ n in this->nodes )
	{
		
	}
	/*
	 * Receive Action
	 */
	for each ( Node^ n in this->nodes )
	{
		
	}
	this->global_round++;
}
