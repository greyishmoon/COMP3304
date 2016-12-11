// S01-Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Calc.h"

using  namespace std;

int main()
{
	// define variables
	double num1, num2;
	char operation, redo;
	// define and instantiate Calc object
	Calc func = Calc();

	// print welcome
	cout << " Welcome to the calculater program v.1.0 written by Chris" << endl;
	cout << " ********************************************************" << endl << endl << endl;

	// loop to keep running calculations unless exit selected
	do
	{
		// capture input
		cout << " Please enter an operation which you like to calculate (+,-,*,/): ";
		cin >> operation;
		cout << endl;
		cout << " Please enter two numbers to apply your requested operation(" << operation << ")..." << endl;
		cout << " 1st num: ";
		cin >> num1;
		cout << " 2nd num: ";
		cin >> num2;
		cout << endl;

		// switch statement to call correct operation and generate result output
		switch (operation)
		{
		case'+':
			cout << " The addition of two numbers (" << num1 << "," << num2 << "): ";
			// call add method
			cout << func.add(num1, num2) << endl;
			break;

		case'-':
			cout << " The substraction of two numbers (" << num1 << "," << num2 << "): ";
			// call subtract method
			cout << func.subtract(num1, num2) << endl;
			break;

		case'*':
			cout << " The multiplication of two numbers (" << num1 << "," << num2 << "): ";
			// call multiply method
			cout << func.multiply(num1, num2) << endl;
			break;

		case'/':
			cout << " The division of two numbers (" << num1 << "," << num2 << "): ";
			// protect against div by zero error
			if (num2 == 0)
			{
				cout << " not valid - divide by zero" << endl;
			}
			else
			{
				// call divide method
				cout << func.divide(num1, num2) << endl;
			}
			break;

		default:
			cout << " unknown command" << endl;
		}

		// handle redo or exit
		cout << endl << " 'r' for another calculation or 'x' to exit: ";
		cin >> redo;
		cout << endl << endl;

	}
	while (redo == 'r' || redo == 'R');

    return 0;
}

