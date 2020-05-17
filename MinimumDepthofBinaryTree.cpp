// Problem Description
/*
 Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.
*/


// This solution also leverages the level order traversal of a binary tree 
// The difference from the maximum depth is that it terminates whenever we encounter a node having node children 
// while the max depth terminates only when the a level has no nodes. 

class Solution {
public:
    int minDepth(TreeNode* root) {
        int minDepth = 1;
        if ( !root )
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty() )
        {
            for ( int i = q.size(); i > 0; i-- )
            {
                TreeNode *node = q.front();
                q.pop();
                if ( !node->left && !node->right )
                    return minDepth;
                if ( node->left )
                    q.push(node->left);
                if ( node->right )
                    q.push(node->right);
            }
            minDepth++;
        }
        
        return minDepth;
    }
};

// Use recursion
class Solution {
public:
    int minDepth(TreeNode* root) {

        if ( !root )
            return 0;
        if ( !root->left ) 
            return minDepth(root->right) + 1;
        if ( !root->right )
            return minDepth(root->left) + 1;
        return min(minDepth(root->left),minDepth(root->right)) + 1;
        
    }
};

// recursion can also be written like this 
class Solution {
public:
    int minDepth(TreeNode* root) {
        int minres = INT_MAX;
        if ( !root )
            return 0;
        if ( !root->left && !root->right ) 
            return 1;
        if ( root->left )
            minres = min( minres, minDepth(root->left) );
        if ( root->right )
            minres = min( minres, minDepth(root->right) );
        return minres+1;
    }
};

// We can record the depth of each node and only update the min for leaf nodes, 
// while to find maxdepth, we update for every nodes. 
class Solution {
public:
    int minDepth(TreeNode* root) {
        if ( !root )
            return 0;
        stack<pair<TreeNode*,int> > s;
        int mindepth = INT_MAX;
        s.push(pair<TreeNode *, int>(root,1));
        while ( !s.empty() )
        {
            auto node = s.top();
            s.pop();
            if ( !node.first->left && !node.first->right )
            {
                mindepth = min( mindepth, node.second );
            }
            if ( node.first->left )
                s.push(pair<TreeNode*,int>(node.first->left,node.second+1));
            if ( node.first->right )
                s.push(pair<TreeNode*,int>(node.first->right,node.second+1));
        }
        
        return mindepth;
        
    }
};