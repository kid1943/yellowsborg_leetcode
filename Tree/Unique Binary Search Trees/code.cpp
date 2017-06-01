

//超时解法
class Solution {
public:
    int numTrees(int n) {
        return resolve(1, n);
    }
    
    int resolve(int index, int n){
        int result = 0;
         if(index >= n){
             return 1;
         }
         for(int i = index;i <= n ;i++){
              result += resolve(index, i-1)*resolve(i+1, n);
         }
         return result;
    };
};