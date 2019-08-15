// Problem Description
/*
 * A binary tree is univalued if every node in the tree has the same value.
 * Return true if and only if the given tree is univalued.
 * 
 * 
 */

// hint: basically we traverse the true and if any node is not equal to the value
// it is a NON-univalued tree.
// O(n), O(h)
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {

        return helper(root,root->val);
    }
    
    bool helper( TreeNode *root, int val ) {
        if ( root == NULL ) 
            return true;
        if ( root->val != val ) 
            return false;
        return helper(root->left,val) && helper(root->right,val);
        
    }
};