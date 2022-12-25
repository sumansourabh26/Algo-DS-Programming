#pragma once
#pragma once
// https://www.hackerrank.com/challenges/crush/problem

#include"crush_HR.h"
#include <iostream>
#include <vector>
#include <fstream> 
#include<cmath>
using namespace std;

ifstream fp_in;
ofstream fp_out;

long long tree[26666497], maxi[16777218];
long long pow2 = 1, p, init, last, add;


long long addfunc(long long node, long long p) {

	if (node > 26666496) return 0;

	if (node == init || node == last) {
		tree[node] += add;
		return tree[node];
	}
	if (!p) return (tree[node]);
	long long left = node << p;
	long long right = left - 1 + ((long long)1 << (p));
	if (left > last || right < init) return (maxi[node]);
	if (left >= init && right <= last) {
		tree[node] += add;
		maxi[node] += add;
		return(maxi[node]);
	}
	else {
		long long temp = node << 1;
		maxi[node] = max(tree[node] + max(addfunc(temp, p - 1), addfunc(temp + 1, p - 1)), maxi[node]);
		return maxi[node];
	}
}

void run()
{
	fp_in.open("myfile.txt", ios::in);    // open the streams
	fp_out.open("outfile.txt", ios::out);

	long long size, query_count;
	fp_in >> size >> query_count;


	for (p = 0; pow2 < size; p++) {
		pow2 = pow2 << 1;
	}

	//while (pow2 < size) pow2 = pow2 << 1;
	for (long long i = 0; i < query_count; i++) {
		fp_in >> init >> last >> add;
		//fp_out << init<< " " << last <<endl;
		init = init - 1 + pow2;
		last = last - 1 + pow2;
		addfunc(1, p);

	}
	fp_out << maxi[1] << " " << maxi[0];
	cout << maxi[1] << " " << maxi[0];


	fp_in.close();   // close the streams
	fp_out.close();


}

