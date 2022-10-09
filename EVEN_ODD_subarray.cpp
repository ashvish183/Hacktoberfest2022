//----------------------Maximum Even Odd subarray Length---------------
#include<iostream>
#include<algorithm>
using namespace std;

//-----------------------------approach 1:O(n2)--------------------------
//int evenodd(int a[],int n)
//{
//    int res=1;
//    for(int i=0;i<n;i++)
//    {
//        int curr=1;
//        for(int j=i+1;j<n;j++)
//        {
//            if ( (a[j]%2==0 && a[j-1]%2!=0) || (a[j-1]%2==0 && a[j]%2!=0) )
//            curr++;
//            else
//            break;
//            
//        }
//        res=max(res,curr);
//
//    }
//    return res;
//
//}

//--------------------------approach 2: SUBARRAY technique------------------

int evenodd(int a[],int n)
{
    int res=1,curr=1;

    for(int i=1;i<n;i++)
    {
        if( (a[i]%2==0 && a[i-1]%2!=0) || (a[i-1]%2==0 && a[i]%2!=0))
        {curr++;
         res=max(res,curr);
        }
        else
        curr=1; 
    }
    return res;
    
}
int main()
{  
     int a[100],n;
    cout<<" Enter the size of array :";
    cin>>n;

    cout<<"\n enter the elemnts of an array one by one:";
    for(int i=0;i<n;i++)
    cin>>a[i];

    int len=evenodd(a,n);
    cout<<endl<<len;
    return 0;

}