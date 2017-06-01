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
        string str;
        queue<TreeNode*> q;
        q.push(root);
        
        queue<int> qLevel;
        qLevel.push(1);
        str = int2str(root->val)+"#";
        
        
        int depth = getDepth(root,0);
        
        while(q.size()){
            TreeNode* node = q.front();
            int level = qLevel.front();
            q.pop();
            qLevel.pop();
            int i = level+1;
            if(node->left){
                q.push(node->left); 
                qLevel.push(i);
                str = str + int2str(node->left->val)+"#";
            }else if(level < depth){
                TreeNode* node = new TreeNode(-1);  
                q.push(node);  
                qLevel.push(i);
                str = str + "-1#";
            }
            
               if(node->right){
                 q.push(node->right);
                 qLevel.push(i);
                 str = str + int2str(node->right->val)+"#";
               }else if(level < depth){
                 TreeNode* node = new TreeNode(-1);  
                 q.push(node);    
                 qLevel.push(i);
                 str = str + "-1#";
               }
        }
        return str;
    }
    
    
    int getDepth(TreeNode* root, int dp){
        if(!root){
            return dp;
        }
        int dp0 = getDepth(root->left, dp);
        int dp1 = getDepth(root->right, dp);
        int i = dp0>=dp1?dp0:dp1;
        ++i;
        return i;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == ""){
            return nullptr;
        }
        
        TreeNode* root;
        
        int len = data.size();
        
        for(int i = 0; i < len; i++){
          cout<< data[i] <<endl;
        }
        
        vector<string> vec = split(data, "#");
        unordered_map<int, TreeNode*> mapNode;
        
        for(int i = 0; i < vec.size(); i++){
            if(!mapNode[i]){
                int num = str2int(vec[i]);
                TreeNode* node = new TreeNode(num);
                mapNode[i] = node;
            }
            
            int tem = 2*i;
            
            if(tem+1 < vec.size()){
                if(!mapNode[tem+1]){
                    int val = str2int(vec[tem+1]);
                    if(val == -1){
                         mapNode[tem+1] = nullptr;
                    }else{
                        TreeNode* node = new  TreeNode(str2int(vec[tem+1]));
                        mapNode[tem+1] = node;
                    }
                }
                mapNode[i]->left = mapNode[tem+1];
            }
            
            if(tem+2 < vec.size()){
                 if(!mapNode[tem+2]){
                    int val = str2int(vec[tem+2]);
                    if(val == -1){
                        mapNode[tem+2] = nullptr;
                    }else{
                        TreeNode* node = new TreeNode(str2int(vec[tem+2]));
                        mapNode[tem+2] = node;
                    }
                }
                mapNode[i]->right = mapNode[tem+2];
            }
        }
        return  mapNode[0];
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
    
    // 整形转字符串
    string int2str(const int &int_temp)  {  
        stringstream stream;  
        stream<<int_temp;  
        string str_temp=stream.str();   //此处也可以用 stream>>string_temp  
        return str_temp;
    }
   
   //字符串转整形
   int str2int(string str){
      int i = atoi(str.c_str());
      return i;
   }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));