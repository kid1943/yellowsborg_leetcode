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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(((p==NULL)&&(q!=NULL))||((q==NULL)&&(p!=NULL))){
            return false;
        }
        
        if((p==NULL)&&(q==NULL)){
            return true;
        }
        
        bool b0 = isSameTree(p->left, q->left);
        bool b1 = isSameTree(p->right, q->right);
        cout<< b0<<"--"<<b1<<endl;
        if(p->val == q->val){
            return b0&&b1;
        }else{
            return false;
        }
    }
};