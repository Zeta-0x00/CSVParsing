#ifndef WRITER_H
#define WRITER_H
#include <iostream>
#include <stdlib.h>
#include<string>
#include<vector>
#include <fstream>

namespace std
{
    void Write(vector<string>&x, const string &path)
{
	ofstream File;
	File.open(path,ios::out);
	if(File.fail()){cout<<"Acction Imposible\n"; exit(1);}
	else 
	{
		string aux;
		for(unsigned int i=0; i<x.size(); i++)
		{
			aux+=x[i]+"\n";
		}
		File<<aux;
		File.close();
	}
}
}

#endif //!WRITER_H