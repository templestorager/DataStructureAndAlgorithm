// Problem Description
/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

The successor of a node p is the node with the smallest key greater than p.val.

 

Example 1:


Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.
Example 2:


Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.
 

Note:

If the given node has no in-order successor in the tree, return null.
It's guaranteed that the values of the tree are unique.
*/

// There are two variants of this problem. 
// 1. Each node has an additional parent. 
// 2. The tree root is given, so we need to start traversing from the root 
// If the given node has a right child, then it's next is the minimum of its right subtree,
// i.e., the left-most child. 
// Otherwise, 
// In the first variant, the next node should be the first ancestor which itself is a left child of its parent 
// In the second variant, we start inorder traversing from root, the next is the next node visited after the given node. 
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if ( !root ) 
            return nullptr;
        if ( p->right ) 
        {
            p = p->right;
            while ( p->left )
                p = p->left;
            return p;
        }
        else 
        {
            // if we are given an additional parent in each node 
            #if 0
            TreeNode *grand = p->parent;
            while ( grand && p == grand->right )
            {
                p = grand;
                grand = grand->parent;
            }
            #endif 
            stack<TreeNode *> s;
            bool seen = false;
            while( !s.empty() || root )
            {
                while(root)
                {
                    s.push(root);
                    root = root->left;
                }
                root = s.top();
                s.pop();
                if ( seen )
                    return root;
                if ( root == p )
                    seen = true;
                root = root->right;
            }
            
            return nullptr;
        }
    }
};

// This solution emulates the traversal of the BST, leveraging the properties of BST 
// It update the succ as it traverses 
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
            TreeNode *succ = nullptr;
            while ( root )
            {
                if ( root->val > p->val )
                {
                    succ = root;
                    root = root->left;
                }
                else 
                {
                    root = root->right;
                }
            }
        
            return succ;
        }
};

// This is the recursive version of the above solution 
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if ( !root )
            return nullptr;
        if ( root->val <= p->val )
            return inorderSuccessor(root->right,p);
        else 
        {
            TreeNode *left = inorderSuccessor(root->left, p);
            return left ? left : root;
        }
    }
};

// This solution uses recursive inorder traversal to find the successor. 
// while recursing, it records the prev and if at any point time, if the 
// prev is set (i.e., each to p), then the current node is the succ of p
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if ( !root )
            return nullptr;
        inorder(root,p);
        return succ;
    }
    void inorder(TreeNode *root, TreeNode *p )
    {
        if ( !root )
            return;
        inorder(root->left,p);
        if ( pre == p ) 
            succ = root;
        pre = root;
        inorder(root->right,p);      
    }
private:
    TreeNode *pre = nullptr, *succ = nullptr;
};