
class Solution {
public:
    
    bool checkSubset(vector<int>&nums, int n , int part)
    {
        bool t[n+1][part+1];
        for(int i =0; i<=n ; i++)
        {
            for(int j=0; j<=part; j++)
            {
                if(i==0)
                {
                    t[i][j]=false;
                }
                if(j==0)
                {
                    t[i][j]=true;
                }
            }
        }
        
        for(int i =1; i<=n ; i++)
        {
            for(int j=1; j<=part; j++)
            {
                if(nums[i-1]<=j)
                {
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j] ;
                }
                else 
                {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][part];
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i =0; i<n; i++)
        {
            sum+=nums[i];
        }
        
        if(sum%2==0)
        {
            return checkSubset(nums,n,sum/2);
        }
        else
        {
            return false;
        }
    }
};
