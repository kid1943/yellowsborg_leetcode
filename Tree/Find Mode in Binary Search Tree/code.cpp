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
    
unordered_map<int,int> m; 
int max = 0;
vector<int> vecResult;
public:
    vector<int> findMode(TreeNode* root) {

        return  getMap(root);

    }
    
    vector<int> getMap(TreeNode* root){
        if(!root){
            return vecResult;
        }
        
        int val = ++m[root->val];  
       if(max == 0){
          max = val;
          vecResult.push_back(root->val);
        }else if(val > max){
          max = val;   
          vecResult.erase(vecResult.begin(), vecResult.end());
          vecResult.push_back(root->val);
        }else if(val == max){
          vecResult.push_back(root->val);
        }
        
        getMap(root->left);
        getMap(root->right);
        return vecResult;
    }
};