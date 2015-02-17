#pragma once
class DataManager
{
private:
	picojson::object *obj;
public:
	DataManager();
	~DataManager();
	void OutPutJSON(void);
};

