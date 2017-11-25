// ExamplePointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <process.h>
#include <memory>
using  namespace std;


int main()
{
	int x = 5;
	int y = 10;
	cout << "Simple x value (x): " << x << '\n'; // value of variable x
	cout << "Address-of x (&x): " << &x << '\n'; // memory address of variable x
	cout << '\n';

	cout << "Simple x value (y): " << y << '\n'; // value of variable x
	cout << "Address-of x (&y): " << &y << '\n'; // memory address of variable x
	cout << '\n';

	int *iPtr = new int{ 42 };
	cout << "iPtr value (*iPtr) : " << *iPtr << '\n'; // value of variable iPtr
	cout << "Address-of iPtr (iPtr): " << iPtr << '\n'; // memory address of variable iPtr
	cout << '\n';

	iPtr = &y;		// assign y memory location to iPtr
	// BUT - allocated memory for original iPtr (42) is now not referenced but not deleted - MEMORY LEAK
	cout << "iPtr (y) value (*iPtr) : " << *iPtr << '\n'; // value of variable iPtr
	cout << "Address-of (y) iPtr (iPtr): " << iPtr << '\n'; // memory address of variable iPtr
	cout << '\n';

	int *iPtr2 = new int{ 99 };
	cout << "iPtr2 value (*iPtr2) : " << *iPtr2 << '\n'; // value of variable iPtr2
	cout << "Address-of iPtr (iPtr2): " << iPtr2 << '\n'; // memory address of variable iPtr2
	cout << '\n';

	cout << "copy iPtr2 to iPtr3 >>" << '\n'; 
	int *iPtr3;
	iPtr3 = iPtr2;
	cout << "iPtr3 value (*iPtr3) : " << *iPtr3 << '\n'; // value of variable iPtr3
	cout << "Address-of iPtr (iPtr3): " << iPtr3 << '\n'; // memory address of variable iPtr3
	cout << '\n';

	cout << "delete iPtr2 and reset >>" << '\n';
	delete iPtr2;
	iPtr2 = 0;
//	cout << "iPtr2 value (*iPtr2) : " << *iPtr2 << '\n'; // value of variable iPtr2 >>>>>>>> Throws null pointer exception
	cout << "Address-of iPtr (iPtr2): " << iPtr2 << '\n'; // memory address of variable iPtr2
	cout << '\n';

	cout << "iPtr3 still pointing to dealloc memory - stores??? (probably garbage) >>" << '\n';
	cout << "iPtr3 value (*iPtr3) : " << *iPtr3 << '\n'; // value of variable iPtr3
	cout << "Address-of iPtr (iPtr3): " << iPtr3 << '\n'; // memory address of variable iPtr3
	cout << '\n';

	//SMART POINTERS
	shared_ptr<int> shPtr1(new int{ 111 });
	cout << "shPtr1 value (*shPtr1) : " << *shPtr1 << '\n'; // value of variable shPtr1
	cout << "Address-of iPtr (shPtr1): " << shPtr1 << '\n'; // memory address of variable shPtr1
	cout << "shPtr1 count (shPtr1.use_count()) : " << shPtr1.use_count() << '\n'; // number of pointer to this memory loc
	cout << '\n';

	shared_ptr<int> shPtr2(shPtr1);
	cout << "shPtr2 value (*shPtr2) : " << *shPtr2 << '\n'; // value of variable shPtr2
	cout << "Address-of iPtr (shPtr2): " << shPtr2 << '\n'; // memory address of variable shPtr2
	cout << "shPtr1 count (shPtr1.use_count()) : " << shPtr1.use_count() << '\n'; // number of pointer to this memory loc
	cout << "shPtr2 count (shPtr1.use_count()) : " << shPtr2.use_count() << '\n'; // number of pointer to this memory loc
	cout << '\n';

	shared_ptr<int> shPtr3;
	shPtr3 = shPtr2;
	cout << "shPtr3 value (*shPtr3) : " << *shPtr3 << '\n'; // value of variable shPtr3
	cout << "Address-of iPtr (shPtr3): " << shPtr3 << '\n'; // memory address of variable shPtr3
	cout << "shPtr1 count (shPtr1.use_count()) : " << shPtr1.use_count() << '\n'; // number of pointer to this memory loc
	cout << "shPtr2 count (shPtr1.use_count()) : " << shPtr2.use_count() << '\n'; // number of pointer to this memory loc
	cout << "shPtr3 count (shPtr1.use_count()) : " << shPtr3.use_count() << '\n'; // number of pointer to this memory loc
	cout << '\n';

	cout << "Reset shPtr1" << '\n';
	shPtr1.reset();
//	cout << "shPtr1 value (*shPtr1) : " << *shPtr1 << '\n'; // value of variable shPtr1   >>>>>>>> Throws exception
	cout << "Address-of shPtr1 (shPtr1): " << shPtr1 << '\n'; // memory address of variable shPtr1
	cout << "shPtr1 count (shPtr1.use_count()) : " << shPtr1.use_count() << '\n'; // number of pointer to this memory loc
	cout << '\n';
	cout << "shPtr2 value (*shPtr2) : " << *shPtr2 << '\n'; // value of variable shPtr2
	cout << "Address-of iPtr (shPtr2): " << shPtr2 << '\n'; // memory address of variable shPtr2
	cout << "shPtr3 value (*shPtr3) : " << *shPtr3 << '\n'; // value of variable shPtr3
	cout << "Address-of iPtr (shPtr3): " << shPtr3 << '\n'; // memory address of variable shPtr3
	cout << "shPtr2 count (shPtr1.use_count()) : " << shPtr2.use_count() << '\n'; // number of pointer to this memory loc
	cout << "shPtr3 count (shPtr1.use_count()) : " << shPtr3.use_count() << '\n'; // number of pointer to this memory loc
	cout << '\n';

	unique_ptr<int> uPtr1(new int{ 222 });
	cout << "uPtr1 value (*uPtr1) : " << *uPtr1 << '\n'; // value of variable uPtr1
	cout << "uPtr1 valid (uPtr1 != nullptr) : " << (uPtr1 != nullptr) << '\n'; // test if unique_ptr is null
//	cout << "Address-of uPtr1 (uPtr1): " << uPtr1 << '\n'; // memory address of variable uPtr1    >>>>>>>> Throws exception - unable to access memory location
	cout << '\n';

	unique_ptr<int> uPtr2 = move(uPtr1);
//	cout << "uPtr1 value (*uPtr1) : " << *uPtr1 << '\n'; // value of variable uPtr1    >>>>>>>> Throws exception - pointer is now null
	cout << "uPtr2 value (*uPtr2) : " << *uPtr2 << '\n'; // value of variable uPtr1
	cout << "uPtr1 valid (uPtr1 != nullptr) : " << (uPtr1 != nullptr) << '\n'; // test if unique_ptr is null
	cout << "uPtr2 valid (uPtr2 != nullptr) : " << (uPtr2 != nullptr) << '\n'; // test if unique_ptr is null
	cout << '\n';

	uPtr2.reset();
	cout << "uPtr2 valid (uPtr2 != nullptr) : " << (uPtr2 != nullptr) << '\n'; // test if unique_ptr is null

	system("pause");
    return 0;
}

