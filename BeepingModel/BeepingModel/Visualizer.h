#pragma once
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
		bool AA;
	public:
		Visualizer(void);
		Visualizer(Controller^,Graphics^);
		void Draw(void);
		void Clear(void);
		void SetParameter(Settings*);
	};
}
