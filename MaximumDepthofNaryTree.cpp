// Problem Description
/*
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// Basically, the maxdepth it equal to the number of levels. so we can use level order traversal to calculate 
// the max depth
class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node*> q; 
        int maxdepth = 0;
        if ( root == nullptr )
            return maxdepth;
        q.push(root);
        while ( !q.empty() )
        {
            int q_sz = q.size();
            if ( q_sz > 0 )
                maxdepth++;
            for ( int i = q_sz; i > 0; i-- )
            {
                Node *tmp = q.front();
                q.pop();
                for ( auto c : tmp->children )
                {
                    if ( c )
                        q.push(c);
                }
            }
        }
        
        return maxdepth;
    }
};

// We can use recursion, as we traverse down, we update the global result
class Solution {
public:
    int maxDepth(Node* root) {
        int res = 0;
        helper( root, 1, res );
        return res;
    }
    void helper( Node *root, int cur, int &res )
    {
        if ( root == nullptr )
            return;
        if ( root->children.size() == 0 )
            res = max(cur,res);
        for ( auto c : root->children )
            helper( c, cur+1, res);
    }
};

// Recursion without an additional helper function 
class Solution {
public:
    int maxDepth(Node* root) {
        if ( root == nullptr )
            return 0;
        int res = 1;
        for ( auto c : root->children )
            res = max( res, maxDepth(c) + 1 );
        return res;
    }
};