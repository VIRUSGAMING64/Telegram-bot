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
    vector<pair<ll, ll>> a;
    vector<pair<ll, ll>> st;
    vector<ll> lazy;
    ST() {}
    ST(vector<pair<ll, ll>> _a)
    {
        atm = _a.size();
        tam = atm * 4 + 40;
        a = _a;
        st.resize(tam);
        lazy.resize(tam);
        build(1, 0, atm - 1);
    }
    pair<ll, ll> F(pair<ll, ll> &x1, pair<ll, ll> &x2)
    {
        if (x1.first < x2.first)
        {
            return x1;
        }
        else
        {
            return x2;
        }
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
        st[n] = F(st[n * 2], st[n * 2 + 1]);
    }
    pair<ll, ll> query(ll n, ll l, ll r, ll a, ll b)
    {
        if (l > b || r < a)
            return {100000000, 10000000};
        if (l >= a && r <= b)
            return st[n];
        ll m = (l + r) / 2;
        auto q1 = query(n * 2, l, m, a, b);
        auto q2 = query(n * 2 + 1, m + 1, r, a, b);
        return F(q1, q2);
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

map<vector<int>, int> memo;
int x1, x2, x3;
int mop = 10000000;
void f(vector<int> a, int ops)
{
    if (memo[a])
        return;
    memo[a] = 1;
    set<int> r;
    int cnt = 0;
    for (auto c : a)
    {
        r.insert(c);
    }
    if (r.find(x3) != r.end())
        cnt++;
    if (r.find(x2) != r.end())
        cnt++;
    if (r.find(x1) != r.end())
        cnt++;
    if (cnt == 3)
    {
        mop = min(ops, mop);
        return;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == -1)
            continue;
        if (a[i] + 1 < 1001)
        {
            a[i]++;
            f(a, ops + 1);
            a[i]--;
        }
        if (a[i] != 1)
        {
            a[i]--;
            f(a, ops + 1);
            a[i]++;
        }
        for (int j = 0; j < a.size(); j++)
        {
            if (i == j)
                continue;
            if (a[j] == -1)
                continue;
            int d = a[i];
            int d2 = a[j];
            a.push_back(a[i] + a[j]);
            a[i] = -1;
            a[j] = -1;
            f(a, ops + 10);
            a.pop_back();
            a[i] = d;
            a[j] = d2;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> x1 >> x2 >> x3;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    f(a, 0);
    cout << mop << endl;
    return 0;
}
