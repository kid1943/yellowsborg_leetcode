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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        return traver(root, vec);
    }
    
    //递归实现
    vector<int> traver(TreeNode* root, vector<int>& vec){        
        if(!root){
            return vec;
        }        
        traver(root->left, vec);
        vec.push_back(root->val);
        traver(root->right, vec);
        return vec;
    }
	
	
	/*
	非递归实现但会改变树的结构
	vector<int> traverse(TreeNode* root, vector<int>& vec) {
           stack<TreeNode*> s;
           s.push(root);
           while(!s.empty()){
             TreeNode* node = s.top();
              if(node ->left){
                  s.push(node ->left);
                  node ->left = NULL;//防止重复遍历
              }else{
                  s.pop();
                  vec->push(node->val);
                  if(node->right){
                     s.push(node->right);
                  }   
              } 
            }
          return vec;
    }
   */
    
    
};