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
    bool isBalanced(TreeNode* root) {
        
        if(!root){
            return true;
        }
        
        bool b;
        
        int result = getDepth(root->left) - getDepth(root->right);
        if(result <=1 && result >= -1){
            b = true;
        }else{
            b = false;
        }
        
        
        return b&&isBalanced(root->right)&&isBalanced(root->left);
        
    }
    
    
    int getDepth(TreeNode* root){
        if(!root){
            return 0;
        }
        int dep0 = getDepth(root->left);
        int dep1 = getDepth(root->right);
        return ++(dep0 > dep1 ? dep0 : dep1);
    }
};