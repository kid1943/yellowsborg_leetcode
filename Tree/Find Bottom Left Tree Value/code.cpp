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
    int findBottomLeftValue(TreeNode* root) {
        
        if(!root){
            return 0;
        }
        queue<TreeNode*> q;
        queue<int> level;
        
        q.push(root);
        level.push(0);
        
        vector<int> vec;
        
        int m = -1;
        int result;
        while(q.size()){
          TreeNode* sr = q.front();
          result = sr->val;
          int l = level.front();
          level.pop();
          q.pop();  
          
          if(sr->left){
              q.push(sr->left);
              level.push(l+1);
          }
          
          if(sr->right){
              q.push(sr->right);
              level.push(l+1);
          }
          
          if(l > m){
              m = l;
              vec.push_back(sr->val);
          }
        }
        return vec[m];
    }
};