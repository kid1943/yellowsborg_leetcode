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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vecResult;
        
        if(!root){
            return vecResult;
        }
        
        queue<TreeNode*> q;
        queue<int> levq;
        q.push(root);
        levq.push(1);
        while(!q.empty()){
            TreeNode* node = q.front();
            int level = levq.front();
            q.pop();
            levq.pop();
            if(vecResult.size() < level){
                vector<int> vec;
                vec.push_back(node->val);
                vecResult.push_back(vec);
            }else{
                vecResult[level-1].push_back(node->val);
            }
            
            ++level;
            if(node->left){
                q.push(node->left);
                levq.push(level);
            }
            
            if(node->right){
                q.push(node->right);
                levq.push(level);
            }
        }
        return vecResult;
    }
};