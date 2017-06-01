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

      
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> vec;
      stack<TreeNode*> s;
      TreeNode* pCurrent = root;
      if(!root){
          return vec;
      }
       unordered_map<TreeNode*, bool> map;
     while(!s.empty() || pCurrent){
        if(pCurrent && !map[pCurrent]){
            s.push(pCurrent);
            map[pCurrent] = true;
            pCurrent = pCurrent->left;
        }else{ 
            TreeNode *pNode = s.top();
            pCurrent = pNode->right;
            if(!pCurrent || map[pCurrent]){
                vec.push_back(pNode->val);
                s.pop();
                pCurrent = nullptr;
            } 
        }
    }
      return vec;
    }
      
     /*vector<int> postorderTraversal(TreeNode* root) {
      vector<int> vec;
      stack<TreeNode*> s;
      unordered_map<TreeNode*, bool> map;
      if(!root){
          return vec;
      }
      s.push(root);
      while(!s.empty()){
        TreeNode* node = s.top();
        if(node->left && !map[node->left]){
            s.push(node->left);
            map[node->left] = true;
        }else{
          if(node->right && !map[node->right]){
            s.push(node->right);       
            map[node->right] = true;
          }else{
            s.pop();
            vec.push_back(node->val);
          }
        }
      }
      return vec;
     }*/
    /*
      会改变树的结构
      vector<int> postorderTraversal(TreeNode* root) {
      vector<int> vec;
      stack<TreeNode*> s;
      if(!root){
          return vec;
      }
      s.push(root);
      while(!s.empty()){
        TreeNode* node = s.top();
        if(node->left){
            s.push(node->left);
            node->left = NULL;
        }else{
          if(node->right){
            s.push(node->right);       
            node->right = NULL;
          }else{
            s.pop();
            cout<< node->val <<endl;
            vec.push_back(node->val);
          }
        }
      }
      return vec;
    }*/
    
    /*递归实现
     vector<int> traversal(TreeNode* root, vector<int>& vec){
        if(!root){
            return vec;
        }
        traversal(root->left, vec);
        traversal(root->right, vec);
        vec.push_back(root->val);
        return vec;
    }*/
    
    
};