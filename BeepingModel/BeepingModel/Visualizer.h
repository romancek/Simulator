#pragma once
namespace BeepingModel{
	ref class Visualizer
	{
	private:
		Controller^ controller;
	public:
		Visualizer(void);
		Visualizer(Controller^);
		void Draw(void);
	};
}
