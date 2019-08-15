// Problem Description
/*
 * Given an n-ary tree, return the postorder traversal of its nodes' values.
 * Note:
 * Recursive solution is trivial, could you do it iteratively?
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


// this solution uses recurison 
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorderhelper(res,root);
        return res;
    }
    
    void postorderhelper(vector<int> &res, Node *root) {
        if ( root == NULL ) 
            return;
        for ( int i = 0; i < (root->children).size(); i++ ) {
            postorderhelper(res,root->children[i]);
        }
        res.push_back(root->val);
    }
};


// hint: iterative approach 
// note we insert the popped item at the front 
class Solution {
public:
    vector<int> postorder(Node* root) {
        if ( !root ) 
            return {};
        vector<int> res;
        stack<Node*> s{{root}};
        while ( !s.empty() ) {
            Node *t = s.top();
            s.pop();
            res.insert(res.begin(),t->val);
            for ( Node * child : t->children ) {
                if ( child )
                    s.push(child);
            }
        }
        
        return res;
    }
};