//--------------------------------------frequencies of elements in an array-------------------------
#include<iostream>
using namespace std;

void FREQ(int a[],int n)
{
    int freq=1,i=1;
    while(i<n)
    {
        while(i<n && a[i]==a[i-1] )
        {
            freq++;
            i++;
        }
        cout<<endl<<a[i-1]<<" ="<<freq;
        freq=1;
        i++;
    }
    if(n==1|| a[n-1]!=a[n-2])
    cout<<endl<<a[n-1]<<" = 1";                              //if last element is different  or there is only one element in the array 

}

int main()
{
    int a[100],n;
    cout<<" enter the size:";
    cin>>n;

    cout<<endl<<" enter the elements :";
    for(int i=0;i<n;i++)
    cin>>a[i];
    FREQ(a,n);
     return 0;

}