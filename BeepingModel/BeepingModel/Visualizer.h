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
	public:
		Visualizer(void);
		Visualizer(Controller^,Graphics^,int,int);
		void Draw(void);
		void Set(void);
	};
}
