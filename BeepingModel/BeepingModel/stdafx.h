// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
#pragma once
#include <map>
#include <ctime>
#include <boost/random.hpp>
#include <iostream>
#include <ctime>
#include <map>
#include <math.h>
#include <string>
#include <boost/version.hpp>
#include <cliext/vector>
#include "picojson.h"

#define N_SIZE 3
#define M_SIZE 3

#define UDK_R 50 //UnitDisk radius

#define _run_speed_ms 50 
#define _MIS_apper_stop_ms 10
#define NODE_SIZE 5
#define PEN_WIDTH 0.1f
#define	_DENSITY 2		//高いと濃度が低い
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
// TODO: プログラムに必要な追加ヘッダーをここで参照してください。

typedef struct  {
	bool AA;
	unsigned int unitdisk_r;
	int topology; //0:Random, 1:UnitDisk
}Settings;