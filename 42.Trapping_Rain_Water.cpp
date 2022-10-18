// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
//Output: 6


class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        if(N == 0) return 0;
        int left = 0, right = N-1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        while(left < right){
            if(height[left] > leftMax){
                leftMax = height[left];
            }
            if(height[right] > rightMax){
                rightMax = height[right];
            }
            if(leftMax < rightMax){
                //use leftMax to substract because leftMax is min(leftMax, rightMax)
                ans += max(0, leftMax - height[left]);
                // cout << "[" << left << ", " << right << "] " << leftMax << " " << rightMax << " " << ans << endl;
                left++;
            }else{
                ans += max(0, rightMax - height[right]);
                // cout << "[" << left << ", " << right << "] " << leftMax << " " << rightMax << " " << ans << endl;
                right--;
            }
        }
        return ans;
    }
};