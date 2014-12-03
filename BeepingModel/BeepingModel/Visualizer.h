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
		array<Pen^>^ pen_node;
		array<Pen^>^ pen_line;
		SolidBrush^ brush;
	public:
		Visualizer(void);
		Visualizer(Controller^,Graphics^,int,int);
		void Run(void);
		void Draw(void);
		void Set(void);
		void Clear(void);
		void AA(bool);
	};
}
