#pragma once
#include <string>
using  namespace std;

class Hello
{
private:
	// Member variables
	string name;
public:
	Hello();
	~Hello();
	// Methods
	void welcome();
	void setName(string nameIn);
	string getMessage();
};

