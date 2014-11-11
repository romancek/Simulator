#pragma once

namespace BeepingModel{
	ref class Channel
	{
	private:
		int id;
	public:
		Channel(void);
		Channel(int);
	public:
		property int Id {
			int get() { return this->id; }
			void set( int value ) { this->id = value; }
		}
	};
}
