class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string result;
        return handle(nums, 0, result);
    }
    
    string handle(vector<int>& nums, int index, string& str){
         string num = to_string(nums[index]);
        
         if(nums.size() == 2){
             string num1 = to_string(nums[1]);
             return num+"/"+num1;
         }
        
         if(index == (nums.size()-1) && nums.size()>1){
             str = str + num+")";
             return str;
         }else if(index == (nums.size()-1) && (nums.size() == 1)){
             return num;
         }
         
         if(index == 0){
             str = str + num+"/(";
         }else{
             str = str + num + "/";
         }
         return handle(nums, ++index, str);
    }
    
    
    
    
};