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
    void dfs(TreeNode* root, string& s){
        if(!root){
            s.append("n,");
            return;
        }
        s.append(to_string(root->val));
        s.append(",");
        dfs(root->left, s);
        dfs(root->right, s);
    }
    TreeNode* treeBuilder(stringstream& ss){
        string word = "";
        std::getline(ss, word, ',');

        if(word == "n") return nullptr;
        TreeNode* node = new TreeNode(stoi(word));
        node->left = treeBuilder(ss);
        node->right = treeBuilder(ss);
        return node;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        dfs(root, str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return treeBuilder(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
