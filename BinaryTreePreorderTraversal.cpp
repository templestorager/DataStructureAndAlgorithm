// Problem Description 
/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

// This is the trivial recursive solution 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs_preorder(root,res);
        return res;
    }
    void dfs_preorder( TreeNode *root, vector<int> &res )
    {
        if ( !root )
            return ;
        res.push_back(root->val);
        dfs_preorder( root->left,res);
        dfs_preorder( root->right, res);
    }
};

// This is the iteration solution using a stack 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if ( !root )
            return res;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *cur = s.top();
            res.push_back(cur->val);
            s.pop();
            if ( cur->right )
                s.push(cur->right);
            if ( cur->left )
                s.push(cur->left);
        }
        
        return res;
    }
};

// Same idea, but written in a different manner.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if ( !root )
            return res;
        stack<TreeNode *> s;
        TreeNode * p = root;
        while ( p || !s.empty() )
        {
            if ( p ) 
            {
                s.push(p);
                res.push_back(p->val);
                p = p->left;
            }
            else 
            {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        
        return res;
    }
};


// Morris preorder traversal 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
                    res.push_back(cur->val);
                    prev->right = cur;
                    cur = cur->left;
                }
                else 
                {
                    prev->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        
        return res;
    }
};