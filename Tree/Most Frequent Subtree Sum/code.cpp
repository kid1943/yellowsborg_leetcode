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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> map;
        vector<int> vec;
        int maxFrq = 0;
        if(!root){
            return vec;
        }
      
        findOutSum(root, map, vec, maxFrq);
        return vec;
    }
    
    int findOutSum(TreeNode* root, unordered_map<int, int>& map,vector<int>& vec ,int& maxFrq){
        if(!root){
            return 0;
        }
        int leftSum = findOutSum(root->left, map, vec, maxFrq);
        int rightSum = findOutSum(root->right, map, vec, maxFrq);
        int sum = root->val+leftSum+rightSum;
        
        ++map[sum];
        
        if(map[sum] > maxFrq){
            vec.clear();
            maxFrq = map[sum];
            vec.push_back(sum);
        }else if(map[sum] == maxFrq){
            vec.push_back(sum);
        }
        return sum;
    }
};