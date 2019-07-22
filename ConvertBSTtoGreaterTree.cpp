// Problem Description 
/*
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original
 * BST is changed to the original key plus sum of all keys greater than the original key in BST.
 * 
 * Example:
 * Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
 * 
 */

// This problem essentially needs to perform a reverse-in-order traversal
// In the meanwhile, we just need to track a global state (i.e., the total sum of the nodes 
// visited so far)
// O(n), O(n)
// Recursion approach 
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if ( root != nullptr ) {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
    
        return root;
    }   
private:
    int sum = 0;  
};

// Or 
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convertBSTHelper(root,sum);
        return root;
    }
    
    void convertBSTHelper( TreeNode* root, int &sum ) {
        if ( root != nullptr ) {
            convertBSTHelper(root->right,sum);
            sum += root->val;
            root->val = sum;
            convertBSTHelper(root->left,sum);
        }
    }
};

// This solution uses a stack to visit all tree nodes.
// O(n), O(n)
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int total = 0;
        stack<TreeNode *> s; 
        TreeNode *node = root;
        while ( !s.empty() || node ) {
            while ( node ) {
                s.push(node);
                node = node->right;
            }
            
            node = s.top();
            s.pop();
            total += node->val;
            node->val = total;
            node = node->left;
        }      
        return root;
    }  
};

// This solution uses tmporay auxiliary links during visiting nodes. 
// O(n), O(1)
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int totalsum = 0;
        TreeNode *node = root;
        while ( node ) { 
            if ( !node->right ) {
                totalsum += node->val;
                node->val = totalsum;
                node = node->left;
            }
            else {
                TreeNode * succ = getSuccessor(node);
                if ( !succ->left ) {
                    succ->left = node;
                    node = node->right;
                }
                else {
                    succ->left = NULL;
                    totalsum += node->val;
                    node->val = totalsum;
                    node = node->left;
                }
            }
        }
        
        return root;
    }
    
    TreeNode * getSuccessor(TreeNode * node ) {
        TreeNode *succ = node->right;
        while ( succ->left && succ->left != node ) {
            succ = succ->left;
        }    
        return succ;
    }
};