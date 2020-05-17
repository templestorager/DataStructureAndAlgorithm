// Problem Description
/*
 Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.  (The values of the nodes may still be duplicates.)

Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

The right-most node is also defined by the same way with left and right exchanged.

Example 1

Input:
  1
   \
    2
   / \
  3   4

Ouput:
[1, 3, 4, 2]

Explanation:
The root doesn't have left subtree, so the root itself is left boundary.
The leaves are node 3 and 4.
The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
So order them in anti-clockwise without duplicates and we have [1,3,4,2].
 

Example 2

Input:
    ____1_____
   /          \
  2            3
 / \          / 
4   5        6   
   / \      / \
  7   8    9  10  
       
Ouput:
[1,2,4,7,8,9,10,6,3]

Explanation:
The left boundary are node 1,2,4. (4 is the left-most node according to definition)
The leaves are node 4,7,8,9,10.
The right boundary are node 1,3,6,10. (10 is the right-most node).
So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].
*/

// This straightforward method pushes the left boundary, leaf nodes, and right boundary in order 
// It's worth noting how we are push duplicate nodes, e.g., the left-most node is for sure a leave node. 

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if ( !root )
            return res;
        if ( !IsLeafNode(root) )
            res.push_back(root->val);
        TreeNode *t = root->left;
        while ( t )
        {
            if ( !IsLeafNode(t) )   // leaf node is not pushed to the left boundary, and there is only one such node 
                res.push_back(t->val);
            if ( t->left )
                t = t->left;
            else 
                t = t->right;
        }
        AddLeave( res, root );
        stack<TreeNode*> rightnodestack; // right-most node traversal results in clock-wise order, so we need to reverse them 
        t = root->right;
        while ( t )
        {
            if ( !IsLeafNode(t) )   // again we avoid duplicating this node by not pushing it to the right boundary
                rightnodestack.push( t );
            if ( t->right )
                t = t->right;
            else
                t = t->left;
        }
        
        while ( !rightnodestack.empty() )
        {
            res.push_back(rightnodestack.top()->val);
            rightnodestack.pop();
        }
        
        return res;
    }
    
    bool IsLeafNode( TreeNode *root )
    {
        if ( !root->left && !root->right )
            return true;
        return false;
    }
    
    void AddLeave(vector<int> &res, TreeNode *root )
    {
        if ( IsLeafNode(root) )
        {
            res.push_back(root->val);
        }
        else
        {
            if ( root->left )
                AddLeave(res,root->left);
            if ( root->right )
                AddLeave(res,root->right);
        }
    }
};


// This method identifies the node type while using preorder traversing the binary tree
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> leftboundary, rightboundary, leaves;
        PreOrder(leftboundary,rightboundary,leaves,root,0);
        #if 1
        leftboundary.insert(leftboundary.end(),leaves.begin(),leaves.end());
        leftboundary.insert(leftboundary.end(),rightboundary.begin(),rightboundary.end());
        #endif
        #if 0
        for ( int i = 0; i < leaves.size(); i++ )
            leftboundary.push_back(leaves[i]);
        for ( int i = 0; i < rightboundary.size(); i++ )
            leftboundary.push_back(rightboundary[i]);
        #endif
        
        return leftboundary;
    }
    
    void PreOrder( vector<int> &left, vector<int> &right, vector<int> &leaves, TreeNode *root, int color)
    {
        if ( !root )
            return;
        if ( IsRightBoundary(color) )
            right.insert(right.begin(),root->val); // since preorder visits right boundary in reverse order. 
        else if ( IsLeftBoundary(color) || IsRoot(color) )
            left.push_back(root->val);
        else if ( IsLeafNode(root) )
            leaves.push_back(root->val);
        PreOrder(left,right,leaves,root->left,leftChildColor(root, color) );
        PreOrder(left,right,leaves,root->right,rightChildColor(root, color));
    }
    
    // 0: root, 1: leftboundary 2:rightboundary 3: other 
    bool IsLeafNode( TreeNode *node )
    {
        return !node->left && !node->right;
    }
    
    bool IsRoot( int color )
    {
        return color == 0;
    }
    
    bool IsLeftBoundary( int color )
    {
        return color == 1;
    }
    
    bool IsRightBoundary( int color )
    {
        return color == 2;
    }
    
    int leftChildColor( TreeNode *node, int color )
    {
        if ( IsLeftBoundary(color) || IsRoot(color) )
            return 1;       // leftboundary
        if ( IsRightBoundary(color) && !node->right )
            return 2;
        return 3;
    }
    
    int rightChildColor( TreeNode *node, int color )
    {
        if ( IsRoot(color) || IsRightBoundary(color) )
            return 2; // right boundary 
        if ( IsLeftBoundary(color) && !node->left )
            return 1;
        return 3;
    }
};