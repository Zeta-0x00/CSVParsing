#include <vector>
#include <string>
#include <iostream>
#include "Reader.h"
#include "Writer.h"

using namespace std;
int main()
{
	const string path = "ejemplo.csv";
	vector<string> x = Read(path);
	for (unsigned int i = 0; i < x.size(); i++) { cout << x[i] << endl; }
	x.push_back("Hallo; this is the; test");
	Write(x,path);
	for (unsigned int i = 0; i < x.size(); i++) { cout << x[i] << endl; }
	system("pause");
}
