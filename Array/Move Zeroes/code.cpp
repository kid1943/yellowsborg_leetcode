class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int x = 0;x < nums.size();x++){
           if(nums[x] == 0){
               exchange(nums, x);
           }
        }
        return;
    }
    
    void exchange(vector<int>& nums, int index){
        int flag = index;
        for(int x = index+1; x < nums.size(); x++){
            if(nums[x]!=0){
                nums[flag] = nums[x];
                nums[x] = 0;
                flag = x;//记录交换位置
            }
        }
    }
};