#pragma once

namespace BeepingModel{
	ref class Channel
	{
	private:
		int id;
		array<int>^ endpoint;
	public:
		Channel(void);
		Channel(int);
		void SetEndPoint(int,int);
	public:
		property int Id {
			int get() { return this->id; }
			void set( int value ) { this->id = value; }
		}
		property array<int>^ EndPoint {
			array<int>^ get(){return this->endpoint;}
			void set(array<int>^ ep){this->endpoint = ep;}
		}
	};
}
