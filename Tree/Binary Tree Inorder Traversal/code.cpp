/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        return traver(root, vec);
    }
    
    
    vector<int> traver(TreeNode* root, vector<int>& vec){
        
        if(!root){
            return vec;
        }
        
        traver(root->left, vec);
        
        vec.push_back(root->val);
        
        traver(root->right, vec);
        return vec;
    }
    
    
};