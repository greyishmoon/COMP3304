// ExampleClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <process.h>
#include "Number.h"

using  namespace std;

int main()
{
	Number myNum = Number();
	myNum.setNum(42);
	cout << "Number set was: " << myNum.getNum() << endl;

	system("pause");
    return 0;
}

