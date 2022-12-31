#pragma once
/*
* 
* Author : SUMAN SOURABH
* EMAIL ID - sumansourabh26@gmail.com
* Problem :https://leetcode.com/problems/n-queens/description/
* 
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
#include<queue>
#include<unordered_map>

using namespace std;

void  run() {
    freopen("myfile.txt", "r", stdin);
    freopen("outfile.txt", "w", stdout);
}

#define MaxN 5002
#define debug 0
#define MOD (1000000007 )
#define ll long long int
#define vi vector<int>
#define loopi(i,data,n) for(int i = data; i < n; i++)
#define loopie(i,data,n) for(int i = data; i <= n; i++)
#define loopd(i,data,n) for(int i = data; i >=n; i--)
template <typename A> ostream& operator<< (ostream& cout, vector<A> const& v) { cout << "["; for (int i = 0; i < v.size(); i++) { if (i) cout << ", "; cout << v[i]; } return cout << "]\n"; }


vector<int> curr_pos;
int board_size;
vector<vector<string>> ans;

bool isValid(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (curr_pos[i] == col) return false;
        if (abs(curr_pos[i] - col) == abs(row - i)) return false;
    }
    return true;

}
vector<string> stringRepresent() {
    vector<string> chess;
    for (int i = 0; i < board_size; i++) {
        string s(board_size, '.');
        s[curr_pos[i]] = 'Q';
        chess.push_back(s);
    }
    return chess;
}
void solveNQueensHelper(int curr_row) {
    if (curr_row == board_size) {
        ans.push_back(stringRepresent());
    }

    for (int j = 0; j < board_size; j++) {
        if (isValid(curr_row, j)) {
            curr_pos[curr_row] = j;
            solveNQueensHelper(curr_row + 1);
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    ans.clear();
    curr_pos.clear();
    board_size = n;
    curr_pos.resize(n);
    solveNQueensHelper(0);
    return ans;

}

int mainFunction() {
    run();
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc = 1;
    //cin >> tc;

    for (int i = 0; i < tc; i++) {
        solveNQueens(4);
    }
    cout << ans;

}