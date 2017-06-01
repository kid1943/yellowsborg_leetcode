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
    int kthSmallest(TreeNode* root, int k) {
        
        
        if(!root){
            return 0;
        }
        
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        TreeNode* nCur = root;
        
        vector<TreeNode*> vec;
        
        while(!nodeStack.empty()){
            
            if(nCur){
                nCur = nCur->left;
                if(nCur){
                    nodeStack.push(nCur);
                }
            }else{
                TreeNode* node  = nodeStack.top();
                nodeStack.pop();
                //这是倒数的node
                vec.push_back(node);
                
                if(vec.size() == k){
                    return vec[vec.size()-1]->val;
                }
                
                nCur = node->right;
                if(nCur){
                    nodeStack.push(nCur);
                }
            }
        }
        
        return 0;
        
        
    }
};