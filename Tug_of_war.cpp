#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
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
void tow(vll &a,vll &vis,vll &cur,ll &dif,ll sum,ll cursum,int idx,int select)
{
    if(idx==a.size()) return;
    if(a.size()/2-select>(a.size()-idx)) return;
    tow(a,vis,cur,dif,sum,cursum,idx+1,select);
    select++;
    cursum+=a[idx];
    cur[idx]=1;
    if(select==a.size()/2)
    {
        if(abs(sum/2-cursum)<dif)
        {
          dif=abs(sum/2-cursum);
          for(int i=0;i<a.size();i++)
          {
              vis[i]=cur[i];
          }

        }
    }
    else
    {
        tow(a,vis,cur,dif,sum,cursum,idx+1,select);
    }
    cur[idx]=0; //backtrack 
}
int main()
{
IOS();
FAST;
ll t;
cin>>t;
while(t--)
{ 
    auto start = high_resolution_clock::now();
  ll n;
  cin>>n;
  vll a(n);
  inp(a);
  ll sum=accumulate(all(a),0);
  vll vis(n,0),cur(n,0);
  ll dif=INT_MAX;
  tow(a,vis,cur,dif,sum,0,0,0);
  cout<<dif<<endl;
  
auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
}
return 0;
}