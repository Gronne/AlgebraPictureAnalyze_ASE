// ConsoleApplication8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Ana_knap.h"
#include "Compare.h"

#include <iostream>
#include <string>

#include <cstring>
#include <atlstr.h>
#include <afxstr.h>
#include <atlimage.h>
#include <WINDOWS.H>
//#include <atlimpl.cpp>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define ASIZE 50

// The one and only application object

CWinApp theApp;

using namespace std;

int main()
{

	//----------------------- standard code - can not be edited -----------------------
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(nullptr);

	if (hModule != nullptr)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
		{
			// TODO: change error code to suit your needs
			wprintf(L"Fatal Error: MFC initialization failed\n");
			nRetCode = 1;
		}
		else
		{
			// TODO: code your application's behavior here.
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		wprintf(L"Fatal Error: GetModuleHandle failed\n");
		nRetCode = 1;
	}
	//--------------------------------------------------------------------------------------

	//--------------- init ---------------

	int bitColor;

	CImage image;
	CBitmap bitmap;

	FILE * bitFile;

	//--------------- setup ---------------

	image.Load(_T("C:\\bitmapping\\message_1.png")); // just change extension to load jpg

	bitmap.Attach(image);

	bitmap.SetBitmapDimension(image.GetWidth(), image.GetHeight());

	const int width = bitmap.GetBitmapDimension().cx;
	const int height = bitmap.GetBitmapDimension().cy;

	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;

	//----------- Processing ------------
	int first_i;
	int first_l;
	int std_height = 0;
	int std_width = 0;
	int now_height = 0;
	int now_width = 0;
	int Numbers[ASIZE] = { 0 };
	int Numbers2[ASIZE] = { 0 };
	int arrayCounter = 0;
	int check = 0;


	for (size_t i = 0; i < height; i++)
	{
		for (size_t l = 0; l < width; l++)
		{
			if (image.GetPixel(l, i) < 50000)
			{
				first_i = i;
				first_l = l;

				cout << "Height: " << first_i << " - Width: " << first_l << endl;
				cout << "Color: " << image.GetPixel(first_l, first_i) << endl << endl;

				check = 1;
			}
			if (check == 1)
			{
				break;
			}
		}
		if (check == 1)
		{
			break;
		}
	}


	for (size_t i = first_i; image.GetPixel(first_l, i) < 50000; i++)
	{
		std_height++;
	}

	first_i = first_i + ((std_height / 5) * 4);

	for (size_t l = first_l; image.GetPixel(l, first_i) < 50000; l++)
	{
		std_width++;
	}

	cout << "Height: " << first_i << " - Width: " << first_l << endl;
	cout << "Color: " << image.GetPixel(first_l, first_i) << endl;
	cout << "std height: " << std_height << endl;
	cout << "std Width: " << std_width << endl << endl;

	int check2 = 0;

	for (size_t l = 0; l < width; l++)
	{
		//cout << 1 << endl;
		if (image.GetPixel(l, first_i) < 50000 && check == 0)
		{
			//cout << 2 << endl;
			l += std_width/2;
			
			for (size_t i = first_i; image.GetPixel(l, i) < 50000; i--)
			{
				//cout << 3 << endl;
				now_height++;
			}
			//cout << "Now height: " << now_height << endl;

			(now_height < std_height / 2) ? Numbers[arrayCounter] = 0 : Numbers[arrayCounter] = 1;
			check = 1;
			now_height = 0;
			arrayCounter++;
		}
		else if(image.GetPixel(l, first_i) > 50000)
		{
			check = 0;
		}
	}

	/*int count3 = 0;
	cout << arrayCounter << endl;
	for (size_t i = 0; i < arrayCounter; i++)
	{
		//cout << 1 << endl;
		Numbers[count3] = Numbers2[i];
		count3++;
		i++;
	}*/
	

	/*cout << endl;
	for (size_t i = 0; i < arrayCounter; i++)
	{
		cout << Numbers[i] << " ";
	}
	cout << endl << endl;*/

	Compare AMN(Numbers, arrayCounter);

}