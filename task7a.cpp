#include <iostream>
#include <algorithm>

using namespace std;
//this is a test
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};

class BinaryTree {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) { // If root is NULL, return 0
            return 0;
        } else {
        	// Recursively find the maximum depth of the left subtree
            int left_depth = maxDepth(root->left);
            // Recursively find the maximum depth of the right subtree
            int right_depth = maxDepth(root->right); 
            // Return the maximum depth of the subtree + 1 (for the current node)
            return max(left_depth, right_depth) + 1; 
        }
    }
};

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(3); 
    root->left = new TreeNode(9); 
    root->right = new TreeNode(20); 
    root->right->left = new TreeNode(15); 
    root->right->right = new TreeNode(7); 
     // Create a BinaryTree object obj
    BinaryTree obj;
     // Print the maximum depth of the binary tree
    cout << "The maximum depth of the binary tree is: " << obj.maxDepth(root) << endl;

    return 0;
}
