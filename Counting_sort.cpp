#include <iostream>  
using namespace std;  
int getMax(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max;   
}  
void countSort(int a[], int n) 
{  
   int output[n+1];  
   int max = getMax(a, n);  
   int count[max+1];  
  
  
  for (int i = 0; i <= max; ++i)   
  {  
    count[i] = 0;  
  }  
    
  for (int i = 0; i < n; i++)   
  {  
    count[a[i]]++;  
  }  
  
   for(int i = 1; i<=max; i++)   
      count[i] += count[i-1]; 
   
  for (int i = n - 1; i >= 0; i--) {  
    output[count[a[i]] - 1] = a[i];  
    count[a[i]]--;   
}  
  
   for(int i = 0; i<n; i++) {  
      a[i] = output[i];  
   }  
}  
int main() {  
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n; 
    int a[n];
    cout<<"Enter the elements of an Array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    } 
    cout<<"Before sorting array elements are - \n";  
        for (int i = 0; i < n; i++){  
        cout<<a[i]<<" ";   
        }
    countSort(a, n);  
    cout<<"\nAfter sorting array elements are - \n";    
        for (int i = 0; i < n; i++){
        cout<<a[i]<<" ";   
        }
    return 0;  
}  
