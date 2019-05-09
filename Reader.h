#ifndef READER_H
#define READER_H
#include <iostream>
#include <stdlib.h>
#include<string>
#include<vector>
#include <fstream>

namespace std
{
    vector<string> Read(const string &FileName)
{
	
	ifstream file;
	file.open(FileName, ios::in);
	if (file.fail()) { cout << "This file not exist\n"; exit(1); }
	else
	{
		string line;
		string aux = "";
		vector<string> words;
		bool flag = false;
		while (!file.eof()) 
		{
			getline(file, line);
			for (unsigned int i = 0; i < line.size(); i++)
			{
				
				if (line[i] != ';') { aux += line[i]; flag = true; }
				if (line[i] == ';' && flag == true) { words.push_back(aux); aux = ""; flag = false; }
			}
			words.push_back(aux); aux = ""; flag = false;
		}
		file.close();
		return words;
	}
}

}


#endif //!READER_H