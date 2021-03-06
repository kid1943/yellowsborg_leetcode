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

    vector<int> preorderTraversal(TreeNode* root) {                  
		 stack<TreeNode*> s;
         vector<int> vec;  
         if(!root){
             return vec;
         }
         vec.push_back(root->val);
         s.push(root);
         
         while(!s.empty()){
             TreeNode *pNode = s.top();
             if(pNode->left){
                vec.push_back(pNode->left->val);
                s.push(pNode->left);
                pNode->left = NULL;
             }else{
                s.pop();
                if(pNode->right){
                  vec.push_back(pNode->right->val); 
                  s.push(pNode->right);
                }
             }
         }
         return vec;
    }

      /* 要使用到map
         vector<int> preorderTraversal(TreeNode* root){  
         stack<TreeNode*> s;
         vector<int> vec;
         unordered_map<TreeNode*, bool> map; 
         
         if(!root){
             return vec;
         }
         
         s.push(root);
         vec.push_back(root->val);
         
         while(!s.empty()){
             TreeNode* node = s.top();
             if(node->left && !map[node->left]){
                 map[node->left] = true;
                 vec.push_back(node->left->val);
                 s.push(node->left);
             }else{
                 s.pop();
                 if(node->right && !map[node->right]){
                     map[node->right] = true;
                     vec.push_back(node->right->val);
                     s.push(node->right);
                 }
             }
         }
         return vec;
        }*/
		
	/*不使用map和不改变树结构
         vector<int> preorderTraversal(TreeNode* root) {
         stack<TreeNode*> s;
         vector<int> vec;
         TreeNode *pCurrent = root;
         while(!s.empty() || pCurrent){        
             if(pCurrent){
                 vec.push_back(pCurrent->val);
                 s.push(pCurrent);
                 pCurrent = pCurrent->left;
             }else{
                 pCurrent = s.top();
                 s.pop();
                 pCurrent = pCurrent->right;
             }
         }
         return vec;
     }*/
	 
	 
	/*
	vector<int> preorderTraversal(TreeNode* root){		 
	    vector<int> vec;  
        if (root == nullptr) return vec;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            root = st.top();
            st.pop();
			vec.push_back(root->val);
            if (root->right != nullptr) st.push(root->right);
            if (root->left != nullptr) st.push(root->left);
        }
        return vec;
    }
	*/
	
 /*
  递归遍历 
      vector<int>  preorderTraversal(TreeNode* root, vector<int>& vec){
        if(!root){
            return vec;
        }
        vec.push_back(root->val);
        preorderTraversal(root->left, vec);
        preorderTraversal(root->right, vec);
        return vec;
    }
  */
};