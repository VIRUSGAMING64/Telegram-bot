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
vector<vector<ll>> g;
bool vis[MAXN];
ll datas[MAXN];
ll pa[MAXN];
vector<vector<ll>> dp;
vector<ll> e, dis;
ll F[MAXN];
void dfs(ll x, ll xr = 0, ll P = -1, ll d = 0)
{
    if (vis[x] == 1)
        return;
    dis[x] = d;
    vis[x] = 1;
    F[x] = e.size();
    e.push_back(x);
    for (ll i = 0; i < 25; i++)
    {
        if (xr & (1 << i))
        {
            dp[x][i] += 1;
        }
    }
    for (auto c : g[x])
    {
        if (c == P)
            continue;
        pa[c] = x;
        dfs(c, datas[c], x, d + 1);
        e.push_back(x);
    }
}

pair<vector<ll>, vector<ll>> ADJ(vector<ll> a, vector<ll> b, vector<ll> lca)
{
    ll n = lca.size();
    ll x1 = 0, x2 = 0;
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        a[i] -= lca[i];
        b[i] -= lca[i];
    }
    vector<ll> tot(n);
    for (int i = 0; i < n; i++)
    {
        tot[i] = a[i] + b[i];
    }
    return {tot, tot};
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        dp.resize(n, vector<ll>(25));
        g = {};
        e = {};
        g.resize(n);
        dis.resize(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> datas[i];
            vis[i] = 0;
            F[i] = 0;
            for (int j = 0; j < 25; j++)
            {
                dp[i][j] = 0;
            }
        }
        g.resize(n);
        for (ll i = 0; i < n - 1; i++)
        {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(0, datas[0]);
        vector<pair<ll, ll>> ax(e.size());
        for (ll i = 0; i < e.size(); i++)
        {
            ax[i].first = dis[e[i]];
            ax[i].second = e[i];
        }
        ST st(ax);
        ll q;
        cin >> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 25; j++)
            {
                // cerr << dp[i][j] << " ";
            } // cerr << endl;
        }
        while (q--)
        {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;
            ll ax2 = b;
            ll ax = a;
            a = F[a];
            b = F[b];
            if (b <= a)
                swap(a, b);

            ll lc = st.query(1, 0, e.size() - 1, a, b).second;
            // cerr << "LCA: " << lc << endl;
            auto res = ADJ(dp[ax], dp[ax2], dp[lc]);
            int cnt = 0;
            for (int i = 0; i < 25; i++)
            {
                res.first[i] += (datas[lc] & (1 << i));
                res.second[i] += (datas[lc] & (1 << i));
                res.first[i] -= (datas[ax2] & (1 << i));

                if (res.first[i] >= 1)
                    cnt++;
                if (res.second[i] >= 1)
                    cnt++;
            }
            cout << cnt << " ";
            // cerr << "ARES: " << res << endl;
        }
        cout << endl;
    }
}
