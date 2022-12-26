#pragma once
/*
*
* Author : SUMAN SOURABH
* EMAIL ID - sumansourabh26@gmail.com
* Problem :https://www.codechef.com/INTPREP_01/problems/PREP35
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

vector<string> region;
vector<vector<bool>> saved;
int n;

bool isValid(int r, int c) {
	if (r < 0 || c < 0 || r >= n || c >= n) return false;
	else if (region[r][c] == 'X') return false;
	else return true;
}

int nbr[4][2] = { {1,0},{-1,0},{0,1}, {0,-1} };

void dfs(int r, int c) {
	if (region[r][c] == 'X') return;

	saved[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int x = r + nbr[i][0], y = c + nbr[i][1];
		if (isValid(x, y)) {
			if (!saved[x][y]) dfs(x, y);
		}
	}


}

int mainFunction() {
	run();
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q = 1;
	cin >> q;
	while (q--) {
		cin >> n;
		region.resize(n);
		loopi(i, 0, n) {
			cin >> region[i];
		}
		saved.assign(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++) dfs(0, i);
		for (int i = 0; i < n; i++) dfs(n - 1, i);
		for (int i = 0; i < n; i++) dfs(i, 0);
		for (int i = 0; i < n; i++) dfs(i, n - 1);

		loopi(i, 0, n) {
			loopi(j, 0, n) {
				if (region[i][j] == 'X') cout << 'X';
				if (region[i][j] == 'O') {
					if (saved[i][j]) cout << 'O';
					else cout << 'X';
				}
			}
			cout << endl;

		}

	}

	return 0;
}