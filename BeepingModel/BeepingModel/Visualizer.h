#pragma once
#include "StdAfx.h"

namespace BeepingModel{
	using namespace System::Drawing;
	ref class Visualizer
	{
	private:
		Controller^ controller;
		Graphics^ g;
		cli::array<Pen^>^ pen_node;
		cli::array<Pen^>^ pen_line;
		cli::array<SolidBrush^>^ brush;
		bool AA;
		int NODE_SIZE;
		float PEN_WIDTH;
	public:
		Visualizer(void);
		Visualizer(Controller^,Graphics^);
		void Draw(void);
		void Clear(void);
		void SetParameter(Settings*);
		void AllocatePens();
	};
}
