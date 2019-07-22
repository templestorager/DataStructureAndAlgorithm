// Problem Description 
/*
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of 
 * the nodes you can see ordered from top to bottom.

    Example:

    Input: [1,2,3,null,5,null,4]
    Output: [1, 3, 4]
    Explanation:

      1            <---
    /   \
    2     3         <---
    \     \
    5     4       <---

 * 
 */

// This solution essentially performs a level-order traversal, but keeping the last element of a queue
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> q;
        vector<int> res;
        if ( !root ) 
            return res;
        q.push(root);
        while (!q.empty()) {
            res.push_back(q.back()->val);
            int sz = q.size();
            for ( int i = 0; i < sz; i++ ) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if ( node->right)
                    q.push(node->right);
            }
        }
        return res;
    }
};