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
void IOS()
{
 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
   #ifndef ONLINE_JUDGE 
  #endif
}
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
 
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
const  ll mod = 1e9 + 7;
const  ll  inf = 1e16;
const  ll N = 2e5 + 10;
 
int main()
{
IOS();
FAST;
ll n,e;
cin>>n>>e;
vector<vector<ll>> edges;
for(int i=0;i<e;i++)
{
    ll a,b,wt;
    cin>>a>>b>>wt;
    edges.pb({a,b,wt});
}
vll dis(n+1,1e9);
int src;
cin>>src;
dis[src]=0;
for(int i=1;i<n;i++)
{
    // for(auto &it:edges)
    // {
    //     if(dis[it[0]]+it[2]<dis[it[1]])
	//             dis[it[1]]=dis[it[0]]+it[2];
    // }
    for(int i=0;i<edges.size();i++)
    {
        
        if(dis[edges[i][0]]+edges[i][2]<dis[edges[i][1]])
        dis[edges[i][1]]=dis[edges[i][0]]+edges[i][2];
        
    }
}
int f=0;
for(auto &it:edges)
	    {
	        if(dis[it[0]]+it[2]<dis[it[1]]) {f=1;break;}
	    }
        if(f)
        cout<<"Negative cycle\n";
        else
        {
            for(int i=0;i<n;i++)
            cout<<dis[i]<<" ";
        }
return 0;
}