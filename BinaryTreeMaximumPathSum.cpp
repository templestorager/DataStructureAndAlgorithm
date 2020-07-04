// Problem Description
/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        Helper(root,res);
        return res;
    }
    
    int Helper( TreeNode * root, int &res )
    {
        if ( !root )
            return 0;
        int left = max(Helper(root->left,res),0);
        int right = max(Helper(root->right,res),0);
        res = max(res, left+right+root->val);
        return root->val + max(left,right);
    }
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        NodeGain(root,mx);
        return mx;
    } 
    
    // This function returns the maximum contribution a node can make and update the max parameter is this a new maximum is formulated 
    int NodeGain( TreeNode *root, int &mx )
    {
        if ( !root )
        {
            return 0;
        }
        if ( !root->left && !root->right )
        {
            mx = max(mx,root->val);
            return root->val;
        }
        int left_max = max(NodeGain(root->left, mx), 0);
        int right_max = max(NodeGain(root->right,mx),0);
        mx = max( left_max+right_max + root->val, mx );
        return max(left_max,right_max) + root->val;
            
    }
};