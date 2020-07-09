// Problem Description 
/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
*/

// Note: this problem in a binary tree not BST, so cann't leverage the values relationship 

// At any node, p and q could be both in the left or right, or separated in left and right 
// if they are in both left and right, then the current root is the LCA 
// otherwise, we look down to the either the left or right 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ( !root || root == p || root == q )
            return root; 
        TreeNode *left = lowestCommonAncestor( root->left, p, q );
        TreeNode *right = lowestCommonAncestor( root->right, p, q);
        if ( left && right )
            return root;
        return left ? left : right;
    }
};


// An added on optimization, if a returned left is neither p nor q, then the returned node must be LCA
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ( !root || root == p || root == q )
            return root; 
        TreeNode *left = lowestCommonAncestor( root->left, p, q );
        if ( left && left != p && left != q )
            return left;
        TreeNode *right = lowestCommonAncestor( root->right, p, q);
        if ( left && right )
            return root;
        return left ? left : right;
    }
};

// This is the iterative solution which basically performs a traversal for both p and q. 
// Then reversely checks the common ancestor. 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ( !root )
            return nullptr;
        stack<TreeNode *> s{{root}};
        unordered_map<TreeNode *, TreeNode *> parent;
        unordered_set<TreeNode *> p_path;
        parent[root] = nullptr;
        while ( !parent.count(p) || !parent.count(q) ) 
        {
            TreeNode *cur = s.top();
            s.pop();
            if ( cur->left )
            {
                parent[cur->left] = cur;
                s.push(cur->left);
            }
            if ( cur->right )
            {
                parent[cur->right] = cur;
                s.push(cur->right);
            }
        }
        
        while ( p )
        {
            p_path.insert(p);
            p = parent[p];
        }
        
        while ( p_path.count(q) == 0 )
        {
            q = parent[q];
        }
        
        return q;
    }
};