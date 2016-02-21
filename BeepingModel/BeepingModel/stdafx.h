// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���̃C���N���[�h �t�@�C���A�܂���
// �Q�Ɖ񐔂������A�����܂�ύX����Ȃ��A�v���W�F�N�g��p�̃C���N���[�h �t�@�C��
// ���L�q���܂��B
#pragma once

//Default Graph Property
#define N_SIZE 3
#define M_SIZE 3
#define F_SIZE 15
#define	_DENSITY 1.0	//�����ƔZ�x���Ⴂ
#define UDK_R 50		//UnitDisk radius
#define SIMULATE_COUNT 100
#define MAXIMUM_CHANNEL 100000


//Thread Speed Property
//#define _run_speed_ms 50 
//#define _mis_apper_stop_ms 500
//#define _checkinfo_speed_ms 200

#define _Run_Speed_ms 50 
#define _MIS_Apper_Stop_ms 5
#define _CheckInfo_Speed_ms 50
#define _DrawTerminateState_Interval_ms 5000

/*
 * Algorithm Property
 */
//action state
#define beeping 0
#define listen 1
//node state
#define inactive 2
#define competing 3
#define MIS 4
#define MM 4
#define sleep 8
#define Lonely 9	//not matching
//hearing state
#define beep 5
#define silent 6
#define collision 7

//Channel Property
#define CH_EMPTY -1000

typedef struct  {
public:
	//Graph Property
	unsigned int unitdisk_r;
	int topology;		//0:Random, 1:UnitDisk
	unsigned int F;		//[multicast] available number of channels
	bool Req_Connectivity;
	unsigned int Check_num;
	//Rendering Property
	bool AA;
	bool Drawing;		//graph draw
	unsigned int NODE_SIZE;
	float PEN_WIDTH;
	unsigned int Field_Size[2];
	//Simulation Property
	unsigned int execution_times;
	unsigned int execution_condition[3];	//0:start,1:end,2:interval
	bool isSameTopology;
	unsigned int algorithm_type;	//0:MIS_upperN,1:MM2:LeaderElection
}Settings;

typedef struct {
public:
	unsigned int N;
	unsigned int M;
	unsigned int Diameter;
	unsigned int Delta;
	unsigned int Global_Round;
	unsigned int F;
	unsigned int Radius;
	unsigned int Field_Size[2]; //0:Width,1:Height
}GraphInfo;


#include <boost/random.hpp>
#include <boost/random/random_device.hpp>

#include <iostream>
#include <ctime>
#include <map>
#include <math.h>
#include <string>
#include <cliext/vector>
#include "picojson.h"

//My Header
#include "Node.h"
#include "Channel.h"
#include "Controller.h"
#include "DataManager.h"
#include "Visualizer.h"
#include "Observer.h"
#include "FormSetting.h"

#include "Form1.h"
#include "Algorithm.h"
#include "TimeWatch.h"

