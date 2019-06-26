// Problem description 
/* 
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// This solution is based on depth first search algorithm (DFS)
// During DFS, we construct a mapping structure which maps the value to 
// a pair consisting of it's parent and its height. 
// After obtaining this structure, we just need to compare the associated pairs of the 
// two values, i.e., father should NOT be the same and height should be the same 

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        map.clear();
        dfs(root,NULL,0);
        auto Px = map[x], Py = map[y];
        return Px.first != Py.first && Px.second == Py.second; 
    }
private: 
    unordered_map<int, pair<TreeNode*, int > > map; 
    void dfs( TreeNode * root, TreeNode *father, int height ) {
        if ( !root ) 
            return ;
        map[root->val] = make_pair(father,height);
        dfs(root->left, root, height + 1);
        dfs(root->right, root, height + 1 );
    }
};


// this solution use bread-first-search to avoid calling recursive functions 
// 

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push(make_pair(root,nullptr));
        unordered_map<int,pair<TreeNode*, int>> map;
        int height = 0;
        while ( !q.empty() ) {
            int queuesize = q.size();
            for ( int i = 0; i < queuesize; i++ ) {
                auto p = q.front();
                q.pop();
                if  ( !p.first ) 
                    continue;
                map[p.first->val] = make_pair(p.second, height);
                q.push(make_pair(p.first->left, p.first));
                q.push(make_pair(p.first->right,p.first));
            }
            height++;
        }
        auto Px = map[x], Py = map[y];
        return Px.first != Py.first && Px.second == Py.second;
    }

};