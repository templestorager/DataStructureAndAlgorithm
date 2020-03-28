/*
 * Problem Description 
    Given preorder and inorder traversal of a tree, construct the binary tree.

    Note:
    You may assume that duplicates do not exist in the tree.

    For example, given

    preorder = [3,9,20,15,7]
    inorder = [9,3,15,20,7]
    Return the following binary tree:

          3
         / \
        9  20
           /  \
          15   7
*/ 

// Idea: 
// The first element in the preorder is the right and the following element is the root of its left subtree 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for ( int i = 0; i < inorder.size(); i++ )
            inordermap[inorder[i]] = i;
        return BuildTreeHelper(preorder,0,inorder.size()-1);
    }
    
    TreeNode* BuildTreeHelper(vector<int>& preorder, int in_left, int in_right)
    {
        if ( in_left > in_right  )
            return NULL;
        TreeNode *root = new TreeNode(preorder[pre_idx]);
        int rootinidx = inordermap[preorder[pre_idx]];
        pre_idx++;
        root->left = BuildTreeHelper(preorder,in_left,rootinidx-1);
        root->right = BuildTreeHelper(preorder,rootinidx+1,in_right);
        return root;
    }
    int pre_idx = 0; 
    unordered_map<int, int> inordermap;
    
};

// Idea: once we divide the inorder into two parts, then the minimum preorder index is the respective root 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for ( int i = 0; i < inorder.size(); i++ )
            inordermap[inorder[i]] = i;
        for ( int i = 0; i < preorder.size(); i++ )
            preordermap[preorder[i]] = i;
        return BuildTreeHelper(inorder,preorder,0,inorder.size()-1,0);
    }
    
    TreeNode* BuildTreeHelper(vector<int>& inorder, vector<int>& preorder, int in_left, int in_right, int rootpreidx)
    {
        if ( in_left > in_right )
            return NULL;
        TreeNode* root = new TreeNode(preorder[rootpreidx]);
        uint32_t leftroot = UINT32_MAX, rightroot = UINT32_MAX, rootinidx = inordermap[preorder[rootpreidx]];
        for ( int i = in_left; i < rootinidx; i++ )
            if ( preordermap[inorder[i]] < leftroot )
                leftroot = preordermap[inorder[i]];
        for ( int i = rootinidx + 1; i <= in_right; i++ )
            if ( preordermap[inorder[i]] < rightroot )
                rightroot = preordermap[inorder[i]];
        root->left = BuildTreeHelper(inorder, preorder,in_left,rootinidx-1,leftroot);
        root->right = BuildTreeHelper(inorder, preorder,rootinidx+1,in_right, rightroot);
        return root;
    }
    unordered_map<int, int> inordermap, preordermap;
    
};