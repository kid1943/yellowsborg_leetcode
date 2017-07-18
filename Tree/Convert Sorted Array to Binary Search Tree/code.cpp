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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();       
        if(len == 0) return nullptr;
        TreeNode* root = new TreeNode(nums[(len-1)/2]);
        handle((len-1)/2, 0, len-1, nums, root);       
        return root;
    }
    
    TreeNode* handle(int mid, int l_border, int r_border, vector<int>& nums, TreeNode* node){                
         TreeNode* root_l = nullptr;
         TreeNode* root_r = nullptr;
        
        if(mid == l_border){//mid 没有左节点
            
        }else{
            int l_index = (l_border + (mid-1))/2;
            root_l = new TreeNode(nums[l_index]);
            handle(l_index, l_border, mid-1, nums, root_l);
            node->left = root_l;
        }
          
        if(mid == r_border){//mid 没有右节点
            
        }else{
             int r_index = ((mid+1) + r_border)/2;
            root_r = new TreeNode(nums[r_index]);
            if(r_index == r_border){
                
            }else{
                 handle(r_index, mid+1, r_border, nums, root_r);
            }
            node->right = root_r;
        }    
        return node;
    }  
};