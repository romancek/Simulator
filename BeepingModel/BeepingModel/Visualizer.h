#pragma once
#include "Controller.h"
#include "StdAfx.h"
namespace BeepingModel{
	using namespace System::Drawing;
	ref class Visualizer
	{
	private:
		Controller^ controller;
		Graphics^ g;
		array<Pen^>^ pen_node;
		array<Pen^>^ pen_line;
		array<SolidBrush^>^ brush;
		bool stop;
		bool AA;
	public:
		Visualizer(void);
		Visualizer(Controller^,Graphics^);
		void Run(void);
		void Draw(void);
		void Clear(void);
		void SetParameter(Settings*);

		property bool Stop
		{
				bool get(){return this->stop;}
				void set(bool value){this->stop = value;}
		}
	};
}
