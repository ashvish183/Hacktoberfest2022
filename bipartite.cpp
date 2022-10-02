#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
//BFS
bool check(int s,vector<int> adj[],vector<int> &color)
{
    queue<int> q;
    q.push(s);
    color[s]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                q.push(it);
            }
            else if(color[it]==color[node])
            return false;
        }

    }    
    return true;
}
bool bipartite(vector<int> adj[],int v)
{
    vector<int> color(v,-1);
    for(int i=1;i<=v;i++)
    {
        if(color[i]==-1)
        {
            if(!check(i,adj,color))
              return false;
        }
    }
    return true;
}
//DFS 
bool checkdfs(int node,vector<int> adj[],vector<int> &color)
{
    if(color[node]==-1) color[node]=1;
    for(auto it:adj[node])
    {
        if(color[it]==-1)
        {
            color[it]=1-color[node];
            if(!checkdfs(it,adj,color))
            return false;
        }
        else if(color[it]==color[node])
        return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  int v,e;
  cin>>v>>e;
  vector<int> adj[v+1];
for(int i=0;i<e;i++)
{
    int a,b;
    cin>>a>>b;

    adj[a].pb(b);
    adj[b].pb(a);
}
if(bipartite(adj,v))
cout<<"YES\n";
else
cout<<"NO\n";
}