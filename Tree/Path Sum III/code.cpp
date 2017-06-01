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
    int result;
    int pathSum(TreeNode* root, int sum) {
        recusion(root, sum);
        return result;
    }
    
    vector<int> recusion(TreeNode* root, int sum){
         vector<int> vecAll;//供父节点选择
         if(root == NULL){
            return vecAll;
         }
        
         if(root->val == sum){
            result++;   
         }
        
         if((root->right == NULL)&&(root->left == NULL)){
            vecAll.push_back(root->val);
            return vecAll;
         }
        
         vector<int> vecLeft = recusion(root->left, sum);
         vector<int> vecRight = recusion(root->right, sum);
       
         vecLeft.insert(vecLeft.end(), vecRight.begin(), vecRight.end()); 
         vecAll = vecLeft;
        
        for(vector<int>::iterator it = vecAll.begin(); it!=vecAll.end(); it++){
            int i = *it;
            int jude = root->val+i;
            if(jude == sum){
                result++;
            }
            *it = *it+root->val;
        }
        vecAll.push_back(root->val);
        return vecAll;
    }
};