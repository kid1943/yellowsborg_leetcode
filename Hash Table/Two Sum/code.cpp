#include <string.h>

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        string r1 = "qwertyuiop";
        string r2 = "asdfghjkl";
        string r3 = "zxcvbnm";
    
        vector<string> resultWords;
        
        for(int i=0; i<words.size(); i++ ){
            int flag1 = 0;
            int flag2 = 0;
            int flag3 = 0;
            string word = words[i];
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            for (char c : word)  {
                 if(strchr("qwertyuiop",c)){
                     ++flag1;
                 }
                 
                 if(strchr("asdfghjkl",c)){
                     ++flag2;
                 }
                 
                 if(strchr("zxcvbnm",c)){
                     ++flag3;
                 }
            }
            if((flag1==word.size())||(flag2==word.size())||(flag3==word.size())){
                resultWords.push_back(words[i]);   
            }
        }
        return resultWords;
    }
    
};