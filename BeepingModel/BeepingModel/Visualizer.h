#pragma once
namespace BeepingModel{
	using namespace System::Drawing;
	ref class Visualizer
	{
	private:
		Controller^ controller;
		Graphics^ g;
	public:
		Visualizer(void);
		Visualizer(Controller^,Graphics^);
		void Draw(void);
	};
}
