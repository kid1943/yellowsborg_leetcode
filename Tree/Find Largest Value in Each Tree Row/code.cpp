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
    vector<int> largestValues(TreeNode* root) {
        vector<int> vecRes;
        getRes(root, 1, vecRes);
        return vecRes;
    }
    
    
    vector<int> getRes(TreeNode* root, int level, vector<int>& vecRes){
        cout<< level <<endl;
        if(!root){
            return vecRes;
        }
        if(level > vecRes.size()){
            vecRes.push_back(root->val);
        }else if(root->val > vecRes[level-1]){
                cout<< vecRes[level-1] <<endl;
                vecRes[level-1] = root->val;
        }
        ++level;
        getRes(root->left, level, vecRes);
        getRes(root->right, level, vecRes);
        return vecRes;
    }
    
};