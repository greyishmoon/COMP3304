#include "stdafx.h"
#include "Date.h"
#include <iostream>
using  namespace std;

// Default constructor with initialisater list
Date::Date() : day{ 1 }, month{ 1 }, year{ 1970 }
{
	cout << "Date Default Constructor "  << "\n";
}

// Parameterised constructor with  initialisater list
Date::Date(int dy, int mnth, int yr) : day{dy}, month{mnth}, year{yr}  // directly initialize our member variables
{
	// No need for assignment here
}


Date::~Date()
{
	cout << "Date Default DESTRUCTOR " << "\n";
}

void Date::print()
{
	cout << "Day: " << day << " Month: " << month << " Year: " << year << "\n";
}
