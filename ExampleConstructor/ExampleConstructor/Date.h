#pragma once
class Date
{
public:
	Date();
	Date(int dy, int mnth, int yr);
	~Date();
	void print();
private:
	int day;
	int month;
	int year;
};

