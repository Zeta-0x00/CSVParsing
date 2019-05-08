#include <iostream>
#include <stdlib.h>
#include<string>
#include<vector>
#include <fstream>

std::vector<std::string> Read(const std::string &FileName);
int main()
{
	std::vector<std::string> x = Read("Hola.csv");
	for (unsigned int i = 0; i < x.size(); i++) { std::cout << x[i] << std::endl; }
	system("pause");
}

std::vector<std::string> Read(const std::string &FileName)
{
	
	std::ifstream file;
	file.open(FileName, std::ios::in);
	if (file.fail()) { std::cout << "This file not exist\n"; exit(1); }
	else
	{
		std::string line;
		std::string aux = "";
		std::vector<std::string> words;
		bool flag = false;
		while (!file.eof()) 
		{
			std::getline(file, line);
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