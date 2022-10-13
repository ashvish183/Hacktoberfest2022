/* Q. Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the k’th position of the final sorted array. */

#include <bits/stdc++.h>
using namespace std;

int kthElement(int n1,int a[],int n2,int b[],int k)
{
    vector<int> v;
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(a[i]<b[j]) v.push_back(a[i++]);
        else v.push_back(b[j++]);
    }
    for(;i<n1;i++) v.push_back(a[i]);
    for(;j<n2;j++) v.push_back(b[j]);
    
    return v[k-1];
}
 
// Driver Code
int main()
{
    int n1,n2,k;
    cin >> n1;
    int a[n1];
    for(int i=0;i<n1;i++){
      cin >> a[i];
    }
    cin >> n2;
    int b[n2];
    for(int i=0;i<n2;i++){
      cin >> b[i];
    }
    cin >> k;
    
    cout << kthElement(n1,a,n2,b,k);
    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(n1+n2)
 
