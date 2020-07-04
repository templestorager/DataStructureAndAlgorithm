// Problem Description
/*
Given the root of a binary search tree with distinct values, modify it so that every node has a new value equal to the sum of the values of the original tree that are greater than or equal to node.val.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 
*/

// Essentially, this asks to update the value of each node with the sum of itself and all nodes having larger values. 
// Therefore, we can perform an inorder and then update the value of each node with the sum starting from it to the end 
// O(n^2). 
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<TreeNode *> inorder;
        Inorder( root, inorder );
        for ( int i = 0; i < inorder.size(); i++ )
            for ( int j = i+1; j < inorder.size(); j++ )
            {
                inorder[i]->val += inorder[j]->val;
            }
        return root;
    }
    void Inorder(TreeNode *root, vector<TreeNode *> &inorder )
    {
        if( !root ) 
            return;
        Inorder( root->left, inorder );
        inorder.push_back( root );
        Inorder( root->right, inorder );
    }
};

// We can perform a reverse inorder traversal and maintain a sum of the from the largest down to the least 
// O(n), O(n)
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        ReverseInorder( root, sum );
        return root;
    }
    void ReverseInorder(TreeNode *root, int &sum )
    {
        if( !root ) 
            return;
        ReverseInorder( root->right, sum );
        root->val += sum;
        sum = root->val;
        ReverseInorder( root->left, sum );
    }
};