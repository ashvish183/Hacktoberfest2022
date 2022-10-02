#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vpi vector<pi>
#define vpll vector<pll>
#define sz(x) ((int)(x).size())
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define  uniq(a) a.resize(unique(a.begin(), a.end()) - a.begin());

bool issafe(vector<vector<int>> &a,int row,int col,int n,vector<vector<int>> &vis)
{
    if (row == -1 || row == n || col == -1 ||
                  col == n || vis[row][col]
                           || a[row][col] == 0)
        return false;
    return true;
}
vector<string> ans;
void rat(vector<vector<int>> &a,int row,int col,int n,vector<vector<int>> &vis,string path)
{    if (row == -1 || row == n || col == -1
               || col == n || vis[row][col]
                           || a[row][col] == 0)
        return;
   if(row==n-1 and col==n-1)
   {
       ans.pb(path);
       return;
   }
   vis[row][col]=1;
   if(issafe(a,row+1,col,n,vis))
   {
       path.pb('D');
       rat(a,row+1,col,n,vis,path);
       path.pop_back();
   }
   if(issafe(a,row,col-1,n,vis))
   {
       path.pb('L');
       rat(a,row,col-1,n,vis,path);
       path.pop_back();
   }
   if(issafe(a,row,col+1,n,vis))
   {
       path.pb('R');
       rat(a,row,col+1,n,vis,path);
       path.pop_back();
   }
   if(issafe(a,row-1,col,n,vis))
   {
       path.pb('U');
       rat(a,row-1,col,n,vis,path);
       path.pop_back();
   }
   vis[row][col]=0;
   
}
/*
bool issafe(vector<vector<int>> &a,int x,int y,int n)
{
    if(x<n and y<n and a[x][y]==1)
    return true;
    return false;
}
 bool ratinmaze(vector<vector<int>> &a,int x,int y,int n,vector<vector<int>> &vis)
{
  if(x==n-1 && y==n-1 and a[x][y]==1 )
  {
      vis[x][y]=1;
      return true;
  }
  if(issafe(a,x,y,n))
  {
     vis[x][y]=1;
     if(ratinmaze(a,x+1,y,n,vis))
     {
         return true;
     }
     if(ratinmaze(a,x,y+1,n,vis))
     {
         return true;
     }
     
     vis[x][y]=0;
     return false;
     
  }
  return false;
} */
int main()
{ 
    int n;
 cin>>n;
 
 vector<vector<int>> a( n , vector<int> (n));
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<n;j++)
     {
         cin>>a[i][j];
     }
 }
    vector<vector<int>> vis(n,vector<int>(n,0));
    string path;
    rat(a,0,0,n,vis,path);
     for(int i=0;i<ans.size();i++)
      cout<<ans[i]<<endl;
  
    
/* if(ratinmaze(a,0,0,n,vis)) cout<<"YES\n";
else cout<<"NO\n";
for(int i=0;i<n;i++)
 {
     for(int j=0;j<n;j++)
     {
         cout<<vis[i][j]<<" ";
     }
     cout<<endl;
 }
 string s;
 for(int i=0,j=0;i!=n-1 || j!=n-1;)
 {
   if(i!=n-1 and vis[i+1][j]==1)
   {s.pb('D');i++;}
   else if(j!=n-1 and vis[i][j+1]==1)
   {s.pb('R');j++;}
   
 }
 cout<<s<<endl; */
return 0;
}