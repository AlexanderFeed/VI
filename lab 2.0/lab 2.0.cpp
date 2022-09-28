#include <iostream>
#include <list>
#include <fstream>
#include <string>
using namespace std;

bool IsSimple(int a)
{
	int k = 1;
	if (a == 1)
		return false;

	for (int i = 1; i <= sqrt(a); i++)
		if (a % i == 0)
			k++;

	if (k == 2)
		return true;
	else
		return false;
}

int main()
{
	string code;
	string strSimple = "";
	string strNotSimple = "";
	int shift = 0;
	int quantitySimple = 0;
	int strLength;

	ifstream in("in.txt");

	if (in.is_open()) {
		in >> shift;
		getline(in, code);
		getline(in, code);
	}

	in.close();
	strLength = code.length();

	for (int i = 1; i <= code.length(); i++)
		if (IsSimple(i))
			quantitySimple++;

	for (int ish = 0; ish < shift; ish++)
	{
		strSimple = "";
		strNotSimple = "";

		for (int i = 0; i < quantitySimple; i++)
			strSimple.push_back(code[i]);

		for (int i = quantitySimple; i < code.length(); i++)
			strNotSimple.push_back(code[i]);

		int iS = 0;
		int iNS = 0;
		code = "";

		for (int i1 = 1; i1 <= strLength; i1++)
		{
			if (IsSimple(i1))
			{
				code.push_back(strSimple[iS]);
				iS++;
			}
			else
			{
				code.push_back(strNotSimple[iNS]);
				iNS++;
			}
		}
	}
	fstream out("out.txt");
	out << code;
	out.close();
}




