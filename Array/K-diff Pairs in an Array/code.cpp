class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) 
            return 0;
        unordered_map<int,int> m;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            ++m[nums[i]];
        }
           
        int res = 0;
        if(k != 0) {
            for(auto it = m.begin(); it != m.end(); ++it){
               cout<< it->first <<endl; 
               if(m.find(it->first+k) != m.end())//将map中的键值添加k,看能否寻找到对应的键值，如果能找到说明新增一pair
                   ++res;
            }
               
        } else {
            for(auto it = m.begin(); it != m.end(); ++it)
               if(it->second > 1)
                   ++res;
        }
        return res;
    }
};