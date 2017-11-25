// ExampleConstructor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <process.h>
#include "Date.h"
using  namespace std;

int main()
{
	cout << "Start \n\n";

	cout << "Date1 (default): \n";
	Date date1;
	date1.print();

	cout << "\nDate2 (3 params): \n";
	Date date2{ 4, 8, 1985 };
	date2.print();


	cout << "\nEnd \n";
	system("pause");
    return 0;
}

