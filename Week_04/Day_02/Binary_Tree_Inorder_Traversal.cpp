// Recursive Approach

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& arr) {
        if(root == nullptr) {
            return;
        }
        inOrder(root->left, arr);

        arr.push_back(root->val);

        inOrder(root->right, arr);
    }
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> arr;

      inOrder(root, arr);

      return arr;  
    }
};

// Iterative Approach Using Stack

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
       stack<TreeNode*> st;
       TreeNode* node = root;

       vector<int> in;

       while(true) {
        if(node != NULL) {
            st.push(node);

            node = node->left;
        }
        else{
            if(st.empty()) {
                break;
            }
            node = st.top();
            st.pop();
            
            in.push_back(node->val);

            node = node->right;
        }
       } 
       return in;
    }
};
