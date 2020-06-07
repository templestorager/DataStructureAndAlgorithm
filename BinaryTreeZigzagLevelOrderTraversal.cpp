// Problem Description 
/*
 Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

// This solution performs regular level traversal. Then finally reverse the even number level 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> curlevel; 
        if ( root )
            curlevel.push(root);
        while ( !curlevel.empty() )
        {
            queue<TreeNode *> next;
            vector<int> cur;
            while (!curlevel.empty() )
            {
                TreeNode * tmp = curlevel.front();
                cur.push_back(tmp->val);
                curlevel.pop();
                if ( tmp->left )
                    next.push(tmp->left);
                if ( tmp->right )
                    next.push(tmp->right);
            }
            res.push_back(cur);
            curlevel = next;
        }
        
        for ( int i = 0; i < res.size(); i++ )
        {
            if ( i % 2 )
                reverse(res[i].begin(),res[i].end());
        }
        
        return res;
    }
};

// We can also use dfs to do level order traversal 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if ( !root )
            return res;
        DFS_helper(res,root,0);
        for ( int i = 0; i < res.size(); i++ )
            if ( i % 2 )
                reverse(res[i].begin(),res[i].end());
        return res;
    }
    
    void DFS_helper( vector<vector<int>> &res, TreeNode *node, int level )
    {
        if ( level == res.size() )
        {
            res.push_back(vector<int>());  // This is the first element in level@level
            res.back().push_back(node->val);
        }
        else 
        {
            res[level].push_back(node->val);
        }
        if ( node->left )
            DFS_helper(res,node->left,level+1);
        if ( node->right )
            DFS_helper(res,node->right,level+1);
    }
};