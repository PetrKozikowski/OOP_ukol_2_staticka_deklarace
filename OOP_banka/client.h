#pragma once
 

using namespace std;

class Client
{
private:
	static int objectsCount;
	int code;
	string name;

public:
	Client(int c, string n);
	~Client();
	int GetCode();
	string GetName();
	static int GetObjectsCount();


};