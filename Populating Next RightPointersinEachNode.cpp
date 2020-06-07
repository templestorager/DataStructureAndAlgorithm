// Problem Description 
/*
    You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

    struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    }
    Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

    Initially, all next pointers are set to NULL.

    

    Follow up:

    You may only use constant extra space.
    Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
    

    Example 1:



    Input: root = [1,2,3,4,5,6,7]
    Output: [1,#,2,3,#,4,5,6,7,#]
    Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
    

    Constraints:

    The number of nodes in the given tree is less than 4096.
    -1000 <= node.val <= 1000
*/

// Basically, we can perform a level-order traversal and establish the next link for the nodes in each of 
// of the levels except the last node

class Solution {
public:
    Node* connect(Node* root) {
        if ( !root )
            return root;
        queue<Node*> q;
        q.push(root);
        while( !q.empty() )
        {
            int cur_sz = q.size(); 
            
            for ( int i = cur_sz; i > 0; i-- )
            {
                Node *tmp = q.front();
                q.pop();
                if ( i > 1)
                {
                    tmp->next = q.front();
                }
                if ( tmp->left ) 
                    q.push( tmp->left );
                if ( tmp->right )
                    q.push( tmp->right );
            }
        }
        return root;
    }
};


// As usual, we can always recursion to establish the next links 
// if it has an left, then it must have a right and right is the next of the left. 
// if it has a right, then if it has next (i.e., not the last element in the current level), then the next is 
// it's next's left.
class Solution {
public:
    Node* connect(Node* root) {
        if ( root == nullptr )
            return root;
        if ( root->left )
            root->left->next = root->right;
        if ( root->right )
            root->right->next = root->next? root->next->left : nullptr;
        connect( root->left );
        connect( root->right );
        return root;
    }
};

// this function is also based on the level traversal idea. 
// It starts from the first node of the each level and establishes the next nodes of the next level.
// It them moves down to the next level.

class Solution {
public:
    Node* connect(Node* root) {
        if ( root == nullptr )
            return root;
        Node *curlevelhead = root;
        while ( curlevelhead->left )
        {
            Node *walk = curlevelhead;
            while ( walk )
            {
                walk->left->next = walk->right;
                if ( walk->next )
                    walk->right->next = walk->next->left;
                walk = walk->next;
            }
            
            curlevelhead = curlevelhead->left;
        }
        
        return root;
    }
};