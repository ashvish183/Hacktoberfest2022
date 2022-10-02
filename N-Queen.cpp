#include<bits/stdc++.h>
using namespace std;
bool issafe(vector<vector<int>> &v,int x,int y,int n)
{   //check for row
    for(int row=0;row<x;row++)
    {
       if(v[row][y]==1) return false;
    }
    int row=x,col=y;
   while(row>=0 and col>=0)
   {
       if(v[row][col]==1)
       return false;
       row--;
       col--;
   }
   row=x,col=y;
   while(row>=0 and col<n)
   {
       if(v[row][col]==1)
       return false;
       row--;
       col++;
   }
   return true;
}
bool nqueen(vector<vector<int>> &v,int x,int n)
{
   if(x>=n)
   return true;
   for(int col=0;col<n;col++)
   {
       if(issafe(v,x,col,n))
       {
       v[x][col]=1;
       if(nqueen(v,x+1,n))
       return true;
       v[x][col]=0;
       }

   }   
   return false;
} 
int main()
{
int n;
cin>>n;
vector<vector<int>> v(n,vector<int> (n,0));
if(nqueen(v,0,n))
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
    {
        if(v[i][j]==0)
        cout<<"."<<" ";
        else
        cout<<"Q"<<" ";
    }
    cout<<endl;
    }
    
}
return 0;
}