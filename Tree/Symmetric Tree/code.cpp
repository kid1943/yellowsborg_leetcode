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
    bool isSymmetric(TreeNode* root) {
     if(root == nullptr){
         return true;
     }    
      return  check(root->left, root->right);
    }
    
    bool check(TreeNode* root0, TreeNode* root1){
        
        bool result;
        
        if(root0 == nullptr|| root1==nullptr){
            return !root0&&!root1;//其中一个为null一个不为null 返回flase
        }
        
        if(root0->val == root1->val){
            result = true;
        }else{
            result = false;
        }
        
         return result&&check(root0->left, root1->right)&&check(root0->right, root1->left);
        
    }
    
};