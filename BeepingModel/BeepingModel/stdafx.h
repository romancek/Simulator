// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
#pragma once
#include "Controller.h"
#include "Node.h"

#define N_SIZE 1000

//action state
#define beeping 0
#define listen 1
//node state
#define inactive 2
#define competing 3
#define MIS 4
//hearing state
#define beep 5
#define silent 6
// TODO: プログラムに必要な追加ヘッダーをここで参照してください。
