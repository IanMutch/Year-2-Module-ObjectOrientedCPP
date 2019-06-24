#include "methods.h"

void CenterText(string t)
{ 
	streamsize width = (streamsize)(t.length() + 80) / 2;
	cout << setw(width) << t << endl;
}

string IntToString(int i)
{
	ostringstream convert;
	convert << i; 
	return convert.str();
}