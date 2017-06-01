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
    TreeNode* convertBST(TreeNode* root) {
         vector<int> vecResult;
         check(root, vecResult);
         return root;
    }
    
    
   vector<int> check(TreeNode* root, vector<int>& vecResult){
        if(!root){
            return vecResult;
        }
        check(root->right, vecResult);
        vecResult.push_back(root->val);
         for(int i = 0; i < vecResult.size()-1; i++){
              root->val += vecResult[i];
         }
        check(root->left, vecResult);
        return vecResult;
    }
};