// Problem Description 
/*
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to 
 * right, level by level).

    For example:
    Given binary tree [3,9,20,null,null,15,7],
         3
        / \
        9  20
           /  \
          15   7
    return its level order traversal as:
    [
        [3],
        [9,20],
        [15,7]
    ]
 * 
 */
// Recursion 
// O(n), O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if ( !root )
            return res;
        LevelOrderHelper(res,root,0);
        return res;
    }
    
    void LevelOrderHelper( vector<vector<int> > &res, TreeNode *node, int level )
    {
        if ( res.size() == level )
            res.push_back(vector<int>{});
        res[level].push_back(node->val);
        if ( node->left )
            LevelOrderHelper(res,node->left,level+1);
        if ( node->right)
            LevelOrderHelper(res,node->right,level+1);
    }
};

// Iteration 
// O(n), O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> level;
        vector<vector<int> > res;
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while(!q.empty())
        {
            level.clear();
            queue<TreeNode *> tmp;
            while(!q.empty())
            {
                TreeNode *top = q.front();
                level.push_back(top->val);
                q.pop();
                if ( top->left )
                    tmp.push(top->left);
                if ( top->right )
                    tmp.push(top->right);
            }
            res.push_back(level);
            q = tmp;
        }
        return res;
    }
};