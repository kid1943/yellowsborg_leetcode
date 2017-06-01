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
    vector<int> rightSideView(TreeNode* root) {
       vector<int> vec;
       if(!root){
           return vec;
       }
       
       unordered_map<int, bool> map;//层数和对于的最右值
       
       queue<TreeNode*> q;
       queue<int> levq;
       q.push(root);
       levq.push(0);
      
       while(!q.empty()){
            TreeNode* node = q.front();
            int level = levq.front();
            q.pop();
            levq.pop();
            
            if(!map[level]){
              map[level] = true;
              vec.push_back(node->val);
            }
            
              ++level;
          
            if(node->right){
                q.push(node->right);
                levq.push(level);
            }
            
            if(node->left){
                q.push(node->left);
                levq.push(level);
            }
       }
       return vec;
    }
};