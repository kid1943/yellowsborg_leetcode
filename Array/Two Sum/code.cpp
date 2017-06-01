public class Solution {
    public int[] twoSum(int[] nums, int target) {
        for(int i = 0;i < nums.length-1; i++){
            int f = nums[i];
            for(int j = i+1; j<nums.length; j++){
                int s = nums[j];
                if((f + s) == target){
                    int[] arrs = new int[]{i,j};
                    return arrs;
                }
            }
        }
       return null;
    }
}