// by jvpcms

/* Insert values in a binary serch tree data structure.
Keywords: Data Structures. */

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

    Node * insert(Node * root, int data) {
        
        if (root == NULL) return new Node(data);
        
        if (data < root->data)
        {
            if (root->left == NULL) root->left = new Node(data);
            else insert(root->left, data);
        }
        else {
        {
            if (root->right == NULL) root->right = new Node(data);
            else insert(root->right, data);
        }
        }

        return root;
    }

};

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
    myTree.preOrder(root);
  
    return 0;
}
