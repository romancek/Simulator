// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
#pragma once

//Default Graph Property
#define N_SIZE 3
#define M_SIZE 3
#define F_SIZE 15
#define	_DENSITY 2		//高いと濃度が低い
#define UDK_R 50		//UnitDisk radius

//Thread Speed Property
//#define _run_speed_ms 50 
//#define _mis_apper_stop_ms 500
//#define _checkinfo_speed_ms 200

#define _Run_Speed_ms 5 
#define _MIS_Apper_Stop_ms 5
#define _CheckInfo_Speed_ms 5

//Rendering Property
#define NODE_SIZE 5
#define PEN_WIDTH 0.1f

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
#define sleep 7
//hearing state
#define beep 5
#define silent 6

//Channel Property
#define CH_EMPTY -1000

// TODO: プログラムに必要な追加ヘッダーをここで参照してください。

typedef struct  {
public:
	bool AA;
	bool Can_Draw;	//graph draw
	unsigned int unitdisk_r;
	int topology;	//0:Random, 1:UnitDisk
	int F;				//[multicast] available number of channels
}Settings;

#include <boost/random.hpp>
#include <boost/random/random_device.hpp>

#include <iostream>
#include <ctime>
#include <map>
#include <math.h>
#include <string>
#include <cliext/vector>
#include "picojson.h"



#include "Node.h"
#include "Channel.h"
#include "Controller.h"
#include "Visualizer.h"
#include "Observer.h"
#include "FormSetting.h"
#include "Form1.h"
#include "TimeWatch.h"
