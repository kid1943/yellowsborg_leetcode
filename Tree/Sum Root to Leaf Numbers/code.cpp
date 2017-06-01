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
    int sumNumbers(TreeNode* root) {
        
        int sum = 0;
        
        if(!root){
            return 0;
        }
        caculateNumbers(root, 0, sum);
        return sum;
    }
    
    int caculateNumbers(TreeNode* root,int fNum , int & result){
        
        if(!root){
            return result;
        }
        
        int num = root->val;
        fNum = fNum*10+num;
        
        if(!root->left && !root->right){
            return result+=fNum;
        }
        
        caculateNumbers(root->left, fNum, result);
        caculateNumbers(root->right, fNum, result);
        return result;
    }
};