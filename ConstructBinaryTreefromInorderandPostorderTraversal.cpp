/* 
    Given inorder and postorder traversal of a tree, construct the binary tree.

    Note:
    You may assume that duplicates do not exist in the tree.

    For example, given

    inorder = [9,3,15,20,7]
    postorder = [9,15,7,20,3]
    Return the following binary tree:

     3
    / \
   9  20
     /  \
   15   7
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Idea: 
// Given a postorder traversal, we know the last element is the root. 
// Then we find the index of the root in the inorder traversal elements. then recursively apply the same 
// construction to both left and right sides of the inorder
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeHelper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    
    TreeNode *buildTreeHelper( vector<int> &inorder, int iLeft, int iRight, vector<int> &postorder, int pLeft, int pRight )
    {
        if ( iLeft > iRight )
            return NULL;
        TreeNode *curroot = new TreeNode(postorder[pRight]);
        int LeftTreeNodes = 0;
        for ( LeftTreeNodes = iLeft; LeftTreeNodes < inorder.size();LeftTreeNodes++ ) 
            if ( inorder[LeftTreeNodes] == curroot->val )
                break;
        curroot->left = buildTreeHelper(inorder,iLeft,LeftTreeNodes - 1,postorder,pLeft,pLeft+LeftTreeNodes-iLeft-1);
        curroot->right = buildTreeHelper(inorder,LeftTreeNodes+1,iRight, postorder, pLeft+LeftTreeNodes-iLeft, pRight-1);
        return curroot;
    }
};

// Idea: 
// As mentioned above, once we the root node, then we can partition the inorder to left and right sides 
// then for each side, we find the value whose idx in the postorder array is maximum as the root (postorder traversal)
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> InorderMap, PostorderMap;
        for ( int i = 0; i < inorder.size(); i++ )
            InorderMap[inorder[i]] = i;
        
        for ( int i = 0; i < postorder.size(); i++ )
            PostorderMap[postorder[i]] = i;
        return BuildTreeHelper(inorder,0,inorder.size()-1,postorder,postorder.size()-1,InorderMap,PostorderMap);
    }
    
    TreeNode *BuildTreeHelper(vector<int>& inorder, int iLeft, int iRight, vector<int>& postorder, int rootpostidx, unordered_map<int,int>& inordermap, unordered_map<int,int>& postordermap)
    {
        int leftroot = -1, rightroot = -1;
        if ( iLeft > iRight )
            return NULL;
        TreeNode * root = new TreeNode(postorder[rootpostidx]);
        for ( int i = iLeft; i < inordermap[postorder[rootpostidx]]; i++ )
            if ( postordermap[inorder[i]] > leftroot ) 
                leftroot = postordermap[inorder[i]];
        for ( int i = inordermap[postorder[rootpostidx]]+1; i <= iRight; i++ )
            if ( postordermap[inorder[i]] > rightroot )
                rightroot = postordermap[inorder[i]];
        root->left = BuildTreeHelper(inorder, iLeft, inordermap[postorder[rootpostidx]]-1,postorder, leftroot,inordermap, postordermap);
        root->right= BuildTreeHelper(inorder, inordermap[postorder[rootpostidx]]+1,iRight,postorder,rightroot,inordermap,postordermap);
        return root;
    }    
};

// idea: 
// starting from the last elment in the postorder elements, the next elment is the root of the right subtree of the
// tree rooted at the last element. 
// This solution walks through the postorder in the reverse direction and construct the tree 
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post_idx = postorder.size() - 1;
        unordered_map<int,int> inordermap;
        for ( int i = 0; i < inorder.size(); i++ )
            inordermap[inorder[i]] = i;
        return BuildTreeHelper(0,inorder.size()-1,postorder,inordermap);
    }  
    private:
    int post_idx;
    TreeNode *BuildTreeHelper(int iLeft, int iRight, vector<int> &postorder, unordered_map<int,int>& inordermap)
    {
        if ( iLeft > iRight )
            return NULL;
        TreeNode *root = new TreeNode(postorder[post_idx]);
        int rootinorderidx = inordermap[postorder[post_idx]];
        post_idx--;
        root->right = BuildTreeHelper(rootinorderidx+1,iRight,postorder,inordermap);
        root->left = BuildTreeHelper(iLeft,rootinorderidx-1,postorder,inordermap);
        return root;
    }
    
};