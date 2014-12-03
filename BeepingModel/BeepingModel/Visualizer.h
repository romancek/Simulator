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
		bool stop;
	public:
		Visualizer(void);
		Visualizer(Controller^,Graphics^,int,int);
		void Run(void);
		void Draw(void);
		void Set(void);
		void Clear(void);
		void AA(bool);

		property bool Stop {
				bool get(){return this->stop;}
				void set(bool value){this->stop = value;}
		}
	};
}
