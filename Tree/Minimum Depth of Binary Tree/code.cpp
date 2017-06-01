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
    int minDepth(TreeNode* root) {
     
     if(root == nullptr){
         return 0;
     }
     
     int d = 0;
     while(((!root->left)&&root->right)||((!root->right)&&root->left)){
         d++;
         if(root->left){
            root = root->left; 
         }else{
             root = root->right;
         }
     }
     int x = minDepthExcue(root);
     return  d+x;
    }
    
     int minDepthExcue(TreeNode* root) {
         
        if(root == nullptr){
            return 0;
        }
        int d0 = minDepth(root->right);
        int d1 = minDepth(root->left);
        int d = (d0-d1) > 0 ? d1 : d0; 
        ++d;
     return  d;
    }
};