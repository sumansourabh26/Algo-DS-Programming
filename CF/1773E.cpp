#include <bits/stdc++.h>
using namespace std;
#define MOD (1e9+7)
#define ll long long
#define vi vector<int>
#define loopi(i,val,n) for(int i = val; i < n; i++)
#define loopd(i,val,n) for(int i = val; i >=n; i--)
template <typename A> ostream& operator<< ( ostream& cout, vector<A> const& v ) { cout << "["; for ( int i = 0; i < v.size ( ); i++ ) { if ( i ) cout << ", "; cout << v[i]; } return cout << "]"; }


int main ( ) {
	int n; cin>>n;
	vector<vi> blocks(n);
	vi sequencer;
	unordered_map<int,int> positions;

	loopi(i,0,n){
		int size; cin>>size;
		blocks[i].resize(size);
		loopi(j,0,size){
			cin>>blocks[i][j];
			sequencer.push_back(blocks[i][j]);
		}
	}
	sort(sequencer.begin(), sequencer.end());

	loopi(i,0,sequencer.size()){
		positions[sequencer[i]] = i;
	}


	loopi(i,0,n){
		loopi(j,0,blocks[i].size()){
			blocks[i][j] = positions[blocks[i][j]];
		}
	}
//	cout<<blocks<<endl;

	int splits = 0;
	loopi(i,0,n){
		int last = blocks[i][0];
		loopi(j,1,blocks[i].size()){
			if(blocks[i][j] != (last+1)) splits++;
			last = blocks[i][j]; 
		}
	}

	int combine = (n+splits-1);

	cout<<splits<<' '<<combine;


}