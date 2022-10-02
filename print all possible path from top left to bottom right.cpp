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

vector<vector<int>> ans;
bool issafe(vector<vector<int> > & mat,int i,int j,vector<vector<int> > & vis)
{
    return (i>=0 and j>=0 and i<mat.size() and j<mat[0].size() and vis[i][j]==0);
}
void solve(vector<vector<int> > & mat,vector<int> v,int i,int j,vector<vector<int> > & vis)
{
    if(i==mat.size()-1 and j==mat[0].size()-1)
    {
        v.push_back(mat[i][j]);
        ans.push_back(v);
        return;
    }
    v.push_back(mat[i][j]);
    vis[i][j]=1;
    if(issafe(mat,i+1,j,vis))
    {
        solve(mat,v,i+1,j,vis);
    }
    if(issafe(mat,i,j+1,vis))
    {
        solve(mat,v,i,j+1,vis);
    }
    vis[i][j]=0;
    v.pop_back();
}
vector<vector <int> > printAllpaths(vector<vector<int> > & mat , int m , int n)
{
    ans.clear();
    vector<int> v;
    vector<vector<int> > vis(m,vector<int>(n,0)); 
    solve(mat,v,0,0,vis);
    return ans;
}

 void solve() 
{
  ll n,m;
  cin>>n>>m;
  vector<vector<int>> mat(n,vector<int>(m));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    cin>>mat[i][j];
  }
 vector<vector<int>> res=printAllpaths(mat,n,m);
 for(int i=0;i<res.size();i++)
  {
    for(int j=0;j<res[i].size();j++)
    cout<<res[i][j]<<" ";
    cout<<endl;
  }
}
int main()
{
IOS();
FAST;
ll t;
cin>>t;
while(t--)
{
// cout << "Case #" << t << ": ";
solve();
}
return 0;
}