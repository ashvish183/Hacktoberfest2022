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
const double PI=3.1415926535897932384626433832795;
const  ll mod = 1e9 + 7;
const  ll  inf = 1e16;
const  ll N = 2e5 + 10;
vector<int> parent(10000,0);
vector<int> Rank(10000,0);
vector<int> maxi(10000,0);
 int find(int x)
 {
    if(x==parent[x])
    {
        return x;
    }
    return parent[x]=find(parent[x]);
 }
 void Union(int x,int y)
 {
    x=find(x);
    y=find(y);
    if(Rank[x]<Rank[y])
    {
        parent[x]=y;
    }
    else if(Rank[y]<Rank[x])
    parent[y]=x;
    else
    {
        parent[y]=x;
        Rank[x]++;
    }
 }
 void solve() 
{
 int c_nodes=5;
 int c_edges=4;
 vector<int> from{1,2,1,4};
vector<int> to{2,3,3,5};
 for(int i=0;i<=c_nodes;i++)
 {parent[i]=i;
 Rank[i]=0;
 maxi[i]=i;
 }
vector<int> ans;
int s=((c_nodes)*(c_nodes+1))/2;
for(int i=0;i<c_edges;i++)
{
    int x=from[i];
    int y=to[i];
    if(find(x)!=find(y))
    {
        Union(x,y);   
        int a=find(x);
        int b=find(y);
        int oldsum=maxi[x]+maxi[y];
        maxi[a]=max(maxi[a],x);
        maxi[b]=max(maxi[b],y);
        int newsum=maxi[a];
        s=s-oldsum+newsum;
     
    }
    
    ans.push_back(s);
}
// for(int i=1;i<=5;i++)
// cout<<maxi[i]<<" ";
// cout<<endl;
for(int i=0;i<ans.size();i++)
{
cout<<ans[i]<<" ";
}

}
int main()
{
IOS();
FAST;
ll t=1;
// cin>>t;
while(t--)
{
// cout << "Case #" << t << ": ";
solve();
}
return 0;
}