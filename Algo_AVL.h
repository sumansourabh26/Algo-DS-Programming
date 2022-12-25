#pragma once
#pragma once
//https://www.hackerrank.com/challenges/self-balancing-tree/problem?isFullScreen=false
#include <iostream>
#include <vector>
#include <fstream> 
#include <cmath>
#include <stack>
#define COUNT 10

using namespace std;


struct node {
    int data, ht;
    struct node* left;
    struct node* right;

};

node* clockRotate(node** root) {
    node* n1 = *root, * n2_left = (*root)->left, * na = (*root)->right, * nb = (*root)->left->right, * nc = (*root)->left->left;
    int n1data = n1->data, n2data = n2_left->data;
    (*root)->data = n2data;

    (*root)->left = nc;
    (*root)->right = new node();
    (*root)->right->data = n1data;
    (*root)->right->right = na;
    (*root)->right->left = nb;
    (*root)->right->ht = (max(na->ht, nb->ht) + 1);

    (*root)->ht = 1 + max((*root)->left->ht, (*root)->right->ht);
    return *root;
}
node* antiRotate(node** root) {
    node* n1 = *root, * n2_right = (*root)->right, * na = (*root)->left, * nb = (*root)->right->left, * nc = (*root)->right->right;
    int n1data = n1->data, n2data = n2_right->data;
    (*root)->data = n2data;

    (*root)->right = nc;
    (*root)->left = new node();
    (*root)->left->data = n1data;
    (*root)->left->left = na;
    (*root)->left->right = nb;
    (*root)->left->ht = (max(na->ht, nb->ht) + 1);

    (*root)->ht = 1 + max((*root)->left->ht, (*root)->right->ht);

    return *root;
}

void insertReturnHeight(node* root, int data) {
    if (root->ht == -1) {
        root->data = data;
        root->ht = 0;
        node* left = new node(), * right = new node();;
        left->ht = -1;
        right->ht = -1;
        root->left = left;
        root->right = right;
    }
    else {

        if (root->data > data) {
            insertReturnHeight(root->left, data);
            root->ht = max(root->right->ht, root->left->ht) + 1;
            if ((root->left->ht - root->right->ht) > 1) {
                if (root->left->right->ht > root->left->left->ht) antiRotate(&(root->left));
                clockRotate(&root);

            }
        }
        else {
            insertReturnHeight(root->right, data);
            root->ht = max(root->right->ht, root->left->ht) + 1;
            if ((root->right->ht - root->left->ht) > 1) {
                if (root->right->right->ht < root->right->left->ht) clockRotate(&(root->right));
                antiRotate(&root);
            }
        }

    }
}

node* insert(node* root, int data) {
    insertReturnHeight(root, data);
    return root;
}

void print2DUtil(node* root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space);
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
    print2DUtil(root->left, space);
}

void print2D(node* root)
{
    print2DUtil(root, 0);
}
void printBF1(node* root) {
    if (root->ht == -1) return;
    printBF1(root->left);
    cout << root->data << "(BF=" << root->left->ht - root->right->ht << ") ";
    printBF1(root->right);
}
void printBF2(node* root) {
    if (root->ht == -1) return;
    cout << root->data << "(BF=" << root->left->ht - root->right->ht << ") ";
    printBF2(root->left);
    printBF2(root->right);
}

void run() {

    node* root = new node();
    root->ht = -1;
    int i, data; cin >> i;

    while (i--) {
        cin >> data;
        insert(root, data);
    }
    print2D ( root );
}
