// Problem Description 
/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/


// Idea: 
// Serialize: encode it as string of "rootval(left)(right)"
// Deserialize: 
// 1. find the first value
// 2. find the left subtree (first time when parentheses are paired)
// 3. if right substree exist, the remaining is the right substree
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if ( root == NULL ) 
            return "";
        string s = to_string(root->val) + "(" + serialize(root->left) + ")";
        if ( root->right ) 
        {
            s += "(" + serialize(root->right) + ")";
        }
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if ( data.size() == 0) 
            return NULL;
        int j = 0; 
        // find the first number 
        while( j < data.size() && data[j] != '(') 
            j++;                // data[j] == '('
        TreeNode *root = new TreeNode(stoi(data.substr(0,j))); // first value is substring[0~j-1]
        int i = j, openparenthese = 0;
        while ( i < data.size() )
        {
            if ( data[i] == '(' )
            {
                openparenthese++;
            }
            else if ( data[i] == ')' )
            {
                openparenthese--;
            }
            if ( openparenthese == 0 )
                break;                // found the left subtree substring[j+1~i-1], since data[j] and data[i] are the open and closing parenthese of the left subtree
            i++;
        }
        if ( j < data.size() - 1 )
            root->left = deserialize(data.substr(j+1,i-1-j));  // substr[j+1, i-1]
        if ( i + 1 < data.size() - 1 )
            root->right = deserialize(data.substr(i+2, data.size()-3-i));  
            // right subtree: substring[i+2~data.size()-2], since data[i+1] and data[data.size()-1] are the open and closing parenthese of the right subtree
        
        return root;
    }
};


// this method uses the preorder traversal 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root,out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
    
private:
    void serialize(TreeNode *root, ostringstream &out )
    {
        if ( !root )
        {
            out<< "#";
        }
        else 
        {
            out <<root->val<<' ';
            serialize(root->left,out);
            serialize(root->right,out);
        }
    }
    TreeNode *deserialize(istringstream &in )
    {
        string val;
        in >> val;
        if ( val == "#" )
            return NULL;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

// this method leverages the level order traversal
// For each node in the level queue, the following two numbers separated by space are its left and right child, respectively. 
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        queue<TreeNode *> q;
        if ( root != NULL )
            q.push(root);
        while (!q.empty() )
        {
            TreeNode *tmp = q.front();
            q.pop();
            if ( tmp )
            {
                out << tmp->val<<' ';
                q.push(tmp->left);
                q.push(tmp->right);
            }
            else 
            {
                out << "# ";
            }
        }
        
        return out.str();
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if ( data.empty() )
            return NULL;
        istringstream in(data);
        queue<TreeNode *> q;
        string val;
        in >> val;
        TreeNode *root = new TreeNode(stoi(val)), *cur = root;
        q.push(cur);
        while ( !q.empty() )
        {
            TreeNode *t = q.front();
            q.pop();
            if ( ! (in >> val ) )
                break;
            if ( val != "#" )
            {
                cur = new TreeNode(stoi(val));
                t->left = cur;
                q.push(cur);
            }
            if ( ! (in >> val) )
            {
                break;
            }
            
            if ( val != "#" )
            {
                cur = new TreeNode(stoi(val));
                t->right = cur;
                q.push(cur);
            }
        }
        
        return root;
    }

};