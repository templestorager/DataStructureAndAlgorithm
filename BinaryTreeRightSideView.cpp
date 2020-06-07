// Problem Description 
/*
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of 
 * the nodes you can see ordered from top to bottom.

    Example:

    Input: [1,2,3,null,5,null,4]
    Output: [1, 3, 4]
    Explanation:

      1            <---
    /   \
    2     3         <---
    \     \
    5     4       <---

 * 
 */

// This solution essentially performs a level-order traversal, but keeping the last element of a queue
// Use one queue 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> q;
        vector<int> res;
        if ( !root ) 
            return res;
        q.push(root);
        while (!q.empty()) {
            res.push_back(q.back()->val);
            int sz = q.size();
            for ( int i = 0; i < sz; i++ ) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if ( node->right)
                    q.push(node->right);
            }
        }
        return res;
    }
};

// Use two queues 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> RightSideView;
        queue<TreeNode *> curlevel; 
        if ( root )
            curlevel.push( root );
        while ( !curlevel.empty() )
        {
            queue<TreeNode*> nextlevel;
            TreeNode *curnode = NULL;
            while ( !curlevel.empty() )
            {
                curnode = curlevel.front();
                curlevel.pop();
                if ( curnode->left )
                    nextlevel.push( curnode->left );
                if ( curnode->right )
                    nextlevel.push( curnode->right );
            }
            RightSideView.push_back( curnode->val );
            curlevel = nextlevel;
        }
        
        return RightSideView;
    }
};

// Use one queue + a sentinel for each level 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> RightSideView;
        queue<TreeNode *> curlevel; 
        if ( root )
        {
            curlevel.push(root);
            curlevel.push(NULL);
        }
        while ( !curlevel.empty() )
        {
            TreeNode *curnode = NULL;
            while ( curlevel.front() != NULL )
            {
                curnode = curlevel.front();
                curlevel.pop();
                if ( curnode->left )
                {
                    curlevel.push( curnode->left );
                }
                if( curnode->right )
                {
                    curlevel.push( curnode->right );
                }

            }
            curlevel.pop();   // pop the null sentinel 
            if ( curlevel.size() )
                curlevel.push( NULL );
            if ( curnode )
                RightSideView.push_back( curnode->val );
        }
        
        return RightSideView;
    }
};

// Or we can remember the previous node
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> RightSideView;
        queue<TreeNode *> curlevel; 
        TreeNode *curnode = root, *prevnode = NULL;
        if ( root )
        {
            curlevel.push(root);
            curlevel.push(NULL);
        }
        while ( !curlevel.empty() )
        {
            prevnode = curnode;
            curnode = curlevel.front();
            curlevel.pop();
            while ( curnode )
            {
                if ( curnode->left )
                {
                    curlevel.push(curnode->left);
                }
                if ( curnode->right )
                {
                    curlevel.push(curnode->right);
                }
                prevnode = curnode;
                curnode = curlevel.front();
                curlevel.pop();
            }
            
            RightSideView.push_back( prevnode->val );
            if ( curlevel.size() )
                curlevel.push(nullptr);
        }
        
        return RightSideView;
    }
};

// use a queue + level size 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> RightSideView;
        queue<TreeNode *> curlevel; 
        if ( root )
        {
            curlevel.push(root);
        }
        while ( !curlevel.empty() )
        {
            int cursz = curlevel.size();
            for ( int i = 0; i < cursz; i++ )
            {
                TreeNode *tmp = curlevel.front();
                curlevel.pop();
                if ( tmp->left ) 
                    curlevel.push(tmp->left);
                if ( tmp->right )
                    curlevel.push(tmp->right);
                if ( i == cursz - 1)
                {
                    RightSideView.push_back( tmp->val );
                }
            }
        }
        
        return RightSideView;
    }
};