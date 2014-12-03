#pragma once
namespace BeepingModel{
	using namespace System::Drawing;
	ref class Visualizer
	{
	private:
		Controller^ controller;
		Graphics^ g;
		int x;
		int y;
		Pen^ pen_node;
		array<Pen^>^ pen_line;
		SolidBrush^ brush;
	public:
		Visualizer(void);
		Visualizer(Controller^,Graphics^,int,int);
		void Draw(void);
		void Set(void);
		void Clear(void);
	};
}
