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
    
    TreeNode* invertTree(TreeNode* root) {
    
        if(root == NULL){
            return root;
        }
    
        if(root->left == NULL && root->right == NULL){
            return root;
        }
        
        invertTree(root->right);
        invertTree(root->left);
        
        TreeNode* tmpNode;
        tmpNode = root->left;
        root->left = root->right;
        root->right = tmpNode;
        return root;
    }
    
    
};