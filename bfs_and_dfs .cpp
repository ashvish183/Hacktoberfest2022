#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
ll mypow(ll a, ll b) {
ll res = 1;
while (b > 0) {
if (b & 1)
res = res * a;
a = a * a;
b >>= 1;
}
return res;
} 
ll mypow(ll a, ll b, ll m) {
a %= m;
ll res = 1;
while (b > 0) {
if (b & 1)
res = res * a % m;
a = a * a % m;
b >>= 1;
}
return res;
}
using namespace std;
int n,e;
unordered_map<char,vector<char>> adj; 
void BFS(char src,char dest)
{
    unordered_map<char,int> dis;
    for(auto x:adj)
    {
        char cityname=x.ff;
        dis[cityname]=INT_MAX;

    }
    unordered_map<char,char> par;
    queue<char> q;
    q.push(src);
    dis[src]=0;
    while(!q.empty())
    {
      auto u=q.front();
      cout<<u<<" ";
      q.pop();
      for(auto x:adj[u])
      {
          if(dis[x]==INT_MAX)
          {
              q.push(x);
              dis[x]=dis[u]+1;
              par[x]=u;
          }
      }
    }
    cout<<"shortest distance from "<<src<<" to "<<dest<<" is:"<<dis[dest]<<"\n";
    while(dest!=src)
    {
        cout<<dest<<"<--";
        dest=par[dest];
    }
    cout<<src<<"\n";
  
}
unordered_map<char,bool> vis;

void DFS(char src)
{
 cout<<"DFS "<<src<<"\n";
 vis[src]=true;
 for(auto x:adj[src])
 {
     if(!vis[x])
     DFS(x);
 }


}
int main()
{
    /*
       
    b-----d------m
    |   / | 
    | /   |  
    k     | 
     \    |
      \  /
       c---------a
    
    */
FAST;
cin>>n>>e;
for(int i=0;i<e;i++)
{
    char c1,c2;
    cin>>c1>>c2;
    adj[c1].pb(c2);
    adj[c2].pb(c1);
}
char src='b';
char dest='a';
//BFS(src,dest);
cout<<"Adjacency list:\n";
for(auto x:adj)
{
    cout<<x.ff<<"---->";
   for(auto y:x.ss)
   {
       cout<<y<<" ";
   }
   cout<<endl;
}
cout<<endl;
DFS(src);
return 0;
}