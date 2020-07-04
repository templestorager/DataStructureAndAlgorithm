// Problem Description
/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
Example:

Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

Output: 4
*/

// We can remember the closet value while traversing the tree. 
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int closest_val = root->val;
        while ( root )
        {
            closest_val = abs(root->val-target) < abs(closest_val-target) ? root->val : closest_val;
            root = target < root->val ? root->left : root->right;
        }
        
        return closest_val;
    }
};

// Use stack to travese the tree and make comparisons as we tranverse and stop once found. 
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int closest_val = root->val;
        long prev = LONG_MIN;
        stack<TreeNode *> s;
        while ( root || !s.empty() )
        {
            while ( root )
            {
                s.push(root);
                root = root->left;
            }
            TreeNode *top = s.top();
            s.pop();
            if ( prev <= target && top->val > target)
            {
                if ( abs(target - top->val) <= abs(target - prev ) )
                {
                    closest_val = top->val;
                }
                else 
                {
                    closest_val = prev;
                }
                return closest_val;
            }
            prev  = top->val;
            root  = top->right;
        }
        
        return (int)prev;
    }
};

// We can also perform an inorder traversal on the tree and then find the target in the sorted array 
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        vector<int> inorder;
        int closest_val = root->val;
        Inorder(root,inorder);
        if ( target <= inorder[0] )
            return inorder[0];
        if ( target >= inorder[inorder.size()-1] )
            return inorder[inorder.size()-1];
        for ( int i = 0; i < inorder.size() - 1; i++ )
        {
            if ( target >= inorder[i] && target <= inorder[i+1] )
            {
             closest_val = abs(target - inorder[i]) > abs(target-inorder[i+1] ) ? inorder[i+1] : inorder[i];
            }
        }
        
        return closest_val;
    }
    
    void Inorder( TreeNode *root, vector<int> &inorder )
    {
        if ( !root ) 
            return;
        Inorder( root->left, inorder );
        inorder.push_back( root->val );
        Inorder( root->right, inorder );
    }
};