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
        string res;
        queue<TreeNode*> q;
        queue<int> level;
        
        q.push(root);
        level.push(0);
        int p_level = 0;
        
        while(q.size()){            
          TreeNode* node = q.front();
          int l = level.front();
          bool has_child = false;//判断是否有子节点
          string val;
          
          level.pop();
          q.pop(); 
                                
          if(node == nullptr){
              val = "@";
          }else{
              val = to_string(node->val);
          }            
            
         if(l > p_level){
              // res = res + "#" + val + ","; 这样拼接字符串内存会溢出
             res.append("#" + val + ",");
              p_level = l;
          }else{
              // res = res + val + ",";
             res.append(val + ",");
          }  
            
          if(!node){
              continue;
          }  
            
           q.push(node->left);
           level.push(l+1);              
           q.push(node->right);
           level.push(l+1);          
        }
        // cout<< "res:" << res <<endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout<< "fuckkk" <<endl;
         TreeNode* node;
        if(data == ""){
            return nullptr;
        }
              
        vector<string> vec_level = split(data, "#");
        int count = vec_level.size();
        queue<TreeNode*> q;
        
        if(count == 1){//只有一个节点
             vector<string> vec = split(vec_level[0], ",");
             int i = stoi(vec[0]);
             node = new TreeNode(i);
             return node;
        }
        
        for (int i = 0; i < count - 1;i++)
        {        
            string p_nodes = vec_level[i];//父层节点
            string c_nodes = vec_level[i+1];//子层节点                                
            
            vector<string> p_vecs = split(p_nodes, ",");//父节点所有节点集合
            vector<string> c_vecs = split(c_nodes, ",");//子节点所有节点集合
        
            int p_size = p_vecs.size()-1;//因为逗号后算一个字符,所以都要减一
            int c_size = c_vecs.size()-1;
            
            if(i == 0){
                node = new TreeNode(stoi(p_vecs[0]));
                q.push(node);
            }
            
            for(int i = 0; i < p_size; i++){                    
               if(c_size - 1 < 2*i){
                   break;
               } 
                
               TreeNode* n = q.front(); 
               q.pop(); 
                
               if(c_vecs[2*i] != "@"){ 
                   TreeNode* l_node = new TreeNode(stoi(c_vecs[2*i]));                   
                   n->left = l_node; 
                   q.push(l_node);
               }
                               
               if(c_vecs[2*i+1] != "@"){
                  TreeNode* r_node = new TreeNode(stoi(c_vecs[2*i+1]));                 
                  n->right = r_node;
                  q.push(r_node);
               }                              
            }
        }   
        return node;        
    }
    
    //字符串分割函数
    vector<string> split(string str, string pattern)
    {
      string::size_type pos;
      vector<string> result;
      str+=pattern;//扩展字符串以方便操作
      int size=str.size();

      for(int i=0; i<size; i++)
      {
        pos=str.find(pattern,i);
        if(pos<size)
        {
          string s=str.substr(i,pos-i);
          result.push_back(s);
          i=pos+pattern.size()-1;
        }
      }
      return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));