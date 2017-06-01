class Solution {
public:
    int findLUSlength(string a, string b) {
        
        int len_a = a.length();
        int len_b = b.length();
        
        if(len_a != len_b){
            int result =(len_a > len_b)?len_a : len_b; 
            return result; 
        }
        
        bool isSame;
        for(int i = 0; i < len_a; i++){
            if(a[i] != b[i]){
                isSame = false;
                return len_a;
            }  
        }
        
        return -1;
    }
};