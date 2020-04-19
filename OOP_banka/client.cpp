#include <string>
#include <iostream>
#include "client.h"

using namespace std;

int Client::objectsCount = 0;

Client::Client(int c, string n)
{
	code = c;
	name = n;
	objectsCount++;
	cout << "Pocet vytvorenych klientu: " << objectsCount << endl;
}

Client::~Client()
{
	objectsCount--;	
}

int Client::GetCode()
{
	return code;
}

string Client::GetName()
{
	return name;
}

int Client::GetObjectsCount()
{
	return objectsCount;
}