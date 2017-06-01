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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, bool> map;
        TreeNode* target_node = nullptr;
        find(root, p, q, target_node);
        return target_node;
    }
    
    unordered_map<TreeNode*, bool> find(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& target_node){
           unordered_map<TreeNode*, bool> map_mine;   
        if(!root){
            return map_mine;
        }
        
      unordered_map<TreeNode*, bool> map0 = find(root->left, p, q, target_node);
      unordered_map<TreeNode*, bool> map1 = find(root->right, p, q, target_node);
    
        
       if(root->val == p->val){
             map_mine[p] = true;
        }
        
        if(root->val == q->val){
            map_mine[q] = true;
        }
        
        if(map0[p]){
             map_mine[p] = true;
        }else if(map0[q]){
            map_mine[q] = true;
        }
        
        if(map1[p]){
             map_mine[p] = true;
        }else if(map1[q]){
             map_mine[q] = true;
        }
        
        
        if(target_node == nullptr){
            if(map_mine[p]&&map_mine[q]){
                target_node = root;
            }
        }
        
        
        return map_mine;
    }
    
};