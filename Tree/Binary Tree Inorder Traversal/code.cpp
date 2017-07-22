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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        return traver(root, vec);
    }
    
    //递归实现
    vector<int> traver(TreeNode* root, vector<int>& vec){        
        if(!root){
            return vec;
        }        
        traver(root->left, vec);
        vec.push_back(root->val);
        traver(root->right, vec);
        return vec;
    }
	
	
	/*
	非递归实现但会改变树的结构
	vector<int> traverse(TreeNode* root, vector<int>& vec) {
           stack<TreeNode*> s;
           s.push(root);
           while(!s.empty()){
             TreeNode* node = s.top();
              if(node ->left){
                  s.push(node ->left);
                  node ->left = NULL;//防止重复遍历
              }else{
                  s.pop();
                  vec->push(node->val);
                  if(node->right){
                     s.push(node->right);
                  }   
              } 
            }
          return vec;
    }
   */
   
   
   
   /*
   vector<int> traverse(TreeNode* root, vector<int>& vec) {
	   unordered_map<TreeNode*, bool> map;
	   stack<TreeNode*> s;
	   s.push(root);
	   while(!s.empty()){
		 TreeNode* node = s.top();
		  if(node ->left && !map[node]){
			  s.push(node ->left);
			  map[node->left] = true;
		  }else{
			  s.pop();
			  vec->push(node->val);
			  if(node->right){
				 s.push(node->right);
			  }   
		  } 
	  }
      return vec;
   }
   */
   
   
   /*
     vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vector;
        stack<TreeNode *> stack;
        TreeNode *pCurrent = root;

        while(!stack.empty() || pCurrent)
        {
            if(pCurrent)
            {
                //同一根节点下的左右节点，左节点比右节点先出栈（即左节点后进栈,其实最后所有进栈的节点都可以视左一个树中的中间节点。）
                stack.push(pCurrent);
                pCurrent = pCurrent->left;//若左节点为空则，该节点可以等同为中间节点，相对于其右节点先出栈（后进栈）
            }//节点为空就出栈
            else
            {//当左子节点或右子节点没有左子节点时 改节点出栈
                TreeNode *pNode = stack.top();
                vector.push_back(pNode->val);
                stack.pop();
                pCurrent = pNode->right;
            }
        }
        return vector;
    }
	*/
    
    
};