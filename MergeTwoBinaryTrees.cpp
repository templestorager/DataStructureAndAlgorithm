// Problem Description 
/*
 * Given two binary trees and imagine that when you put one of them to cover the other, some 
 * nodes of the two trees are overlapped while the others are not.
 * 
 * You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, 
 * then sum node values up as the new value of the merged node. Otherwise, the NOT null node will 
 * be used as the node of new tree.
 * 
 * Example 1:
 * Input: 
 *    Tree 1                     Tree 2                  
 *        1                         2                             
 *       / \                       / \                            
 *      3   2                     1   3                        
 *      /                           \   \                      
 *     5                             4   7                  
 * 
 * Output:
 *  Merged tree:
 *       3
 *      / \
 *     4   5
 *    / \   \ 
 *   5   4   7
 * 
 */

// This solution uses recursion 
// O(m) where m is the few number of nodes of the two trees, O(m) worst, O(lg m) average 
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if ( t1 == NULL ) 
            return t2;
        if ( t2 == NULL )
            return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right = mergeTrees(t1->right,t2->right);
        
        return t1;
    }
};

// This solution uses iterative approach 
// O(m) O(m), m is the smaller number of the nodes
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if ( t1 == nullptr ) 
            return t2; 
        stack<pair<TreeNode *, TreeNode *> > s;
        s.push(make_pair(t1,t2));
        while(!s.empty()) {
            pair<TreeNode *, TreeNode *> temp = s.top();
            s.pop();
            if ( temp.first == NULL || temp.second == NULL ) 
                continue;
            temp.first->val += temp.second->val;
            
            if ( temp.first->left == NULL ) {
                temp.first->left = temp.second->left;
            } else {
                s.push({temp.first->left, temp.second->left});
            }
            
            if ( temp.first->right == NULL )  {
                temp.first->right = temp.second->right;
            } else {
                s.push({temp.first->right, temp.second->right});
            }
        }
        
        return t1;
    }
};