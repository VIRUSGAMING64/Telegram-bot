#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pb push_back
#define F first
#define S second
#ifdef LOCAL
#include "includes/debug/debug.h"
#endif
#ifndef LOCAL
#define debug
#endif
using namespace std;
#define MAXN 210000
#define MOD 1000000007
#define SU(x) ((x * x + x) / 2)
typedef tree<ll, null_type, less_equal<ll>,
             rb_tree_tag, tree_order_statistics_node_update>
    TREE;

mt19937_64 random(chrono::steady_clock::now().time_since_epoch().count());

class ST
{
public:
    ll tam;
    ll atm;
    vector<ll> a;
    vector<ll> st;
    vector<ll> lazy;
    ST() {}
    ST(vector<ll> _a)
    {
        atm = _a.size();
        tam = atm * 4 + 40;
        a = _a;
        st.resize(tam);
        lazy.resize(tam);
        build(1, 0, atm - 1);
    }
    void prop(ll n, ll l, ll r)
    {
        lazy[n] %= 2;
        if (lazy[n] == 0)
            return;
        st[n] = (r - l + 1) - st[n];
        if (l != r)
        {
            lazy[n * 2] += lazy[n];
            lazy[n * 2 + 1] += lazy[n];
        }
        lazy[n] = 0;
    }
    void build(ll n, ll l, ll r)
    {
        if (l == r)
        {
            st[n] = a[l];
            return;
        }
        ll m = (l + r) / 2;
        build(n * 2, l, m);
        build(n * 2 + 1, m + 1, r);
        st[n] = st[n * 2] + st[n * 2 + 1];
    }
    ll query(ll n, ll l, ll r, ll a, ll b)
    {
        prop(n, l, r);
        if (l > b || r < a)
            return 0;
        if (l >= a && r <= b)
            return st[n];
        ll m = (l + r) / 2;
        ll q1 = query(n * 2, l, m, a, b);
        ll q2 = query(n * 2 + 1, m + 1, r, a, b);
        return q1 + q2;
    }
    void update(ll n, ll l, ll r, ll a, ll b, ll x)
    {
        prop(n, l, r);
        if (l > b || r < a)
            return;
        if (l >= a && r <= b)
        {
            lazy[n] += x;
            prop(n, l, r);
            return;
        }
        ll m = (l + r) / 2;
        update(n * 2, l, m, a, b, x);
        update(n * 2 + 1, m + 1, r, a, b, x);
        st[n] = st[n * 2] + st[n * 2 + 1];
    }
};

ll SUM(ll x)
{
    ll sum = 0;
    while (x != 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int nxt()
{
    int x;
    cin >> x;
    return x;
}

map<int, char> math;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    // cin >> t;
    int n;
    cin >> n;
    vector<int> b(n);
    vector<pair<int,int>> a(n);
    for(int i = 0  ; i < n; i++){
      cin >> a[i].first ;
      a[i].second = i;
    }for(int i = 0 ; i < n; i++){
      cin >> b[i];
    }
    //sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    for(int i = 0 ; i < n; i++){
      a[i].first+=b[i];
      a[i].first%= n;
      swap(a[i].first,a[i].second);
    }
    sort(a.begin(),a.end());
    for(auto c:a){
      cout << c.second << " ";
    }
}
