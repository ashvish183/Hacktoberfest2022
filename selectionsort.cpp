#include<iostream>
using namespace std;
//selection sort
//find the min element in unsorted array
//and swap it with element at begining

int main()
{
    int n;
    cout<<"Enter the number of elements of an array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of an array :";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for (int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
           if(arr[j]<arr[i])
           {
              int temp=arr[i];
              arr[i] = arr[j];
              arr[j] = temp ;

           } 
           
        }
    }
    cout<<"our sorted array is : ";
    for (int i = 0; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
