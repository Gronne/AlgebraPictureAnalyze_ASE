#include "stdafx.h"
#include "Compare.h"


Compare::Compare(int *MA, int length)
{
	cout << endl;
	for (size_t i = 0; i < length; i++)
	{
		cout << MA[i] << " ";
	}
	cout << endl << endl;

	_length = (length - 2);
	_components = _length / 5;

	cout << "_Length: " << _length << endl;
	cout << "_components " << _components << endl;

	numberArray = new int[_components];

	int counter = 1;
	for (size_t i = 0; i < _components; i++)
	{
		numberArray[i] = watsDaNumb(MA[counter], MA[counter + 1], MA[counter + 2], MA[counter + 3], MA[counter + 4]);
		counter += 5;
		//cout << numberArray[i] << endl;

		if (numberArray[i] == 10)
		{
			cout << endl << "FAIL" << endl << endl;
			break;
		}
	}

	for (size_t i = 0; i < _components; i++)
	{
		cout << numberArray[i]<< " ";
	}

	int size = 0;
	for (size_t i = 0; i < _components; i++)
	{
		size += numberArray[i];
	}

	cout << endl << endl << endl << "Size: " << size << endl;

	if (size > _length)
	{
		cout << "SOMETHING OS WRONG! IT'S OVER: " << _length << endl;
	}
	else
	{
		cout << "Everything is perfect and there is: " << _length - size << " in reserve" << endl;
	}


}

int Compare::watsDaNumb(int one, int two, int three, int four, int five)
{
	if (one == 1 && two == 1 && three == 0 && four == 0 && five == 0)
	{
		return 0;
	}
	else if (one == 0 && two == 0 && three == 0 && four == 1 && five == 1)
	{
		return 1;
	}
	else if (one == 0 && two == 0 && three == 1 && four == 0 && five == 1)
	{
		return 2;
	}
	else if (one == 0 && two == 0 && three == 1 && four == 1 && five == 0)
	{
		return 3;
	}
	else if (one == 0 && two == 1 && three == 0 && four == 0 && five == 1)
	{
		return 4;
	}
	else if (one == 0 && two == 1 && three == 0 && four == 1 && five == 0)
	{
		return 5;
	}
	else if (one == 0 && two == 1 && three == 1 && four == 0 && five == 0)
	{
		return 6;
	}
	else if (one == 1 && two == 0 && three == 0 && four == 0 && five == 1)
	{
		return 7;
	}
	else if (one == 1 && two == 0 && three == 0 && four == 1 && five == 0)
	{
		return 8;
	}
	else if (one == 1 && two == 0 && three == 1 && four == 0 && five == 0)
	{
		return 9;
	}


	return 10;
}


Compare::~Compare()
{
	delete[] numberArray;
}
