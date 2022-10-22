#include<iostream>
using namespace std;
void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min=arr[i];
        int minIndex=i;
      
      //find minimum element in the array
        for(int j=i+1;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                minIndex=j;
            }            
        }
        //swap
        int temp=arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
    }
}
int main(){
    int arr[99];
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    cout<<"Enter the array which is to be sorted"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionSort(arr,n);
    cout<<"The sorted array is: "<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i];
    }

}
