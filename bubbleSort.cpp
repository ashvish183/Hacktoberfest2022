#include<iostream>
using namespace std;
class buble_sort
{public:
 int temp;
 buble_sort()
 {
  int arr[5]={5,3,2,4,1};
  for (int i=0;i<=(5-1)-1;i++)
  {
   for (int j=0;j<=(5-1)-1-i;j++)
   {
    if (arr[j]>arr[j+1])
    {
     temp=arr[j];
     arr[j]=arr[j+1];
     arr[j+1]=temp;
    }
   }
  }
  for (int k=0 ; k<5 ; k++)
  {
   cout<<","<<arr[k];
  }
 }
};
int main()
{
 buble_sort obj;
}