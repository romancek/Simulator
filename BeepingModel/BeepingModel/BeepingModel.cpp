// BeepingModel.cpp : メイン プロジェクト ファイルです。

#include "stdafx.h"
#include "Form1.h"
#include <version.hpp>
#include <iostream>
#include <string>

using namespace BeepingModel;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	std::cout << (BOOST_VERSION / 100000) << "." << (BOOST_VERSION / 100 % 1000) << "." << (BOOST_VERSION % 100) << std::endl;
	// コントロールが作成される前に、Windows XP ビジュアル効果を有効にします
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// メイン ウィンドウを作成して、実行します
	Application::Run(gcnew Form1());
	return 0;
}
