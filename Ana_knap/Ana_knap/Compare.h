#pragma once

#include <iostream>

using namespace std;

class Compare
{
public:
	Compare(int *, int);
	int watsDaNumb(int, int, int, int, int);
	~Compare();

private:
	int _length;
	int _components;

	int *numberArray;

};

