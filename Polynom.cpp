// Polinom.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TPolynom.h"
//#include "THeadList.h"
//#include "TLink.h"
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	// Test compiling
	TLink<int> a;
	THeadList<int> b;
	TPolynom P,Q;
	// Test compiling

	cout << "Полином P" << endl;
	P.InsPoly();
	system("cls");
	cout << "Полином Q" << endl;
	Q.InsPoly();
	system("cls");
	cout << "P: ";
	P.OutPoly();
	cout << endl;
	cout << "Q: ";
	Q.OutPoly();
	cout << endl;
	P += Q;
	cout << "P+Q: ";
	P.OutPoly();

	return 0;
}

