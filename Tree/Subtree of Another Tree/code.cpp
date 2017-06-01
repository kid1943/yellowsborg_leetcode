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
    bool isSubtree(TreeNode* s, TreeNode* t) {
      
      if(!s){
          return false;
      }
      
      bool b = check(s, t);
      
      if(b){
          return true;
      }
      
      return b || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
    
    bool check(TreeNode* s, TreeNode*t){
        
        if(!s && !t){
            return true;
        }
        
        if(!s&&t || !t&&s){
            return false;
        }
        
        bool b;
        
        if(s->val != t->val){
            b = false;
        }else{
            b = true;
        }
        
        return b && check(s->left, t->left) && check(s->right, t->right);
    }
    
};