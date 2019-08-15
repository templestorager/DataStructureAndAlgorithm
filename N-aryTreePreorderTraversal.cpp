// Problem Description
/*
    Given an n-ary tree, return the preorder traversal of its nodes' values.
    Note:
    Recursive solution is trivial, could you do it iteratively?
 * 
 * 
 */

/*

// Definition for a Node.
    class Node {
    public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
    };
*/

// Straightforward recursive solution 
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        helper(root,res);
        return res;
    }
    
    void helper( Node* root, vector<int> &res){
        if ( !root ) 
            return;
        res.push_back(root->val);
        for ( Node* node : root->children ) 
            helper(node,res);
    }
};

// iterative solution 
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node *> s;
        s.push(root);
        while( !s.empty() ) {
            Node *node = s.top();
            s.pop();
            if ( node == NULL ) {
                continue;
            }           
            for ( int i = node->children.size() - 1; i >= 0; i-- ) {
                s.push(node->children[i]);
            }        
            res.push_back(node->val);
        } 
        return res;
    }
};
