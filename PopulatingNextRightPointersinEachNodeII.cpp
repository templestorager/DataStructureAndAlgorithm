// Problem Description
/*
Given a binary tree

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
*/

// 1. Without doubt, we can use the level-order traversal to establish the next connections 
// 2. We can also leverage the already established next points, level by level from top to bottom. 
//    The only difference is that we need more careful checks to find the following nodes, given nodes are possibly missing
// Compared with the level order approach, it doesn't require an additional queue to hold the nodes in the same level, 
// as it can find all the node in the next level following the established next connections. 
// Thus, it is more space efficient than the level-order traversal approach. 
class Solution {
public:
    Node* connect(Node* root) {
        Node *walk_curlevel = root;
        while ( walk_curlevel ) 
        {
            // Find the node in the next level to start for next iteration
            Node *head_nextlevel = nullptr;
            Node *tmp = walk_curlevel; 
            while ( tmp )
            {
                if ( tmp->left || tmp->right )
                {
                    head_nextlevel = tmp->left ? tmp->left : tmp->right;
                    break;
                }
                tmp = tmp->next;
            }
            
            while ( walk_curlevel )
            {
                if ( !walk_curlevel->left && !walk_curlevel->right )
                {
                    walk_curlevel = walk_curlevel->next;
                    continue;
                }
                if ( walk_curlevel->left )
                {
                    if ( walk_curlevel->right )
                    {
                        walk_curlevel->left->next = walk_curlevel->right;
                    }
                    else
                    {
                        Node *next = walk_curlevel->next;
      
                        while ( next && !next->left && !next->right )
                            next = next->next;
                        if ( next )
                            walk_curlevel->left->next = next->left ? next->left : next->right;

                    }
                }
                if ( walk_curlevel->right )
                {
                    Node *next = walk_curlevel->next;
                    while ( next && !next->left && !next->right )
                        next = next->next;
                    if ( next )
                        walk_curlevel->right->next = next->left ? next->left : next->right;
                }
                walk_curlevel = walk_curlevel->next;
            }
            walk_curlevel = head_nextlevel;
        }
        
        return root;
    }
};

// We can also use recursion to establish the connects, but need to do it from right to left. 
class Solution {
public:
    Node* connect(Node* root) {
        if ( !root )
            return root;
        Node *next = root->next;
        while ( next )
        {
            if ( next->left ) 
            {
                next = next->left;
                break;
            }
            if ( next->right )
            {
                next = next->right;
                break;
            }
            next = next->next;
        }
        
        if ( root->right )
            root->right->next = next;
        if ( root->left )
            root->left->next = root->right ? root->right : next;
        
        connect(root->right);
        connect(root->left);
        
        return root;
    }
};

// Still the same level order traversal.
class Solution {
public:
    Node* connect(Node* root) {
        if ( !root )
            return root;
        Node *curlevel = root;
        while ( curlevel )
        {
            Node dummy(0), *nextlevel = &dummy;
            while ( curlevel )
            {
                if ( curlevel->left ) 
                {
                    nextlevel->next = curlevel->left;
                    nextlevel = nextlevel->next;
                }
                if ( curlevel->right )
                {
                    nextlevel->next = curlevel->right;
                    nextlevel = nextlevel->next;
                }
                curlevel = curlevel->next;
            }
            
            curlevel = dummy.next; 
        }
        
        return root;
    }
};