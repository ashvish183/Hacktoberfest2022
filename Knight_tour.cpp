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
#define all(x)      (x).begin(), (x).end()
#define inp(x) for(ll&i:x) cin>>i;
void IOS()
{
 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
   #ifndef ONLINE_JUDGE 
  #endif
}
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr) 
bool issafe(int x1,int y1,vector<vector<int>>&ans)
{
    if(x1>=0 and y1>=0 and x1<ans.size() and y1<ans.size() and ans[x1][y1]==-1)
    return true;
    return false;
}
int solve(int x,int y,vector<vector<int>> &ans,int cnt,int xx[],int yy[])
{
    if(cnt==64)
    return 1;
    int x1,y1;
   for(int i=0;i<ans.size();i++)
   {
         x1=x+xx[i];
         y1=y+yy[i];
         if(issafe(x1,y1,ans))
         {
             ans[x1][y1]=cnt;
            if(solve(x1,y1,ans,cnt+1,xx,yy))
            return 1;
            else
            ans[x1][y1]=-1;
         }
   }
   return 0;
}
int main()
{
IOS();
FAST;
ll n;
//cin>>n;
n=8;
int xx[8]= { 2, 1, -1, -2, -2, -1, 1, 2 };
int yy[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };
vector<vector<int>> ans(n,vector<int>(n,-1));
ans[0][0]=0;
int cnt=1;
if(solve(0,0,ans,cnt,xx,yy))
{
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<n;j++)
     cout<<ans[i][j]<<" ";
     cout<<endl;
 }
}
return 0;
}