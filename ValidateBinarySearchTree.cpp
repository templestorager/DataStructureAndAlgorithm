// Problem Description
/*
 
 Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

    Example 1:

      2
     / \
    1   3

    Input: [2,1,3]
    Output: true
    Example 2:

     5
    / \
   1   4
        / \
       3   6

    Input: [5,1,4,null,null,3,6]
    Output: false
    Explanation: The root node's value is 5 but its right child's value is 4.

 */

// It's kind of tricky to verify a valid BST. 
// Locally each node is larger than it's left child and smaller than right child is only a necessary condition 
// of it being a BST. We also need to ensure the value is larger than the max of the left child and smaller than 
// the min of the right child. To implement that, we keep track of the range that each node should fall into 
// Note: we use long type to avoid coner case overflow 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root,LONG_MIN,LONG_MAX);
    }
    
    bool isValidBSTHelper(TreeNode* root, long low, long upper )
    {
        if ( !root )
            return true;
        if ( root->val <= low || root->val >= upper ) return false;
        return isValidBSTHelper(root->left,low,root->val) && isValidBSTHelper(root->right,root->val, upper) ;
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        push_stacks( root, LONG_MIN, LONG_MAX );
        while ( !nodes.empty() )
        {
            TreeNode *tmp = nodes.top();
            nodes.pop();
            long lower = lowers.top();
            lowers.pop();
            long upper = uppers.top();
            uppers.pop();
            if ( tmp == NULL )
                continue;
            if ( tmp->val <= lower || tmp->val >= upper )
                return false;
            push_stacks( tmp->left, lower, tmp->val );
            push_stacks( tmp->right, tmp->val, upper );

        }
        
        return true;
    }
    
    void push_stacks( TreeNode * node, long lower, long upper )
    {
        nodes.push( node );
        lowers.push( lower );
        uppers.push( upper );
    }
    
private:
    stack<TreeNode *> nodes;
    stack<long> lowers;
    stack<long> uppers;
};

// We check the order of inorder traversal 
// O(n) O(n)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> inorderdata;
        inorderBST( inorderdata, root );

        for ( int i = 0; i < (int)inorderdata.size() - 1; i++ )
            if ( inorderdata[i] >= inorderdata[i+1] )
                return false;
        
        return true;
    }
    
    void inorderBST( vector<int> &in, TreeNode *root )
    {
        if ( root == NULL )
            return;
        inorderBST( in, root->left );
        in.push_back(root->val);
        inorderBST( in, root->right );
    }
};

// This method is essentially inorder traversal, but doesn't store the inorder output 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode *> s;
        TreeNode *cur = NULL, *prev = NULL;
        while ( root != NULL || !s.empty() )
        {
            while ( root )
            {
                s.push(root);
                root = root->left;
            }
            cur = s.top();
            s.pop();
            if ( prev && cur->val <= prev->val )
                return false;
            prev = cur;
            root = cur->right;
        }
        
        return true;
    }
    
};