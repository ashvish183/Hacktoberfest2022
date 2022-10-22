// Problem Link : https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();
        map<int, int>mp;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(target - a[i]) != mp.end())
            {
                return {mp[target - a[i]], i};
            }
            mp[a[i]] = i;
        }
        return { -1, -1};
    }
};
