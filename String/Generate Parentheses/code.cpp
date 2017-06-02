class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int cout_left = 0;
        int cout_right = 0;
        string result = "";
        vector<string> vec;
        resolve(vec,n ,result, cout_left, cout_right);
        return vec;
    }
    
    
    void resolve(vector<string>& vec,int n , string str, int c_left, int c_right){
        if(c_right == n){
            vec.push_back(str);
            return ;
        }
        
        if(c_left < n){
            string str_l = str + "(";
            int tmp = c_left + 1;
            resolve(vec, n, str_l, tmp , c_right);
        }
        
        if(c_right < c_left){
            string str_r = str + ")";
            int tmp = c_right + 1;
            resolve(vec, n , str_r, c_left , tmp);
        }
    }
    
};