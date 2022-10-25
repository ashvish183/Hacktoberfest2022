class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int arrsum = 0;
        int expsum = (n*(n+1))/2;
        for(int i=0; i<n; i++)
        {
            arrsum = arrsum+nums[i];
        }
        int diff = expsum - arrsum;
        return diff;
    }
};