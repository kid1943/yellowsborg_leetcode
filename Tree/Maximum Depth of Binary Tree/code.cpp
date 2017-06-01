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
    int maxDepth(TreeNode* root) {
    return  getMaxDepth(root, 1);
    }
    
    int getMaxDepth(TreeNode* root, int depth){
        
        if(root == NULL){
            return 0;
        }
        
        if((root->left == NULL)&&(root->right == NULL)){
            return depth++;
        }
          
      int depth0 = getMaxDepth(root->left, depth);
      int depth1 = getMaxDepth(root->right, depth);
      return ++(depth0 > depth1 ? depth0 : depth1);
    }
};