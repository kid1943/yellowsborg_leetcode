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
    int sum;
    int sumOfLeftLeaves(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        
        if((root->left == NULL)&&(root->right) == NULL){
            return 0;
        }
        
        
        TreeNode* leftTree = root->left;
        if((leftTree!=NULL)&&(leftTree->left == NULL)&&(leftTree->right) == NULL){
            sum+=leftTree->val;
        }
        
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return sum;
    }
};