#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define ff first
#define ss second
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
bool check(int s,vector<int> adj[],vector<int> &vis,vector<int> &dvis)
{
    vis[s]=1;
    dvis[s]=1;
    for(auto it:adj[s])
    {
        if(!vis[it])
        {
            if(check(it,adj,vis,dvis)) return true;
            else if(dvis[it]) return true;
        }
    }
    dvis[s]=0;
    return false;
}
bool iscycle(int v,vector<int> adj[])
{
    vector<int> vis(v+1,0);
    vector<int> dvis(v+1,0);
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            if(check(i,adj,vis,dvis))
            return true;
        }
    }
    return false;
} 
bool iscycletopo(int v,vector<int> adj[])
{
    queue<int> q;
    vector<int> indegree(v,0);
    for(int i=0;i<v;i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    int c=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        c++;
        for(auto it:adj[node])
        {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
        }
    }
    if(c==v) return false;
    return true;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int v,e;
cin>>v>>e;
vector<int> adj[v];
for(int i=0;i<e;i++)
{
    int a,b;
    cin>>a>>b;
    adj[a].pb(b);
}
if(iscycle(v,adj))
cout<<"YES\n";
else
cout<<"NO\n";
return 0;
}