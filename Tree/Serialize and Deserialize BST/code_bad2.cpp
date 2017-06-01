/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "";
        }
        string str = "";
        do_serialize(root, str);
        return str;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == ""){
            return nullptr;
        }
        vector<string> vec_str = split(data, "#");
        TreeNode* root;
        int i = 0;
        do_deserialize(root, vec_str, i);
        return root;
    }
  /*  
    string do_serialize(TreeNode* root, string& str){
        if(!root){
            str = str+"-1#";
            return str;
        }else{
            str = str + int2str(root->val)+"#";
        }
        do_serialize(root->left, str);
        do_serialize(root->right, str);
        return str;
    }*/
    
    TreeNode* do_deserialize(TreeNode*& root,  vector<string>& vec_str, int& index){
        int num = str2int(vec_str[index]);
        if(num == -1){
            return nullptr;
        }
        TreeNode* node = new TreeNode(num);
        root = node;
        root->left = do_deserialize(root->left, vec_str, ++index);
        root->right = do_deserialize(root->right, vec_str, ++index);
        return root;
    }
    
    //int 转 string
    string int2str(int int_temp){
        string string_temp;
        stringstream stream;  
        stream<<int_temp;  
        string_temp=stream.str();   //此处也可以用 stream>>string_temp  
        return string_temp;
    } 
    
    //str转int
    int str2int(string string_temp){  
        int int_temp;
        stringstream stream(string_temp);  
        stream>>int_temp;
        return  int_temp;
    }
    
        //字符串分割
   //字符串分割函数
   vector<string> split(string str, string pattern)
   {
         string::size_type pos;
         vector<string> result;
         int size=str.size();
         for(int i=0; i<size; i++)
         {
           pos=str.find(pattern,i);
           if(pos<size)
           {
             std::string s=str.substr(i,pos-i);
             result.push_back(s);
             i=pos+pattern.size()-1;
           }
         }
        return result;
   }
   
  //前序遍历
    string do_serialize(TreeNode* root, string& str) {
         stack<TreeNode*> s;
         TreeNode *pCurrent = root;
         while(!s.empty() || pCurrent){
             if(pCurrent){
                str = str + int2str(pCurrent->val) + "#";
                 s.push(pCurrent);
                 pCurrent = pCurrent->left;
             }else{
                 str = str + "-1#";
                 pCurrent = s.top();
                 s.pop();
                 pCurrent = pCurrent->right;
             }
         }
         return str;
     }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));