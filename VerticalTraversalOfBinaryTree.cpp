// Problem description 
/*
 Given a binary tree, return the vertical order traversal of its nodes values. For each node at position 
 (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1). Running 
 a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we 
 report the values of the nodes in order from top to bottom (decreasing Y coordinates). If two nodes have 
 the same position, then the value of the node that is reported first is the value that is smaller.
Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.
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

// This solution uses depth-first-search to construct map structuring mapping an X-coordinate to 
// a list of pairs of <-y,node_val>. 
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        NodeMap.clear();
        dfs(root, 0, 0 );
        vector<vector<int>> res;
        for (auto node: NodeMap ) {
            sort(node.second.begin(),node.second.end());
            vector<int> VerticalLine;
            for (auto p : node.second)
                VerticalLine.push_back(p.second);
            res.push_back(VerticalLine);
        }
        return res;
    }
    
private:
    // map x-coordinate to the list of node info ( -y, val )
    map<int, vector<pair<int,int>> > NodeMap; 
    void dfs(TreeNode * root, int x, int y){
        if ( !root )
            return;
        NodeMap[x].emplace_back(-y, root->val);
        dfs(root->left, x-1, y-1 );
        dfs(root->right, x+1, y-1 );
        
    }
};

// this solution uses the same idea, but uses bread-first-search for traversing the tree

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode *,pair<int,int>>> queue;
        queue.push(make_pair(root,make_pair(0,0)));
        map<int, vector<pair<int,int>>> NodeMap;
        while ( !queue.empty() ){
            auto node = queue.front();
            queue.pop();
            int x = node.second.first;
            int y = node.second.second;
            NodeMap[x].emplace_back(-y,node.first->val);
            if ( node.first->left )
                queue.push(make_pair(node.first->left,make_pair(x-1,y-1)));
            if ( node.first->right )
                queue.push(make_pair(node.first->right,make_pair(x+1,y-1)));
        }
        vector<vector<int> > res;
        for ( auto node : NodeMap ) {
            vector<int> vals;
            sort(node.second.begin(),node.second.end());
            for ( auto p : node.second )
                vals.push_back(p.second);
            res.push_back(vals);
        }
        return res;
    }
    
};