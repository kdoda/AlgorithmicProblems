/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {

    private:
    void serializeRek(TreeNode* root, string & s) {
        //to have the string more compact store nulls as 'n' char and parse it on the other 
        //size, doint like this now to save time
        if (root == NULL)
        {
            s.append(std::to_string(INT_MIN) + " ");
            return;
        }
          
        s.append(std::to_string(root->val) + " ");
        serializeRek(root->left,s);
        serializeRek(root->right,s);
    }
    
    TreeNode* deserializeRek(const vector<int> & v, int &i) {
        if (i == v.size() - 1)
            return NULL;
    
        TreeNode* node = new TreeNode(v[i]);
        ++i;
        if(v[i] != INT_MIN)
            node->left = deserializeRek(v,i);
        else 
            ++i;
        
        if(v[i] != INT_MIN)
            node->right = deserializeRek(v,i);
        else 
            ++i;
        
       return node;
    }
    
    void parse(vector<int> & v, const string& data)
    {
        stringstream ss(data);
        int value;
        while(ss >> value)
        {
            v.push_back(value);
        }
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized;
        serializeRek(root, serialized);
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int i = 0;
        vector<int> parsed;
        parse(parsed, data);
        return deserializeRek(parsed,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));