// S01-HelloWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "hello.h"
#include <process.h>
using  namespace std;

int main()
{
	Hello myHello;
	string nameInput;

	myHello.welcome();
	cout << "What is your name? ";
	cin >> nameInput;
	myHello.setName(nameInput);
	cout << myHello.getMessage() << endl;
	system("pause");
	return 0;
}