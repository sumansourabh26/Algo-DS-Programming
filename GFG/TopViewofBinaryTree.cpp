/*
* Author : SUMAN SOURABH
* EMAIL ID : sumansourabh26@gmail.com
* Problem :https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
*/
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    map<int,int> visible_node;
    queue<pair<Node*,int>> nodes_to_explore;
    vector<int> topView(Node *root)
    {
        nodes_to_explore.push({root,0});
        visible_node[0] = root->data;

        while(!nodes_to_explore.empty()){
            Node* n = nodes_to_explore.front().first;
            int level = nodes_to_explore.front().second;
            nodes_to_explore.pop();
            if(n->left!=NULL){
                int level_left = level-1;
                if(visible_node.find(level_left) == visible_node.end()){
                    visible_node[level_left] = n->left->data;
                    //cout<<n->left->data<<' '<<level_left<<endl;
                }
                nodes_to_explore.push({n->left, level_left});
            }
            if(n->right!=NULL){
                int level_right = level+1;
                if(visible_node.find(level_right) == visible_node.end()){
                    visible_node[level_right] = n->right->data;
                    //cout<<n->right->data<<' '<<level_right<<endl;
                }
                nodes_to_explore.push({n->right, level_right});
            }

        }
        vector<int> ans;
        for(auto itr = visible_node.begin(); itr != visible_node.end(); itr++){
            ans.push_back(itr->second);
        }
        return ans;

    }

};



//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends