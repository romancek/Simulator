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
		cli::array<Pen^>^ pen_line_multi;
		cli::array<SolidBrush^>^ brush;
		cli::array<SolidBrush^>^ brush_multi;
		cli::array<unsigned int>^ ch_colors;
		unsigned int channel_mode; //0:Single,1:Multi
		bool AA;
		int NODE_SIZE;
		float PEN_WIDTH;
		unsigned int F;
		unsigned int algorithm_type;
	public:
		Visualizer(void);
		Visualizer(Controller^,Graphics^);
		void Draw(void);
		void DrawSingleChannel(BufferedGraphics^);
		void DrawMultiChannel(BufferedGraphics^);
		void DrawOnlyMatchedPair(void);
		void MakeMultiColors();
		void Clear(void);
		void SetParameter(Settings*);
		void AllocatePens();
	};
}
