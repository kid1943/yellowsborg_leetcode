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
    int rob(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        int sum0 = getSum(root, true);
        int sum1 = getSum(root, false);
        return sum0 > sum1 ? sum0 : sum1;
    }
    
    int getSum(TreeNode* root ,bool canRob){//cout当前节点是第几个连续不抢的节点
                                                      //获取当前打劫节点能获取到的最大值 canRob是指root对应的子节点是否可以打劫        
        if(root == nullptr){
            return 0;
        }
        
        if(canRob){//root不抢  那么root左右节点可以选择抢或不抢            
            vector<int> vec;
            int sum_l0 = getSum(root->left, true);//可以抢
            int sum_r0 = getSum(root->right, true);
                         
            int sum_l1 = getSum(root->left, false);//不可以抢  
            int sum_r1 = getSum(root->right, false); 
            
            int sum0 = sum_l0 + sum_r0;
            int sum1 = sum_l0 + sum_r1;
            int sum2 = sum_l1 + sum_r0;
            int sum3 = sum_l1 + sum_r1;
            
            vec.push_back(sum0);
            vec.push_back(sum1);
            vec.push_back(sum2);
            vec.push_back(sum3);
            int sum = getMaxSum(vec);        
            return sum;                 
        }else{//root 已抢            
            int sum_l = getSum(root->left, true);
            int sum_r = getSum(root->right, true);
            return sum_l + sum_r + root->val;
        }
    }
    
    int getMaxSum(vector<int> vec){
       std::sort(vec.begin(),vec.end());
       return vec[3];
    }   
};