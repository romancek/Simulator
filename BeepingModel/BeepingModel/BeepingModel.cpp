// BeepingModel.cpp : メイン プロジェクト ファイルです。

#include "stdafx.h"

using namespace BeepingModel;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// コントロールが作成される前に、Windows XP ビジュアル効果を有効にします
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	int NODE_SIZE = 5;
	float PEN_WIDTH = 0.1f;
	// メイン ウィンドウを作成して、実行します
	Application::Run(gcnew Form1());
	return 0;
}
