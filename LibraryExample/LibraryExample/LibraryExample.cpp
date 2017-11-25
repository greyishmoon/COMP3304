// SimpleFreeImageApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <iostream>
#include <memory>
#include <FreeImagePlus.h>
#include <process.h>


// pull-in libraries:
// (Note: these pragmas are needed for the resulting exe to run in Windows)
// (The upside is that use of these pragmas removes the need to reference the libraries, or their directories, in the 'properties' menu)
#pragma comment (lib, "Libs/FreeImagePlusd.lib")
#pragma comment (lib, "Libs/FreeImaged.lib")

#define NO_OF_ARGS 2

using namespace std;

int main(int argc, char **argv)
{
	// Check we have correct number of command-line arguments
	if (argc != NO_OF_ARGS)
	{
		cerr << "Usage: ConsoleApplication2 <image filename>" << endl;
	}
	else
	{
		// INSTANTIATE a fipImage and make a unique pointer, called 'imgPtr', point to it:
		unique_ptr<fipImage> imgPtr(new fipImage());

		// CREATE a string and store argv[1] in it as the image filename, call it imageFilename:
		string imageFilename = argv[1];

		// SET the image filename as a pointer to a const char array to play nice with FreeImage, call it 'imgFile':
		const char* imgFile = imageFilename.c_str();

		// LOAD the image pointed to by imgFile into imgPtr, store the boolean success flag in 'loadFlag':
		BOOL loadFlag = imgPtr->load(imgFile);

		// IF the load was successful...
		if (loadFlag > 0)
		{
			// OUTPUT some basic image info:
			cout << "Image: " << imgFile << " is size: " << imgPtr->getWidth() << "x" << imgPtr->getHeight() << "." << endl;
		}

		// OTHERWISE...
		else
		{
			cout << "Could not load image: " << imageFilename << endl;
		}
	}

	system("pause");

	return 0;
}

