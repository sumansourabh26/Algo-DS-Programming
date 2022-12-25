#pragma once
#pragma once
//https://www.hackerrank.com/challenges/array-and-simple-queries/problem
#include <iostream>
#include <vector>
#include <fstream> 
#include <cmath>

using namespace std;
ifstream fin;
ofstream fout;

void setupIO() {
	fin.open("myfile.txt", ios::in);    // open the streams
	fout.open("outfile.txt", ios::out);
}



void run() {
	setupIO();
	vector<int> vec{ 1,2,3,4,5 };
	vector<int>::iterator itr = vec.end(); --itr;
	fout << *itr;

	vec.push_back(6);
	fout << *itr;
	fout.close();

}
