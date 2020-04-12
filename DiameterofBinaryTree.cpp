// Problem Description
/*
 Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/

// The idea is just to calculate the depth of its two childen (L,R)
// then the result would be (L+R+1)
// The trick is to compare the diameter of each and every node, which we can track while recursively traversing.

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        depth(root,res);
        return res;
    }
    
    int depth( TreeNode * root, int &res )
    {
        if ( root == NULL )
            return 0;
        int L = depth(root->left,res);
        int R = depth(root->right,res);
        res = max(res,L+R);
        
        return max(L,R) + 1;
    }
};

// Add an optimization to the above method to avoid duplicate calculation 
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        depth(root,res);
        return res;
    }
    
    int depth( TreeNode * root, int &res )
    {
        if ( root == NULL )
            return 0;
        if ( m.count(root) )
            return m[root];
        int L = depth(root->left,res);
        int R = depth(root->right,res);
        res = max(res,L+R);
        m[root] = res;
        return max(L,R) + 1;
    }
private:
    unordered_map<TreeNode *, int> m;
};

// Remember the height of the nodes to avoid duplicate computing 
// Since the height of a leaf node includes is 1, the height of any node then already includes the edge (path) 
// to it's parent. So the diameter of a node is then just the sum of the heights of its children
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if ( root == NULL) 
            return 0;
        int res = GetHeight(root->left) + GetHeight(root->right); 
        return max(res,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
    
    int GetHeight( TreeNode *node )
    {
        if ( node == NULL )
            return 0;
        if ( h_map.count(node) )
            return h_map[node];
        int h = 1+max(GetHeight(node->left),GetHeight(node->right));
        return h_map[node] = h;
    }
    
private:
    unordered_map<TreeNode *, int> h_map;
    
};