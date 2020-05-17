// Problem Description
/*
 Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
*/

// The trivial solution will be using recursion, i.e., the maxdepth of any node is the max of it's left and right, plus one (the node itself)
// O(n), O(n) worst or O(lgn) best
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if ( root == NULL )
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left,right) + 1;
    }
};

// The following solution leverages the simplified level order traversal in that we don't need to maintain 
// the elements in each level 
// O(n), O(maxelment in any level) 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        queue<TreeNode *> q;
        if ( !root )
            return maxDepth;
        q.push( root );
        while (!q.empty() )
        {
            for ( int i = q.size(); i > 0; i-- )
            {
                TreeNode *tmp = q.front();
                q.pop();
                if ( tmp->left )
                    q.push(tmp->left);
                if ( tmp->right )
                    q.push(tmp->right);
            }
            maxDepth++;
        }
        
        return maxDepth;
    }
};

// we can also use a stack to emulate the procedue of the traversing down the tree, while maintaining the 
// max depth of the binary tree
// for each node, it's height is equal to its parent's height plus one 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        if ( !root )
            return 0;
        stack<pair<TreeNode*,int> > s;
        s.push(pair<TreeNode*,int>(root,1));
        while(!s.empty())
        {
            auto node = s.top();
            s.pop();
            maxDepth = max(maxDepth, node.second);
            if ( node.first->left )
                s.push(pair<TreeNode *, int>(node.first->left,node.second+1));
            if ( node.first->right )
                s.push(pair<TreeNode *,int>(node.first->right,node.second+1));
        }
        
        return maxDepth;
    }
};