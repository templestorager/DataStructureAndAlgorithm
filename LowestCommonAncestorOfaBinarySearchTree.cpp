// Problem Description 
/*
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in 
 * the BST.
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between 
 * two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow 
 * a node to be a descendant of itself).”
 * 
 * Example 1:
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6.
 * 
 * Example 2:
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * Output: 2 
 * Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
 * 
 * Note:
 * All of the nodes' values will be unique.
 * 
 * p and q are different and both values will exist in the BST.
 * 
 */
// This solution leverages the property of BST and uses recursion 
// i.e., if the value of root is larger than both of p and q, then continue to 
// O(N), O(N)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ( !root ) 
            return NULL;
        if ( root->val > max(p->val, q->val) ) 
            return lowestCommonAncestor(root->left,p,q);
        else if ( root->val < min(p->val,q->val) )
            return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};


// This solution is an iterative approach, which updates root recursively
// O(N), O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while ( 1 ) {
            if ( root->val > max(p->val,q->val) ) 
                root = root->left;
            else if ( root->val < min(p->val,q->val) ) 
                root = root->right;
            else 
                break;
        }
        return root;
    }
};