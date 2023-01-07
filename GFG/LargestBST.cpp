/*
* Author : SUMAN SOURABH
* EMAIL ID : sumansourabh26@gmail.com
* Problem : https://practice.geeksforgeeks.org/problems/largest-bst/1
*/
//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int maxBST = INT_MIN;
    bool largestBstHelper(Node *root, int& minV, int& maxV, int &bstsize){

        if(root->right == NULL && root->left == NULL){        
            bstsize = 1;
            maxBST = max(maxBST, bstsize);
            minV = maxV = root->data;
            return true;
        }

        int l_bstsize = 0, l_minV = root->data, l_maxv;
        bool leftAns = true;
        if(root->left != NULL){            
            leftAns = largestBstHelper(root->left, l_minV, l_maxv, l_bstsize);
            leftAns = leftAns && ( l_maxv < root->data); 
        }
        int r_bstsize = 0, r_minV = root->data, r_maxv = root->data;
        bool rightAns = true;
        if(root->right != NULL){
            rightAns = largestBstHelper(root->right, r_minV, r_maxv, r_bstsize);
            rightAns = rightAns && ( root->data < r_minV ) ; 
           
        }
        maxV = r_maxv;
        minV = l_minV;
        
        if(rightAns && leftAns) {
            bstsize = l_bstsize+r_bstsize+1;
            maxBST = max(maxBST, bstsize);
            return true;
        }else{
            return false;
        }

    }

    int largestBst(Node *root)
    {
        int v1, v2, v3;
    	largestBstHelper(root, v1, v2, v3 );
        return maxBST;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends

