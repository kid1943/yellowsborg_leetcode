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
    int diameterOfBinaryTree(TreeNode* root) {
       
        if(root == nullptr){
            return 0;
        }
        
        return max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right), getPathLength(root));   
    }
    
    int getPathLength(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return getDepth(root->left)+getDepth(root->right);   
    }
    
    int getDepth(TreeNode* root){
       if(root == nullptr){
           return 0;
       }
       
        int depth0 = getDepth(root->left);
        int depth1 = getDepth(root->right) ;
     
        if(depth0 >= depth1){
            return ++depth0;
        }else{
            return ++depth1;
        }
    }
    
    int max(int x,int y,int z)  
    {
       int max;
       if(x<=y)
          max=y;
       else
          max=x;
       if(max<=z)
          max=z;
       return max;
    }
};