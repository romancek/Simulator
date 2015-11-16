#include "stdafx.h"

using namespace BeepingModel;
using namespace System::Diagnostics;

Controller::Controller(int x, int y)
{
	this->nodes = nullptr;
	this->channels = nullptr;
	this->graph_topology = 0;
	this->UpperN = 1000;
	this->c = 3;
	this->global_round = 1;
	this->x = x;
	this->y = y;
	this->F = 1;
}

void Controller::InitializeGraph(int topology)
{
	//初期化処理
	this->graph_topology = topology;
	this->global_round = 1;
	nodes = gcnew array<Node^>(this->n);
	channels = gcnew array<Channel^>(this->m);
	for (int i = 0; i < n; i++)
	{
		nodes[i] = gcnew Node(i, this->F);
	}
	for (int i = 0; i < m; i++)
	{
		channels[i] = gcnew Channel(i);
	}
#ifdef _DEBUG
	for each (Node^ n in nodes)
	{
		Debug::WriteLine(n->Id);
	}
	this->CreateGraph();
#endif
}

void Controller::InitializeGraph(int n, int m, double density)
{
	this->n = n;
	this->m = m;
	this->density = density;
	this->global_round = 1;
	nodes = nullptr;
	channels = nullptr;
	nodes = gcnew array<Node^>(this->n);
	channels = gcnew array<Channel^>(this->m);
	for (int i = 0; i < n; i++)
	{
		nodes[i] = gcnew Node(i, this->F);
	}
	for (int i = 0; i < m; i++)
	{
		channels[i] = gcnew Channel(i);
	}
	this->CreateGraph();
	this->ComputeAttribute();
	int lowerF = 2 * (this->delta - 1) + 1;
	this->RefleshFrequency(this->F <  lowerF ? lowerF : this->F);
}

void Controller::Initialize()
{
	this->global_round = 1;
	for each (Node^ n in this->nodes)
	{
		n->Reset(this->F);
	}
	for each (Channel^ ch in this->channels)
	{
		ch->Reset();
	}
}

void Controller::ChangeGraph()
{
	this->CreateGraph();
	this->ComputeAttribute();
	int lowerF = 2 * (this->delta - 1) + 1;
	this->RefleshFrequency(this->F <  lowerF ? lowerF : this->F);
}

/*
* Compute Network Parameter etc. Diameter, Maximum Degree(Delta),
*/

void Controller::ComputeAttribute()
{
	int maxdegree = 0, diam = 0, _degree = 0;
	for each (Node^ n in this->nodes)
	{
		_degree = n->neighbors.size();
		if (_degree != 0 && _degree > maxdegree)
		{
			maxdegree = _degree;
		}
	}
	this->delta = maxdegree;
}

void Controller::RefleshFrequency(int ch_num)
{
	this->F = ch_num;
	for each(Node^ n in this->nodes)
	{
		n->global_freq = this->F;
		n->available_freq = gcnew array<bool>(this->F);
		for (int f = 0; f < this->F; f++)
		{
			n->available_freq[f] = true;
		}
	}
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
	if (!this->isConnected() && this->request_connectivity)
	{
		this->GuaranteeConnectivity();
	}
}

void Controller::CreateRandomEdge(void)
{
	using namespace std;
	int i = 0;
	bool selected = false;
	//M_SIZE edges random selected and add
	array<int>^ rand_edge = gcnew array<int>(2);
	multimap<int,int> created_edge;

	boost::random_device rd;
	boost::random::mt19937 gen( rd() );
	boost::random::uniform_int_distribution<> dist(0,this->n-1);
	boost::variate_generator< boost::mt19937&, boost::random::uniform_int_distribution<> > random(gen, dist);

	while ( i < this->m )
	{
		rand_edge[0] = random();
		rand_edge[1] = random();
		if ( rand_edge[0] == rand_edge[1] ) continue;
		//exists channel same endpoint node
		for ( auto cre : created_edge )
		{
			if ( (cre.first == rand_edge[0] && cre.second == rand_edge[1] )
				|| (cre.first == rand_edge[1] && cre.second == rand_edge[0]) )
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
			nodes[rand_edge[0]]->SetChannel(i);
			nodes[rand_edge[1]]->SetNeighbor(rand_edge[0]);
			nodes[rand_edge[1]]->SetChannel(i);
			int n1 = rand_edge[0];
			int n2 = rand_edge[1];
			created_edge.insert(pair<int, int>(n1, n2));//rand_edge[0], rand_edge[1]));
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

	boost::random_device rd;
	boost::random::mt19937 gen( rd() );
	boost::random::uniform_int_distribution<> distX(NODE_SIZE,this->x-1-NODE_SIZE);
	boost::random::uniform_int_distribution<> distY(NODE_SIZE,this->y-1-NODE_SIZE);
	
	while ( i < this->n )
	{
		dx = distX(gen);
		dy = distY(gen);

		for (auto exa : exist_area)
		{
			if (GetNodeDistance(dx + NODE_SIZE / 2, dy + NODE_SIZE / 2, exa.first + NODE_SIZE / 2, exa.second + NODE_SIZE / 2) < NODE_SIZE)
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
			for ( int nr = 0; nr < this->nodes[i]->neighbors.size(); nr++ )
			{
				if ( this->nodes[i]->neighbors.at(nr) == j ) selected = true;
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
					this->channels[channel_num]->SetEndPoint(i,j);
					this->nodes[i]->SetNeighbor(j);
					this->nodes[i]->SetChannel(channel_num);
					this->nodes[j]->SetNeighbor(i);
					this->nodes[j]->SetChannel(channel_num);
					channel_num++;
			}
		}
		i++;
	}
	//Init Balanced Channels
	for (int balanced_ch = channel_num; balanced_ch < this->m; balanced_ch++)
	{
		this->channels[balanced_ch]->SetEndPoint(-1, -1);
	}
	//this->m = channel_num;
}

void Controller::GuaranteeConnectivity()
{
	for (int count = 0; count < 100;count++)
	{
		// init graph structure
		nodes = nullptr;
		channels = nullptr;
		nodes = gcnew array<Node^>(this->n);
		channels = gcnew array<Channel^>(this->m);
		for (int i = 0; i < n; i++)
		{
			nodes[i] = gcnew Node(i, this->F);
		}
		for (int i = 0; i < m; i++)
		{
			channels[i] = gcnew Channel(i);
		}
		// repositioning 
		this->SetRandomizedPosition();
		this->SetUnitDiskEdge();
		if (this->isConnected())break;
	}
}

bool Controller::isConnected()
{
	this->component_num = this->Traversal();
	if (this->component_num > 1)return false;
	return true;
}

unsigned int Controller::Traversal()
{
	unsigned int component_number = 0;		//connected group number
	for (int id = 0; id < this->n;id++)
	{
		if (this->nodes[id]->marked != -1)
		{
			continue;
		}
		else
		{
			this->DFS(id,component_number++);
		}
	}
	return component_number;
}

void Controller::DFS(int source,int gnum)
{
	this->nodes[source]->marked = gnum;
	for each (int neighbor in this->nodes[source]->neighbors)
	{
		if (this->nodes[neighbor]->marked != -1)continue;
		this->DFS(neighbor,gnum);
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
	this->NODE_SIZE = setting->NODE_SIZE;
	this->request_connectivity = setting->Req_Connectivity;
}

/*
 * Random Value Create with random_device.exe using boost
 */
unsigned int Controller::Random_Device()
{
	ProcessStartInfo^ psi = gcnew ProcessStartInfo( "random_device.exe" );
	psi->WindowStyle = ProcessWindowStyle::Hidden;
	Process^ p = Process::Start(psi);
	p->WaitForExit();
	unsigned int rd = p->ExitCode;
	p->Close();
	return rd;
}

void Controller::Run(void)
{
	//this->Run_UpperN();
	this->Run_MM();
}
/*
 * Algorithm 1
 */
void Controller::Run_UpperN(void)
{
	using namespace System::Threading;
	//Adversal Wake-Up
	boost::random_device rd;
	boost::random::mt19937 gen( rd() );
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
			boost::hellekalek1995 gen( rd() );
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
			boost::hellekalek1995 gen( rd() );
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

/*
 * Experimental MM Algorithm
 */

void Controller::Run_MM()
{
	/*
	 * First Action
	 */
	for each ( Node^ n in this->nodes )
	{
		switch (n->current_step)
		{
		case -1:
			n->ActionState = listen;
			n->current_ch = -1;
			break;
		case 1:
			n->candidate = -1;
			if ( n->NodeState == Lonely )
			{
				/* Random Choice in available channel */
				std::vector<unsigned int> _ch;
				for (int f = 0; f < this->F;f++)
				{
					if ( n->available_freq[f] ) _ch.push_back(f);
				}
				boost::random_device rd;
				boost::random::mt19937 gen(rd());
				boost::random::uniform_int_distribution<> dist(0, _ch.size()-1);
				n->BEEP(_ch[dist(gen)]);
			}
			break;
		case 2:
			if ( n->candidate != -1 )
			{
				if (n->phase == 1)
				{
					n->succ_pattern = true;
					/* Detect Pattern for Correct Matching */
					boost::random_device rd;
					boost::hellekalek1995 gen(rd());
					boost::bernoulli_distribution<> dst(0.5);
					boost::variate_generator< boost::hellekalek1995&, boost::bernoulli_distribution<> > rand(gen, dst);
					if (rand() == 1){
						n->BEEP(n->candidate);
						n->transit_state = 0;
					}
					else
					{
						n->LISTEN(n->candidate);
						n->transit_state = 1;
					}
				}
				else if (n->phase == 2)
				{
					if (n->transit_state == 1)
					{
						n->BEEP(n->candidate);
					}
					else
					{
						n->LISTEN(n->candidate);
					}
					
				}
				else if (n->phase == 3)
				{
					if (n->succ_pattern)
					{
						n->LISTEN(n->candidate);
					}
					else
					{
						n->BEEP(n->candidate);
					}
				}
			}
			else
			{
				/* Wait for 3 round */
				n->WAIT();
			}
			break;
		case 3:
			if (n->phase == 1)
			{
				if (n->NodeState == Lonely) n->BEEP(this->F);
			}
			else
			{
				if (n->NodeState == MM && (n->phase - 2) == n->match_ch)
				{
					n->BEEP(n->phase - 2);
				}
				else
				{
					n->LISTEN(n->phase - 2);
				}
			}
			break;
		default :
			break;
		}
	}
	/*
	 * Second Action
	 */
	for each ( Node^ n in this->nodes )
	{
		switch ( n->current_step )
		{
		case -1:
			break;
		case 1:
			if (n->NodeState == Lonely)
			{
				bool _occur_colllision = false;
				for each(int id in n->neighbors)
				{
					if (this->nodes[id]->ActionState == beeping && n->current_ch == this->nodes[id]->current_ch)
					{
						_occur_colllision = true;
					}
				}
				if (_occur_colllision){
					n->candidate = n->current_ch;
				}
				else
				{
					n->candidate = -1;
				}
			}
			n->Round++;
			n->current_step = 2;
			n->phase = 1;
			break;
		case 2:
			if ( n->candidate != -1 )
			{
				if (n->phase == 1)
				{
					int _collision_num = 1; // sender side
					if (n->transit_state == 1)
					{
						_collision_num = 2; // receiver side
					}

					int _neighbors_beep_count = 0;
					for each(int id in n->neighbors)
					{
						if (this->nodes[id]->candidate == n->candidate 
							&& this->nodes[id]->ActionState == beeping)
						{
							
							_neighbors_beep_count++;
							
						}
					}
					if (_neighbors_beep_count >= _collision_num)n->succ_pattern = false;
				}
				else if (n->phase == 2)
				{
					int _collision_num = 1; // sender side
					if (n->transit_state == 0)
					{
						_collision_num = 2; // receiver side
					}

					int _neighbors_beep_count = 0;
					for each(int id in n->neighbors)
					{
						if (this->nodes[id]->candidate == n->candidate
							&& this->nodes[id]->ActionState == beeping)
						{
							_neighbors_beep_count++;
							
						}
					}
					if (_neighbors_beep_count >= _collision_num)n->succ_pattern = false;
				}
				else if (n->phase == 3)
				{
					if (n->succ_pattern)
					{
						int _neighbors_beep_count = 0;
						for each(int id in n->neighbors)
						{
							if (this->nodes[id]->candidate == n->candidate
								&& this->nodes[id]->ActionState == beeping)
							{
								_neighbors_beep_count++;

							}
						}
						/* Matching is Success */
						if (_neighbors_beep_count == 0)
						{
							n->match_ch = n->candidate;
							n->NodeState = MM;
						}
					}
				}
			}
			else
			{
				/* Wait for 3 round */
				
			}
			n->phase++;
			n->Round++;
			if (n->phase > 3)
			{
				n->current_step = 3;
				n->transit_state = 0;
				n->phase = 1;
			}
			break;
		case 3:
			if (n->phase == 1)
			{
				if (n->NodeState == Lonely)
				{
					bool _isTerminate = true;
					for each(int id in n->neighbors)
					{
						if (this->nodes[id]->ActionState == beeping && this->nodes[id]->current_ch == this->F)
						{
							 _isTerminate = false;
						}
					}
					if (_isTerminate)
					{
						n->candidate = -1;
						n->state = "Terminate";
						n->current_step = -1;
						break;
					}
				}
				else
				{
					/* Wait for 1 round */
				}
			}
			else
			{
				if (n->NodeState == Lonely)
				{
					for each(int id in n->neighbors)
					{
						if (this->nodes[id]->ActionState == beeping && (n->phase - 2) == this->nodes[id]->current_ch)
						{
							n->available_freq[n->phase - 2] = false;
						}
					}
				}
			}
			
			n->phase++;
			n->Round++;
			if ( n->phase > this->F+1 ) //phase 1~F+1
			{
				if ( n->NodeState == MM )
				{
					n->candidate = -1;
					n->state = "Terminate";
					n->current_step = -1;
					break;
				}
				n->phase = 1;
				n->current_step = 1;
			}
			break;
		default :
			break;
		}

	}
	this->global_round++;
}
