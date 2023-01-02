#include <iostream>
#include <vector>
#include <fstream> 
#include <iterator>
#include <algorithm>

using namespace std;

#define MaxN 10
#define MOD (10 )
#define ll long long int
#define vi vector<int>
#define loopi(i,data,n) for(int i = data; i < n; i++)
#define loopie(i,data,n) for(int i = data; i <= n; i++)
#define loopd(i,data,n) for(int i = data; i >=n; i--)
template <typename A> ostream& operator<< ( ostream& cout, vector<A> const& v ) { cout << "["; for ( int i = 0; i < v.size ( ); i++ ) { if ( i ) cout << ", "; cout << v[i] << '\t'; } return cout << "]\n"; }

void  run ( ) {
	freopen ( "in", "r", stdin );
	//freopen ( "outfile.txt", "w", stdout );
}



struct Node {
    int value;
    friend ostream &operator<<( std::ostream &out, const Node n){
        out<<n.value<<' ';  
        return out;    
    }
};

vector<Node> tree(4*MaxN);

Node combine(Node &a, Node &b){
    return Node({min(a.value , b.value)});
}


void buildTree(int arr[], int vertex, int l, int r){
    if(l==r){
        tree[vertex] = Node{arr[l]};
        cout<<arr[l]<<' ';
        return;
    }
    int mid = (l+r)>>1;
    buildTree(arr, vertex<<1, l, mid);
    buildTree(arr, (vertex<<1)+1, mid+1, r);
    tree[vertex] = combine(tree[vertex*2], tree[vertex*2+1]);
}

Node query(int l, int r, int v, int tl, int tr ){ // l,r ->array range of query. tl, tr - are the range of node v. 
    if (l == tl && r == tr) {
        return tree[v];
    }
    int mid =(tl+tr)>>1;
    if(r<=mid) return query(l,r,(v<<1), tl, mid);
    if(mid<l) return query(l,r,((v<<1))+1, mid+1, tr);
    else{
        Node n1 = query(l,mid,(v<<1), tl, mid);
        Node n2 = query(mid+1,r,(v<<1)+1, mid+1, tr);
        return combine(n1,n2);
    }
}

void update(int pos, int v, int tl, int tr, int new_val){
    if(tl == tr){
        tree[v] = Node({new_val});
        return;
    }
    int mid = (tl + tr)>>1;
    if(pos <= mid) update(pos, v<<1, tl, mid, new_val);
    else if(pos > mid) update(pos, 1+(v<<1), mid+1, tr, new_val);

    tree[v] = combine(tree[v<<1], tree[(v<<1)+1]);
}

int main(){
    run();

    int n; cin>>n;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    cout<<endl;
    buildTree(arr, 1, 0, n-1); cout<<endl;
    cout<<tree;

}