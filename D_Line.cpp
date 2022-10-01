//                                       ॐ नमः शिवाय
//                                    ------------------

#include <bits/stdc++.h>
using namespace std;

#define himanshud959         \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define INF 1000000000000000003
#define mod 1e9 + 7
#define ll long long
#define V(i) vector<i>
#define P(i, j) pair<i, j>;
#define F first
#define S second
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define ppf pop_front()
#define ppb pop_back()
#define mp(n, m) make_pair(n, m)
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define rep(i, a, b) for (size_t i = a; i < b; i++)
#define repp(i, a, b) for (size_t i = a; i <= b; i++)

#define sz(x) (int)x.size()
#define R return
#define str string
#define print(x) cout << (x) << '\n';
#define cyes cout << "YES" << '\n';
#define cno cout << "NO" << '\n';
#define csum cout << sum << '\n';
#define cans cout << ans << '\n';
#define ccnt cout << cnt << '\n';
#define cmone cout << '-1' << '\n';
#define cone cout << '1' << '\n';
#define czero cout << '0' << '\n';
#define nl "\n"

#define get(t) \
    int t;     \
    cin >> t;
#define getl(t) \
    ll t;       \
    cin >> t;
#define inputvec(n)   \
    vector<int> a(n); \
    for (auto &i : a) \
    {                 \
        cin >> i;     \
    }
#define getunique(v)                                  \
    {                                                 \
        sort(v.begin(), v.end());                     \
        v.erase(unique(v.begin(), v.end()), v.end()); \
    }

void myTask()
{
    getl(n);
    str a;
    cin >> a;
    int arr[n];
    ll ans = 0;
    rep(i, 0, n)
    {
        if (a[i] == 'L')
            ans += i;
        else
            ans += n - i - 1;

        if (a[i] == 'L')
            arr[i] = n - i - 1 - (i);
        else
            arr[i] = i - (n - i - 1);
    }
    sort(arr, arr + n);
    reverse(arr, arr + n);
    rep(i, 0, n)
    {
        if (arr[i] > 0)
        {
            ans += arr[i];
        }
        cout << ans << " ";
    }
    cout << nl;
}

int32_t main()
{
    himanshud959 /* FIO */

#ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    freopen("opt.txt", "w", stdout);
#endif

    get(_);
    while (_--)
    {
        myTask();
    }
    R 0;
}
