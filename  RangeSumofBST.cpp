// Problem Description 
/*
 * Given the root node of a binary search tree, return the sum of values of all nodes with value 
 * between L and R (inclusive).

    The binary search tree is guaranteed to have unique values.

    Example 1:

    Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
    Output: 32
    Example 2:

    Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
    Output: 23
 * 
 */

// Inorder traversal 
// O(n), O(h)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        rangeSumBSTHelper(root,L,R,sum);
        return sum;
    }
    
    void rangeSumBSTHelper( TreeNode *root, int L, int R, int &sum ) {
        if ( !root )
            return;
        if ( root->val <= R && root->val >= L ) {
            sum += root->val;
        }
        if ( L < root->val ) 
            rangeSumBSTHelper(root->left,L,R,sum);
        if ( R > root->val )
            rangeSumBSTHelper(root->right,L,R,sum);
    }
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0; 
        stack<TreeNode *> s;
        s.push(root);
        while ( !s.empty() ) {
            TreeNode *node = s.top();
            s.pop();
            if ( node != NULL ) {
                if ( L <= node->val && node->val <= R ) {
                    sum += node->val;
                }
                if ( L < node->val ) 
                    s.push(node->left);
                if ( node->val < R ) 
                    s.push(node->right);
            }
        }
        return sum;
    }
};