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
    bool hasPathSum(TreeNode* root, int sum) {
     if(root == NULL){
         return false;
     }    
     return   add2Root(root, 0, sum);
    }
    
    bool add2Root(TreeNode* node, int add, int sum){
        if(node == NULL){
            return false;
        }
        add += node->val;
        if((node->left == NULL)&&(node->right == NULL)){
            if(add == sum){
                return true;
            }else{
                return false;
            }
        }
        
        return  add2Root(node->left, add, sum)||add2Root(node->right, add, sum);
    }
};