class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--; k--;//instead of writing this way u can also write... nums1[k--] = nums1[i--]
            }
            else
            {
                nums1[k--] = nums2[j--];

            }
        }
        while(i>=0)
        {
            nums1[k--] = nums1[i--];
        }
        while(j>=0)
        {
            nums1[k--] = nums2[i--];
        }

    }
};//this code was showing run time error while submitting
//TC = O(m+n);
//SC =O(1);



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         int a=m-1;
        int b=n-1;
        int i=m+n-1;    // calculate the index of the last element of the merged array
        
        // go from the back by A and B and compare and put to the A element which is larger
        while(a>=0 && b>=0){
            if(nums1[a]>nums2[b])   nums1[i--]=nums1[a--];
            else            nums1[i--]=nums2[b--];
        }
        
        // if B is longer than A just copy the rest of B to A location, otherwise no need to do anything
        while(b>=0)         nums1[i--]=nums2[b--];
    
        
    }
};