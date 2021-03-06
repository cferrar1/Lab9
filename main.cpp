// cosc2030 lab9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

map<string, int> fileToMap(string filename);
void mapToFile(map<string, int> outmap);

int main()
{
	string filename = "example.txt";
	map<string, int> testmap = fileToMap(filename);
	mapToFile(testmap);
	return 0;
}

map<string, int> fileToMap(string filename)
{
	map <string, int> inmap;
	ifstream infile;
	infile.open(filename);
	string word;
	if (!infile)
	{
		cerr << "Failed to open file";
		exit(1);
	}
	while (infile >> word)
	{
		inmap.insert(make_pair(word, 0));
		inmap[word]++;
	}
	infile.close();
	return inmap;
}

void mapToFile(map<string, int> outmap)
{
	ofstream outfile;
	outfile.open("output.txt");
	map<string, int>::iterator it;
	for (it = outmap.begin(); it != outmap.end(); it++)
	{
		for (int i = 0; i < it->second; i++)
		{
			outfile << it->first << " ";
		}
		outfile << endl;
	}
	cout << "Success! (probably)" << endl;
}

