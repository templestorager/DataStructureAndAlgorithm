// Problem Description
/*
Given a binary search tree, return a balanced binary search tree with the same node values.

A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

If there is more than one answer, return any of them.
*/

// First perform an inorder traversal, then construct a balanced BST from the sorted array 
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode *> nodes;
        InorderTraversal( root, nodes );
        return ConstructBalBST( nodes, 0, nodes.size() - 1 );
    }
    
    TreeNode *ConstructBalBST( const vector<TreeNode *> &nodes, int l, int r ) 
    {
        if ( l > r ) 
            return NULL;
        int mid = (l+r)/2;
        TreeNode *root = nodes[mid];
        root->left = ConstructBalBST( nodes, l, mid - 1 );
        root->right = ConstructBalBST( nodes, mid+1, r );
        return root;
    }
    
    void InorderTraversal( TreeNode *root, vector<TreeNode *> &nodes ) 
    {
        if ( !root )
            return;
        InorderTraversal( root->left, nodes );
        nodes.push_back( root );
        InorderTraversal( root->right, nodes );
    }
};