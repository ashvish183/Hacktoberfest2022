class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(target-nums[i]) != mp.end())
            {
                ans = {mp[target-nums[i]] , i};
                break;
            }
            else 
            {
                mp[nums[i]] = i;
            }
        }
        
        return ans;
    }
};
