#pragma once
#include <iostream>
#include <vector>
#include <fstream> 
#include <iterator>
#define COUNT 10

using namespace std;
ifstream fin;
ofstream fout;

void setupIO ( ) {
	fin.open ( "myfile.txt", ios::in );    // open the streams
	fout.open ( "outfile.txt", ios::out );
}

struct RedBlackTreeNode {
	bool isBlack, isSentinel;
	RedBlackTreeNode* l, * r;
	int val;

	RedBlackTreeNode ( ) {
		isBlack = true;
		isSentinel = true;
		l = r = NULL;
		val = 0;
	}
	RedBlackTreeNode ( int v ) {
		isSentinel = isBlack = false;
		val = v;
		r = l = &sentinel_node;
	}
	void insert ( int v ) {
		this;
		if ( v < val ) {
			if ( l->isSentinel ) l = new RedBlackTreeNode ( v );
			else l->insert ( v );
		} else {
			if ( r->isSentinel ) r = new RedBlackTreeNode ( v );
			else r->insert ( v );
		}
	}
}sentinel_node;

void print2DUtil ( RedBlackTreeNode* root, int space ) { // call with 0
	if ( root == NULL )
		return;
	space += COUNT;
	print2DUtil ( root->r, space );
	fout << endl;
	for ( int i = COUNT; i < space; i++ )fout << " ";
	fout << root->val<<"/"<< ((root->isBlack )?"B":"R" )<< "\n";
	print2DUtil ( root->l, space );
}

void run ( ) {
	sentinel_node = *( new RedBlackTreeNode ( ) );
	int length;
	fin >> length;

	RedBlackTreeNode* root = new RedBlackTreeNode ( 200 );
	root->isBlack = true;
	for ( size_t i = 0; i < length; i++ ) {
		int temp; fin >> temp;
		root->insert ( temp );	
		
	}
	print2DUtil ( root, 0 );
	int x = 0;

}


