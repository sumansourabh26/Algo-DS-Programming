/*
* Author : SUMAN SOURABH
* EMAIL ID : sumansourabh26@gmail.com
* Problem : https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(){
        data = 0;
        left = right = NULL;
    }
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* ans = NULL;

    void helper(Node* root ,int &n1 ,int& n2, bool& found_n1, bool& found_n2 ){
        if(root->left == NULL && root->right ==NULL){
            found_n1 = (root->data == n1)? true : false;
            found_n2 = (root->data == n2)? true : false;
            return;
        }
        bool l_fn1 = false, l_fn2 = false;
        if(root->left != NULL){
            helper(root->left, n1, n2, l_fn1, l_fn2);
        }
        if(l_fn1 && l_fn2) return;
        
        bool r_fn1 = false, r_fn2 = false;
        if(root->right != NULL){
            helper(root->right, n1, n2, r_fn1, r_fn2);
        }
        if(r_fn1 && r_fn2) return;

        bool n_fn1 = (root->data == n1)? true : false;
        bool n_fn2 = (root->data == n2)? true : false;
        found_n1 = (n_fn1 || l_fn1 || r_fn1) ;
        found_n2 = (n_fn2 || l_fn2 || r_fn2);
        if(found_n1 && found_n2){
            ans = root;
        }
        
    }

    Node* lca(Node* root ,int n1 ,int n2 )
    {
        bool found_n1, found_n2 ;
        helper(root ,n1 , n2, found_n1, found_n2 );
        return ans;

    }
};

//{ Driver Code Starts.

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.lca(root,a,b)->data<<endl;
    }
    return 0;
}

// } Driver Code Ends