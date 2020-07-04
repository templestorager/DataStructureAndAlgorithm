// Problem Description
/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
 

Example 2:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
*/

// We can use recursion to check, as we check a current node, we ask whether it's complementary sum has been seen before 
// If so, then there is a combination that satifies the sum condition.
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return findTargetHelper( root, k, s);
    }
    bool findTargetHelper( TreeNode *root, int sum, unordered_set<int> &s )
    {
        if ( !root )
            return false;
        if ( s.find(sum-root->val) != s.end() )
            return true;
        s.insert( root->val );
        return findTargetHelper( root->left, sum, s ) || findTargetHelper( root->right, sum, s );
    }
};

// Similar to the recursion idea, we can embed the check process in the level traversal procedure 
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        queue<TreeNode *> q;
        if ( !root ) 
            return false;
        q.push( root );
        while ( !q.empty() ) 
        {
            int queue_sz = q.size();
            for ( int i = 0; i < queue_sz; i++ )
            {
                TreeNode *t = q.front();
                q.pop();
                if ( s.find(k- t->val) != s.end() ) 
                    return true;
                s.insert( t->val );
                if ( t->left ) 
                    q.push( t->left );
                if ( t->right )
                    q.push( t->right );
            }
        }
        return false;
    }
};


// Finally, we can perform an inorder traveral to get the sorted array and use two pointers to find the sum 
// as in the regular two sum problem. 
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> data;
        InorderTraversal( root, data );
        int l = 0, h = data.size() - 1;
        while ( l < h )
        {
            if ( data[l] + data[h] == k ) 
                return true;
            if ( data[l] + data[h] < k )
                l++;
            else 
                h--;
        }
        return false;
    }
    
    void InorderTraversal( TreeNode * root, vector<int> &data ) 
    {
        if ( root == nullptr ) 
            return;
        InorderTraversal( root->left, data );
        data.push_back( root->val );
        InorderTraversal( root->right, data );
    }
};

