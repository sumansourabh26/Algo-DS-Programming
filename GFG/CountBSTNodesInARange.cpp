/*
* Author : SUMAN SOURABH
* EMAIL ID : sumansourabh26@gmail.com
* Problem : https://practice.geeksforgeeks.org/problems/largest-bst/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
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
//Function to count number of nodes in BST that lie in the given range.
class Solution{
public:
    int getCount(Node *root, int l, int h){
        cout<<"under:"<<root->data<<':'<<l<<' '<<h<<endl;
        if(root->left == NULL && root->right == NULL){
            int total = (l<= root->data && root->data <= h)? 1 : 0;
            cout<<total<<endl;
            return (total);
        }
        int lc = 0, rc = 0;
        if(root->data<=l) rc = 0;
        
        (root->left != NULL)? (getCount(root->left, max(l,root->left->data), root->data)):0;
        int rc = (root->right != NULL)? (getCount(root->right, root->data, min(h,root->right->data))):0;
        int total = (lc+rc+((l<= root->data && root->data <= h)? 1 : 0));
        cout<<total<<endl;
        return total;
    }
};


//{ Driver Code Starts.

int main()
{
	
	int t;
	scanf("%d ", &t);
	while (t--)
	{
		string s;
		getline(cin >> ws, s);
		int l, r;
		cin >> l >> r;
		Solution ob;
		Node* root = buildTree(s);
		cout << ob.getCount(root, l, r) << endl;
		
	}
	return 0;
}

// } Driver Code Ends