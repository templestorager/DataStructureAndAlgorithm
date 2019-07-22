// Problem Description 
/* 
 * Given a root node reference of a BST and a key, delete the node with the given key in the BST.
 * Return the root node reference (possibly updated) of the BST.
 * 
 * Basically, the deletion can be divided into two stages:
 * Search for a node to remove.
 * If the node is found, delete the node.
 * Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7

 * 
 * 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// The key is to find the node to replace to node-to-be-deleted. 
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if ( !root ) 
            return NULL;
        if ( key > root->val ) 
            root->right = deleteNode(root->right,key);
        else if ( key < root->val ) 
            root->left = deleteNode(root->left,key);
        else {
            if ( root->left == NULL && root->right == NULL ) {
                root = NULL;
            } 
            else if ( root->right ) {
                root->val = successor(root); 
                root->right = deleteNode(root->right,root->val);
            }else  {
                root->val = predecessor(root);
                root->left = deleteNode(root->left,root->val);
            }
        }
        return root;
    }

    int successor(TreeNode * root) {
        root = root->right;
        while( root->left ) 
            root = root->left;
        return root->val;
    }
    
    int predecessor(TreeNode *root) {
        root = root->left;
        while ( root->right ) 
            root = root->right;
        return root->val;
    }
};