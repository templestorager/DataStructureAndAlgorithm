// Problem Description
/*
 Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
*/

// This straight solution consists of three steps: 
// 1. first obtain the inorder traversal 
// 2. find the elements which are swapped in the inorder results 
// 3. traverse the tree again and swap the values if they belong to the swapped values 
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        int x, y;
        InorderTraversalRecur(root,inorder);
        FindSwappedValue( inorder, x, y);
        InorderRecurFix( root,x, y);
    }
    
    void InorderRecurFix( TreeNode *root, const int x, const int y )
    {
        if ( !root )
            return;
        InorderRecurFix( root->left, x, y);
        if ( root->val == x || root->val == y )
        {
            root->val = root->val == x ? y : x;
        }
        InorderRecurFix( root->right, x, y);
    }
    
    void InorderTraversalRecur( TreeNode *root, vector<int> &nums )
    {
        if ( !root )
            return;
        InorderTraversalRecur(root->left,nums);
        nums.push_back(root->val);
        InorderTraversalRecur(root->right,nums);
    }
    
    void InorderTraversal(TreeNode *root, vector<int> &nums )
    {
        stack<TreeNode *> s;
        while ( !s.empty() || root )
        {
            while (root)
            {
                s.push(root);
                root = root->left;
            }
            TreeNode *tmp = s.top();
            nums.push_back(tmp->val);
            s.pop();
            root = tmp->right;
        }
    }
    
    void FindSwappedValue( const vector<int> &nums, int &x, int &y )
    {
        int idx1 = -1, idx2 = -1;

        for ( int i = 0; i < nums.size()-1; i++ )
        {
            if ( nums[i] > nums[i+1] )
            {
                idx1 = i;
                idx2 = i + 1;
                for ( int j = i+2; j < nums.size(); j++ )
                {
                    if ( nums[j] < nums[idx2] )
                    {
                        idx2 = j;
                    }
                }

            }
            if ( idx2 != -1 )
                break;
        }

        x = nums[idx1];
        y = nums[idx2];
    }
};