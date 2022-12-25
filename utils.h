#pragma once

#include <iostream>
#include <vector>
#include <fstream> 
#include <iterator>
#include <cmath>
#include <deque>
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

//Sieve of Eratosthenes
int first_pf[MaxN]; // i index -> the first prime factor of i. used for prime factorisation
bool is_prime[MaxN];
void primeList ( int n ) {

    memset ( is_prime, true, sizeof ( is_prime ) );
    is_prime[0] = is_prime[1] = false;
    is_prime[2] = true; first_pf[2] = 2;

    for ( int i = 4; i <= n; i = i + 2 ) {
        is_prime[i] = false;
        first_pf[i] = 2;
    }
    for ( int i = 3; i <= n; i = i + 2 ) {
        if ( is_prime[i] ) {
            first_pf[i] = i;
            for ( ll j = ( ll ) i * i; j <= n; j += i ) {
                is_prime[j] = false;
                first_pf[j] = i;
            }
        }
    }
}
// end of Sieve of Eratosthenes


ll pow_mod ( int i, int pow ) {
	if ( pow == 1 ) return i;
	long long temp = pow_mod ( i, pow / 2 );
	temp = ( temp * temp ) % MOD;
	if ( pow % 2 ) temp = ( temp * i ) % MOD;
	return ( temp );
}

ll xorUpto ( ll N ) {
	ll ans;
	switch ( N % 4 ) {
		case 0: ans = N; break;
		case 1: ans = 1; break;
		case 2: ans = N + 1; break;
		case 3: ans = 0; break;
	}
	return ans;

}

// sliding window max
deque<int> window;
vector<int> helper ( vi& arr, int size, int ws ) {
    window.clear ( );
    vi ans;

    int i = 0;
    for ( ; i < ws; i++ ) {
        while ( ( !window.empty ( ) ) && arr[i] >= arr[window.back ( )] )
            window.pop_back ( );
        window.push_back ( i );
    }

    for ( ; i < size; i++ ) {
        ans.push_back ( arr[window.front ( )] );
        while ( ( !window.empty ( ) ) && ( i - window.front ( ) >= ws ) )
            window.pop_front ( );  
        while ( ( !window.empty ( ) ) && arr[i] >= arr[window.back ( )] )
            window.pop_back ( );
        window.push_back ( i );
    }
    ans.push_back ( arr[window.front ( )] );
    return ans;
}

// end sliding window

struct Node {
	int data, ht;
	struct Node* left;
	struct Node* right;
    Node ( ) {
        left = NULL;
        right = NULL;
        ht = 0;
    }
    Node ( int d ) {
        data = d;
        left = NULL;
        right = NULL;
        ht = 0;
    }

};


void print2DUtil ( Node* root, int space ) {
	if ( root == NULL )
		return;
	space += 10; // #define COUNT 10
	print2DUtil ( root->right, space );
	cout << endl;
	for ( int i = 10; i < space; i++ )
		cout << " ";
	cout << root->data << "\n";
	print2DUtil ( root->left, space );
}

void print2D ( Node* root ) {
	print2DUtil ( root, 0 );
}


///// AVL TREE ///////
void clockRotate ( Node** root ) {
    Node* n1 = *root, * n2_left = ( *root )->left, * na = ( *root )->right, * nb = ( *root )->left->right, * nc = ( *root )->left->left;
    int n1data = n1->data, n2data = n2_left->data;
    ( *root )->data = n2data;

    ( *root )->left = nc;
    ( *root )->right = new Node ( );
    ( *root )->right->data = n1data;
    ( *root )->right->right = na;
    ( *root )->right->left = nb;
    ( *root )->right->ht = ( max ( na->ht, nb->ht ) + 1 );

    ( *root )->ht = 1 + max ( ( *root )->left->ht, ( *root )->right->ht );
    //return *root;
}
void antiRotate ( Node** root ) {
    Node* n1 = *root, * n2_right = ( *root )->right, * na = ( *root )->left, * nb = ( *root )->right->left, * nc = ( *root )->right->right;
    int n1data = n1->data, n2data = n2_right->data;
    ( *root )->data = n2data;

    ( *root )->right = nc;
    ( *root )->left = new Node ( );
    ( *root )->left->data = n1data;
    ( *root )->left->left = na;
    ( *root )->left->right = nb;
    ( *root )->left->ht = ( max ( na->ht, nb->ht ) + 1 );

    ( *root )->ht = 1 + max ( ( *root )->left->ht, ( *root )->right->ht );

    //return *root;
}

void insertReturnHeight ( Node* root, int data ) {
    if ( root->ht == -1 ) {
        root->data = data;
        root->ht = 0;
        Node* left = new Node ( ), * right = new Node ( );;
        left->ht = -1;
        right->ht = -1;
        root->left = left;
        root->right = right;
    } else {

        if ( root->data > data ) {
            insertReturnHeight ( root->left, data );
            root->ht = max ( root->right->ht, root->left->ht ) + 1;
            if ( ( root->left->ht - root->right->ht ) > 1 ) {
                if ( root->left->right->ht > root->left->left->ht ) antiRotate ( &( root->left ) );
                clockRotate ( &root );

            }
        } else {
            insertReturnHeight ( root->right, data );
            root->ht = max ( root->right->ht, root->left->ht ) + 1;
            if ( ( root->right->ht - root->left->ht ) > 1 ) {
                if ( root->right->right->ht < root->right->left->ht ) clockRotate ( &( root->right ) );
                antiRotate ( &root );
            }
        }

    }
}

Node* insert ( Node* root, int data ) {
    insertReturnHeight ( root, data );
    return root;
}

///end ///// AVL TREE ///////