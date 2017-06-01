
class Solution {
public:
    string reverseWords(string s) {
        
        std::string result_str;
        std::string pattern = " ";
        
        
        reverse(s.begin(),s.end()); 
        std::vector<std::string> result = split(s,pattern);
        for(int i=0; i<result.size(); i++)
        {
          std::cout<<result[i]<<std::endl;
        }
        
        for(int i = 0; i<result.size(); i++){
            if(i == result.size()-1){
                result_str += result[result.size()-1-i];
            }else{
                 result_str += result[result.size()-1-i]+" ";
            }    
        }
        
        return result_str;
    }
    
  std::vector<std::string> split(std::string str,std::string pattern)
  {
    std::string::size_type pos;
    std::vector<std::string> result;
    str+=pattern;//扩展字符串以方便操作
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
};