class Solution
{
    public:
    int trap(vector<int>& height)
    {
        int n = height.size();
        int left_max[n+1];
        int right_max[n+1];
        
        int large=0;
        for(int i=0;i<n;i++)
        {
            large=max(large,height[i]);
            left_max[i] = large;
        }
        large=0;
        for(int i=n-1;i>=0;i--)
        {
            large=max(large,height[i]);
            right_max[i] = large;
        }
        
        int water=0;
        for(int i=0;i<n;i++)
        {
            water += min(left_max[i],right_max[i])-height[i];
        }
        return water;
    }
};
