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
    TreeNode* deleteNode(TreeNode* root, int key) {
        root = deleteNodeitem(root, key);
        return root; 
    }
    
    TreeNode* deleteNodeitem(TreeNode* root, int key){
       
        TreeNode* p = root;//the keynode to delete
        TreeNode* pp = root;//parentNode of the keynode
        TreeNode* s;//the node to replace the keynode
        TreeNode* ps;//parent node of replacenode
         
        //findout the keynode p and its parant node pp
        while((p != NULL)&&(p->val != key)){
            pp = p;
            if(key > p->val){
               p = p->right;    
            }else if(key < p->val){
               p = p->left;
            }
        }
         
        if(p == NULL){
            return root;
         }
       
        //state1 node p have 2 nonull childnode
        if((p->left!=NULL)&&(p->right!=NULL)){
            //find the biggest node in the right tree
            s = p->right;
            ps = p;
            while(s->left != NULL){
                ps = s;
                s = s->left;
            }
           
           TreeNode q = {s->val}; q.left = p->left; q.right = p->right;
            if(pp->left == p){
                pp->left = &q;
            }else if(pp->right == p){
                pp->right = &q;
            }else if(p == root){//要删除的节点就是根节点
                pp->val = q.val;
                cout<< "要删除的节点就是根节点" <<endl;
            }
            
            //make the s node to delete 找出节点s所对应的父节点
            if(ps != p){
                pp = ps;
            }else if((p == ps)&&(p!=root)){//当s的父节点即为p节点时
                pp = &q;
                cout<< "当s的父节点即为p节点时" <<endl;
            }
            p = s;//it must one left child of p if p has child
        }
        
        //statue2 node p have at most one nonull childnode
        TreeNode* pc = p;//the child of p , if it has. 
        if(p->left != NULL){
            pc = p->left;
        }else if(p->right != NULL){
            pc = p->right;
        }else{
            pc = NULL;//p has no child
        }
    
        if(pp->left == p){
            pp->left = pc;
        }else if(pp->right == p){
            pp->right = pc;
        }else{
            root = pc;//根节点就是需要删除的节点
        }
        //  delete p;
        return root;
    }
};