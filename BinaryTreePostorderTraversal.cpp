// Problem Description 
/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

// This is the trivial recursion solution.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs_postorder(root,res);
        return res;
    }
    
    void dfs_postorder( TreeNode *root, vector<int> &res )
    {
        if ( !root )
            return ;
        dfs_postorder( root->left, res);
        dfs_postorder( root->right, res);
        res.push_back(root->val);
    }
};

// This is a tricky solution by tweaking the traversal of preorder 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> s;
        if ( !root )
            return res;
        s.push(root);
        while ( !s.empty() )
        {
            TreeNode *cur = s.top();
            s.pop();
            res.insert(res.begin(),cur->val);
            if ( cur->left )
                s.push(cur->left);
            if ( cur->right )
                s.push(cur->right);
        }
        return res;
    }
};

// We only can process the cur node if it is a leaf node or both its childen have been processed 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *prev = root;
        if ( !root )
            return res;
        s.push(root);
        while ( !s.empty() )
        {
            TreeNode *cur = s.top();
            if ( (!cur->left && !cur->right) || cur->left == prev || cur->right == prev )
            {
                res.push_back(cur->val);
                s.pop();
                prev = cur;
            }
            else 
            {
                if ( cur->right )
                    s.push(cur->right);
                if ( cur->left )
                    s.push(cur->left);
            }
        }
        
        return res;
    }
};