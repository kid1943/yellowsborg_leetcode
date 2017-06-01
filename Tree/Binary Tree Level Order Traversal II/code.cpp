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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vecResult;
        vector<vector<int>> res = coutVec0(root, 0, vecResult);
        reverse(res.begin(), res.end());
        return res;
    }
    vector<vector<int>> coutVec0(TreeNode* root,int level ,vector<vector<int>>& vecResult){
        if(!root){
            return vecResult;
        }
        
       if(level < vecResult.size()){
            //  vecResult[vecResult.size()-1-level].push_back(root->val);
            vecResult[level].push_back(root->val);
       }else if(level == vecResult.size()){
              vector<int> vec;
              vec.push_back(root->val);
            //   vecResult.insert(vecResult.begin(), vec);
            vecResult.push_back(vec);
        }
        ++level;
        coutVec0(root->left, level, vecResult);
        coutVec0(root->right, level, vecResult);
        return vecResult;
     }
};