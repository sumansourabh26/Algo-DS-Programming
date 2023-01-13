/*
* Author : SUMAN SOURABH
* EMAIL ID - sumansourabh26@gmail.com
* Problem : https://leetcode.com/problems/binary-search-tree-iterator/description/
*/


#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    list<int> treeArr;
    list<int>::iterator n;


    void buildArr(TreeNode* root){
        if(root->left != NULL){
            buildArr(root->left);
        }
        treeArr.push_back(root->val);
        if(root->right != NULL){
            buildArr(root->right);
        }
    }

    BSTIterator(TreeNode* root) {
        buildArr(root);
        n = treeArr.begin();

    }
    
    int next() {
        int t = *n;
        n = (++n);
        return t;
    }
    
    bool hasNext() {
        // auto t = treeArr.end();
        // t--;
        return( n!=treeArr.end());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */