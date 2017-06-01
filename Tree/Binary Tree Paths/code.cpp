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
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<string> vec; 
      combineStr(root, "", vec);
      return vec;
    }
    
    vector<string> combineStr(TreeNode* root, string str, vector<string>& vec){
        if(root == nullptr){
            return vec;
        }
       
        if(root->left == nullptr && root->right == nullptr){
          if(str != ""){
              str = str + "->" + to_string(root->val);
          }else{
              str =  to_string(root->val);
          }
            vec.push_back(str);
            return vec;
        }
       
         if(str != ""){
             str = str + "->" + to_string(root->val);
         }else{
             str =  to_string(root->val);
         }
       
        combineStr(root->right, str, vec);
        combineStr(root->left, str, vec);
        
        return vec;
    }
    
};