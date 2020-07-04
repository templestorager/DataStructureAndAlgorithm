// Problem Description
/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

 

Example:



BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false
 

Note:

next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
You may assume that next() call will always be valid, that is, there will be at least a next smallest number in the BST when next() is called.
*/

// We flatten the tree in an array and just maintains an index to the array to faciliate next() and hasnext()
// O(n) O(n)
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        Inorder( root, FlattenedData );
        NextIdx = 0; 
    }
    
    /** @return the next smallest number */
    int next() {
        return FlattenedData[NextIdx++]->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return NextIdx < FlattenedData.size();
    }
private:
    int NextIdx; 
    vector<TreeNode *> FlattenedData; 
    void Inorder( TreeNode *root, vector<TreeNode *> &data )
    {
        if ( !root ) 
            return ;
        Inorder( root->left, data );
        data.push_back( root );
        Inorder( root->right, data );
    }
};

// We can also maintain the a stack which has the next smallest on its top. It actually simulate the inorder traversal. 
// whenever we pop the top nodes,  we push its next node onto the stack, which is the leftmost grandchild of its right child
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while ( root )
        {
            leftnodes.push( root );
            root = root->left;
        }
    }
    /** @return the next smallest number */
    int next() {
        TreeNode *t = leftnodes.top();
        int res = t->val;
        leftnodes.pop();
        TreeNode *right = t->right;
        while ( right )
        {
            leftnodes.push( right );
            right = right->left;
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !leftnodes.empty();
    }
private:
    stack<TreeNode*> leftnodes;
};

