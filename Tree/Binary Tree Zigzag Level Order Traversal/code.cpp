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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         
         vector<vector<int>> vec_result; 
         
         if(!root){
             return vec_result;
         }
         queue<TreeNode*> q_node; 
         queue<int> q_level; 
         q_node.push(root);
         q_level.push(0);
         while(q_node.size()){
            TreeNode* node = q_node.front();     
            int level = q_level.front(); 
            q_node.pop();
            q_level.pop();
            
            if(vec_result.size() < level+1){
                  vector<int> vec_child;
                  vec_child.push_back(node->val);
                  vec_result.push_back(vec_child);
            }else{
                  vec_result[level].push_back(node->val); 
            }
         
              ++level;
              
              if(node->left){
                q_node.push(node->left);
                q_level.push(level);
              }
              
              if(node->right){
                q_node.push(node->right);
                q_level.push(level);
              } 
         }
         
         for(int i = 0; i < vec_result.size(); i++){
              
              if(i%2 != 0){
                 reverse(vec_result[i].begin(), vec_result[i].end());  
              }
         }
         return vec_result;
    }
};