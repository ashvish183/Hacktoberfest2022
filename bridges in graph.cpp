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
#define f(i,x,n) for(ll i=x;i<n;i++)
void dfs(int node,int parent,vector<int> &vis,vector<int> &low,vector<int> &tin,int &timer,vector<int> adj[])
{ 
    vis[node]=1;
    tin[node]=timer;
    low[node]=timer;
    timer++;
    for(auto it:adj[node])
    {
        if(it==parent) continue;
        if(!vis[it])
        {
            dfs(it,node,vis,low,tin,timer,adj);
            low[node]=min(low[node],low[it]);
            if(low[it]>tin[node])
            cout<<node<<" "<<it<<endl;
        }
        else
        {
            low[node]=min(low[node],tin[it]);
        }
    }
} 
int main()
{
ll t;
cin>>t;
while(t--)
{
  ll n,m;
  cin>>n>>m;
  vector<int> adj[n+1];
  for(int i=0;i<m;i++)
  {
      int a,b;
      cin>>a>>b;
      adj[a].pb(b);
      adj[b].pb(a);
  }
  vector<int> low(n+1,-1);
  vector<int> tin(n+1,-1);
  vector<int> vis(n+1,0);
  int timer=0;
  for(int i=0;i<n;i++)
  {
      if(!vis[i])
      dfs(i,-1,vis,low,tin,timer,adj);
  }
}
return 0;
}