#include "stdafx.h"
#include "Hello.h"
#include <iostream>
#include <string>

Hello::Hello()
{
}

Hello::~Hello()
{
}

void Hello::welcome() {
	cout << "Welcome to the Hello class!" << endl;
}

void Hello::setName(string nameIn) {
	name = nameIn;
}

string Hello::getMessage() {
	return "Hello " + name + ". Nice to meet you!";
}
