/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    int curPointer;//当前的位置 
    vector<TreeNode*> vec;
    BSTIterator(TreeNode *root) {
       inOrderTraverse(root, vec);
       curPointer = -1;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(vec.size() == 0){
            return false;
        }
        int b =  (vec.size()-1) - curPointer;
        if(b){
            return true;
        }else{
            return false;
        }
    }

    /** @return the next smallest number */
    int next() {
         ++curPointer;
        TreeNode* node = vec[curPointer];
        return node->val;
    }
    
    vector<TreeNode*> inOrderTraverse(TreeNode* root, vector<TreeNode*>& vec){
        if(!root){
            return vec;
        }
        inOrderTraverse(root->left, vec);
        vec.push_back(root);
        inOrderTraverse(root->right, vec);
        return vec;
    }
};




/*class BSTIterator {
private:
    TreeNode *current = NULL; 
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode *root) {
         // initialize the current pointer
        current = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        while(current){
            s.push(current);
            current = current->left;
        }
        if(s.empty()){
            return false;
        }
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = s.top();
        s.pop();
        current = node->right;
        return node->val;
    }
};
*/

/*class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        find_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (st.empty())
            return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* top = st.top();
        st.pop();
        if (top->right != NULL)
            find_left(top->right);
            
        return top->val;
    }
    
    /** put all the left child() of root */
    void find_left(TreeNode* root)
    {
        TreeNode* p = root;
        while (p != NULL)
        {
            st.push(p);
            p = p->left;
        }
    }
};*/

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */