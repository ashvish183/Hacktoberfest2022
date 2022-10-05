#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll knapsack(ll W,ll wt[],ll val[],ll n)
{
     ll i, w;
      vector<vector<ll>> K(n + 1, vector<ll>(W + 1));
 
    // Build table K[][] in bottom up manner
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}
int main()
{
    ll val[]={60,100,120};
    ll wt[]={10,20,30};
    ll W=50;
    ll n=sizeof(val)/sizeof(val[0]);
    cout<<knapsack(W,wt,val,n)<<"\n";
    
}