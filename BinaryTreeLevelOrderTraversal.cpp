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
        if ( !root ) 
            return levels;
        levelvisithelper(root,0);
        return levels;
    }

    void levelvisithelper( TreeNode * node, int level ) 
    {
        vector<int> temp;
        if ( levels.size() == level ) 
            levels.push_back(temp);
        levels[level].push_back(node->val);
        
        if ( node->left )
            levelvisithelper(node->left,level+1);
        if ( node->right )
            levelvisithelper(node->right,level+1);
    }
    
private:
    vector<vector<int>> levels;
    
};

// Iteration 
// O(n), O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        queue<TreeNode *> q{{root}};
        vector<int> curlevel;
        if ( !root ) 
            return levels;
        while( !q.empty() ) {
            curlevel.clear();
            for ( int i = q.size(); i > 0; i-- ) {
                TreeNode *t = q.front();
                q.pop();
                curlevel.push_back(t->val);
                if ( t->left ) 
                    q.push(t->left);
                if ( t->right )
                    q.push(t->right);
            }
            levels.push_back(curlevel);
        }
        return levels;   
    }
    
};