// Problem Description
/*
Given two binary search trees, return True if and only if there is a node in the first tree and a node in the second tree whose values sum up to a given integer target.

 

Example 1:



Input: root1 = [2,1,4], root2 = [1,0,3], target = 5
Output: true
Explanation: 2 and 3 sum up to 5.
Example 2:



Input: root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
Output: false
*/

// We use traversal to find the data set in the two trees respectively. 
// The only difference is that we only include unique data in the set, becuase it require "if and only if one pair"
class Solution {
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> t1, t2;
        GetBstData( root1, t1 );
        GetBstData( root2, t2 );
        for ( auto it : t1 )
            if ( t2.count(target - it) )
                return true;
        return false;
    }
    
    void GetBstData( TreeNode * root, unordered_set<int> &data )
    {
        if ( !root )
            return ;
        if ( data.count(root->val) == 0 )
            data.insert( root->val );
        GetBstData( root->left, data );
        GetBstData( root->right, data );
    }
};