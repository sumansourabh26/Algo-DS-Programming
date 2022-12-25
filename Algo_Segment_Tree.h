#pragma once

#include <iostream>
#include <vector>
#include <fstream> 
#include <iterator>
#include <algorithm>

using namespace std;

#define MaxN 100004
#define MOD (10 )
#define ll long long int
#define vi vector<int>
#define loopi(i,data,n) for(int i = data; i < n; i++)
#define loopie(i,data,n) for(int i = data; i <= n; i++)
#define loopd(i,data,n) for(int i = data; i >=n; i--)
template <typename A> ostream& operator<< ( ostream& cout, vector<A> const& v ) { cout << "["; for ( int i = 0; i < v.size ( ); i++ ) { if ( i ) cout << ", "; cout << v[i] << '\t'; } return cout << "]\n"; }

/// <summary>
/// segment Tree for range minimum 
/// </summary>

struct Node {
	int data, lr, rr; //left range, right range
	Node ( ) { //empty node (0 for sum, int_max for min)
		data = 0;
	}
	Node ( int d, int l, int r ) {
		data = d;
		lr = l; rr = r;
	}
};

vector<Node> t ( 4 * MaxN );

Node combine ( Node n1, Node n2 ) {
	Node n ( n1.data + n2.data, n1.lr, n2.rr );
	return n;
}

/*
 ti = index of tree node ( root = 1 )
 [tl ... tr] range under the node t[ti]
 arr = input arr
*/
void build ( vi& arr, int ti, int tl, int tr ) {
	if ( tl == tr ) {
		t[ti] = Node ( arr[tl], tl, tr );
	} else {
		int tm = ( tl + tr ) / 2;
		build ( arr, ti * 2, tl, tm );
		build ( arr, ti * 2 + 1, tm + 1, tr );
		t[ti] = combine ( t[ti * 2], t[ti * 2 + 1] );
	}
}

Node query ( int v, int l, int r ) {
	int tl = t[v].lr, tr = t[v].rr;

	if ( l <= tl && r >= tr ) {
		return t[v];
	}
	int tm = ( tl + tr ) / 2;

	Node* ln = NULL, * rn = NULL;
	if ( l <= tm ) {
		Node temp = ( query ( v << 1, l, r ) );
		ln = &temp;
	}
	if ( r > tm ) {
		Node temp = ( query ( 1 + ( v << 1 ), l, r ) );
		rn = &temp;
	}
	if ( ln == NULL ) return *rn;
	else if ( rn == NULL ) return *ln;
	else return  combine ( *ln, *rn );
}

void update ( int v, int pos, int new_val ) {
	int tl = t[v].lr, tr = t[v].rr;
	if ( tl == tr ) {
		t[v].data = new_val;;
	} else {
		int tm = ( tl + tr ) / 2;
		if ( pos <= tm )
			update ( v * 2, pos, new_val );
		else
			update ( v * 2 + 1, pos, new_val );
		t[v] = combine ( t[v * 2], t[v * 2 + 1] );
	}
}

void lazyUpdate ( int v, int l, int r, int add ) {
	int tl = t[v].lr, tr = t[v].rr;
	if ( l > r )
		return;
	if ( l == tl && r == tr ) {
		t[v].data += add;
	} else {
		int tm = ( tl + tr ) / 2;
		lazyUpdate ( v * 2, l, min ( r, tm ), add );
		lazyUpdate ( v * 2 + 1, max ( l, tm + 1 ), r, add );
	}
}

int lazyGet ( int v, int pos ) {
	int tl = t[v].lr, tr = t[v].rr;
	if ( tl == tr )
		return t[v].data;
	int tm = ( tl + tr ) / 2;
	if ( pos <= tm )
		return t[v].data + lazyGet ( v * 2, pos );
	else
		return t[v].data + lazyGet ( v * 2 + 1, pos );
}


/*
struct SegmentNode {

	SegmentNode* left_node, * right_node;
	int left_range, right_range;
	NodeData data;

	SegmentNode ( vector<int>& v, int left_range, int right_range ) {
		this->left_range = left_range;
		this->right_range = right_range;

		if ( left_range == right_range ) {
			// data = v[left_range]; data for leaf
			return;
		}

		int mid = ( left_range + right_range ) / 2;
		left_node = new SegmentNode ( v, left_range, mid );
		right_node = new SegmentNode ( v, mid + 1, right_range );
		data = combineData ( left_node->data, right_node->data );
	}

	void updatePoint ( int pos, int val ) {
		if ( left_range == right_range ) { //leaf
			// data for leaf
			return;
		}
		if ( pos < right_node->left_range ) left_node->updatePoint ( pos, val );
		else right_node->updatePoint ( pos, val );
		data = combineData ( left_node->data, right_node->data );
	}

	void updateRange ( int l, int r, int l_pos ) { // update with adding val to all in (l,r)

		if ( r < left_range || right_range < l ) return;
		if ( l <= left_range && right_range <= r ) {
			/*data.lr_pos = ( l_pos + left_range - l );
			data.set = true;
			return;
		}

		//if ( data.set ) {
		//	left_node->data = right_node->data = data;
		//	right_node->data.lr_pos = data.lr_pos + right_node->left_range - left_node->left_range;
		//}
		//data.set = false;

		//int mid = ( l + r ) / 2;
		//if ( l <= left_node->right_range ) left_node->updateRange ( l, min ( r, left_node->right_range ), l_pos );
		//if ( r >= right_node->left_range ) right_node->updateRange ( max ( right_node->left_range, l ), r, l_pos + max ( right_node->left_range, l ) - l );
	}

	NodeData queryRange ( int l, int r ) {

		if ( r < left_range ) return NodeData ( );
		if ( l > right_range ) return NodeData ( );
		if ( left_range >= l && right_range <= r ) return data;

		return ( combineData ( left_node->queryRange ( l, r ), right_node->queryRange ( l, r ) ) );
	}

	NodeData combineData ( NodeData ldt, NodeData rdt ) {
		NodeData dt;
		return dt;
	}
};
**/

