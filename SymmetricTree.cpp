// Problem Description 
/*
 
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3

*/

// Recursive solution: 
// If two subtrees are symmetric to each other, their root values are equal and their left and right 
// subtrees are respectively symmetric, i.e, left vs right and right vs left.
// O(n), O(n) worst case 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelper(root,root);
    }
    bool isSymmetricHelper( TreeNode *left, TreeNode *right )
    {
        if ( !left && !right )
            return true;
        if ( !left || !right )
            return false;
        return (left->val == right->val && isSymmetricHelper(left->right,right->left) && isSymmetricHelper(left->left,right->right));
    }
};

// Idea: leverages a queue as a working stage to examine the nodes. 
// We push nodes into the queen such a way that two consecutive nodes are the same if the tree is symmetric
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        q.push(root);
        while( !q.empty() )
        {
            TreeNode *top1 = q.front();
            q.pop();
            TreeNode *top2 = q.front();
            q.pop();
            if ( !top1 && !top2 )
                continue;
            if ( (!top1 || !top2) || (top1->val != top2->val) )
                return false;
            q.push(top1->right);
            q.push(top2->left);
            q.push(top1->left);
            q.push(top2->right);
        }
        
        return true;
    }  
};