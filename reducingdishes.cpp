class Solution {
public:
    
    int solve(vector<int>&sat , int index , int time,vector<vector<int>>&dp){
        int n=sat.size();
        // checking base conditon,if index has reached the end point the no need to calc further
        if(index==n) return 0;
        
        //if dp has already valued stored  in it
        if(dp[index][time]!=-1){
            return dp[index][time];
        }
        
        // including the dish to cook , therefore index+1 and time+1
        int incl = sat[index]*(time+1) + solve(sat , index+1 , time+1,dp);
        
        //dont include this dish to cook and move further, therefore index+1 and time remain same 
        int excl = 0+ solve(sat , index+1 , time,dp);
        
        //storing the maximum ans in dp 
        dp[index][time]=max(incl , excl);
        
        //
        return dp[index][time];
        
        
    }
    
    
    int maxSatisfaction(vector<int>& sat) {
        
        //sort the array to get the maximum result
        sort(sat.begin() , sat.end());
        
        //formation of 2D dp vector
        vector<vector<int>> dp(sat.size()+1 , vector<int>(sat.size()+1 ,-1));
        
        return solve(sat , 0 , 0,dp);
    }
};
