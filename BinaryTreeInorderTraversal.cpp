// Problem Description
/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

// This is the trivial recusive solution 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs_helper( root, res );
        return res;
    }
    void dfs_helper( TreeNode *root, vector<int> &res )
    {
        if ( !root )
            return;
        dfs_helper( root->left, res);
        res.push_back(root->val);
        dfs_helper( root->right, res);
    }
};

// Iterative approach to inorder traversal, leveraging a stack to get left first and then backtrack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if ( !root )
            return res;
        stack<TreeNode *> s;
        while ( root || !s.empty() )
        {
            while ( root )
            {
                s.push(root);
                root = root->left;
            }
            
            res.push_back(s.top()->val);
            root = s.top()->right;
            s.pop();
        }
        
        return res;
    }
};

// This method is called Morris traversal, also known as threaded binary tree.
// Key idea is to use the right child of leaf nodes to point to their inorder successor. 
// When we first enter the left subtree, we connect the prev of the cur node 
// When we encounter the second time and find the right child is already set, then we are done with left 
// subtree and should move to process the cur ndoe and move to its right subtree.
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if ( !root )
            return res;
        TreeNode *cur = root, *prev = nullptr;
        while ( cur )
        {
            if ( !cur->left )
            {
                res.push_back(cur->val);
                cur = cur->right;
            }
            else 
            {
                prev = cur->left;
                while ( prev->right && prev->right != cur )
                    prev = prev->right;
                if ( !prev->right )
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else 
                {
                    prev->right = nullptr;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
