// Problem Description 
/*
Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1:

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:

      2
     /
    4
and

    4
Therefore, you need to return above trees' root in the form of a list.
*/

// idea: if two subtrees are duplicate, then their serializations are the same 
// So we use DFS to searialize the subtrees and if there appeared before, then add 
// the current node (subtree root) to the result. 
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode *> res;
        unordered_map<string, int> subtreemap;
        findduplicatesubtreehelper(root,subtreemap,res);
        return res;
    }
    string findduplicatesubtreehelper( TreeNode* node, unordered_map<string,int> &m, vector<TreeNode*>& res) 
    {
        if ( !node )
            return "#";
        string subtreeserialization = to_string(node->val) + ","+ findduplicatesubtreehelper(node->left,m,res) + "," + findduplicatesubtreehelper(node->right,m,res);
        m[subtreeserialization]++;
        if ( m[subtreeserialization] == 2 )
            res.push_back(node);
        return subtreeserialization;
    }
};