#pragma once

/*
*
* Author : SUMAN SOURABH
* EMAIL ID - sumansourabh26@gmail.com
* Problem :https://www.codechef.com/DSAPREP_03/problems/JUMPEND
*/

#include<iostream>
#include<cmath>
#include<vector>
#include<fstream> 
#include<cstring>
#include<climits>
#include<algorithm>
#include<stack>
#include<string>


using namespace std;

void  run() {
	freopen("myfile.txt", "r", stdin);
	freopen("outfile.txt", "w", stdout);
}

#define MaxN 100001
#define debug 0
#define MOD (10 )
#define ll long long int
#define vi vector<int>
#define loopi(i,data,n) for(int i = data; i < n; i++)
#define loopie(i,data,n) for(int i = data; i <= n; i++)
#define loopd(i,data,n) for(int i = data; i >=n; i--)
template <typename A> ostream& operator<< (ostream& cout, vector<A> const& v) { cout << "["; for (int i = 0; i < v.size(); i++) { if (i) cout << ", "; cout << v[i] << '\t'; } return cout << "]\n"; }

vi arr;

int mainFunction() {
	run();
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q = 1;
	cin >> q;
	while (q--) {
		int n;  cin >> n;
		arr.resize(n);
		loopi(i, 0, n)cin >> arr[i];

		int reached = n - 1, ans = 0;

		for (int counter = reached - 1; counter >= 0; counter--) {
			if (arr[counter] + counter >= reached) {
				reached = counter;
				ans++;
			}
		}
		if (reached != 0) cout << -1 << endl;
		else cout << ans << endl;
	}

	return 0;
}