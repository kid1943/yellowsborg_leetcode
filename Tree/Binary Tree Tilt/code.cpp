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
    int findTilt(TreeNode* root) {
        int rightVal;
        int leftVal;
        
        if(root == NULL){
            return 0;
        }
        
        leftVal = findTilt(root->left);
        rightVal = findTilt(root->right);
        
        int leftSum = sum(root->left);
        int rightSum = sum(root->right);
        int relaVal = abs(leftSum - rightSum);
        
        int result = leftVal + rightVal + relaVal;
        return result;
    }
    
    int sum(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftSum = sum(root->left);
        int rightSum = sum(root->right);
        int sumVal = leftSum + rightSum + root->val;
        return sumVal;
    }
};