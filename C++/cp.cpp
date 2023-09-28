#pragma GCC Optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifdef LOCAL
#define FAST_COMPILEr
#endif
#ifndef FAST_COMPILE
#ifdef LOCAL
#include "includes/debug/debug.h"
#include "includes/nums/floatx.hpp"
#include "includes/ttmath/ttmath.h"
#include "includes/json/json.hpp"
#include <omp.h>
#include <unistd.h>
#include "includes/win/api.hpp"
#include <windows.h>
using namespace literals;
using namespace flx;
using namespace ttmath;
using namespace nlohmann;
using namespace std;
using namespace chrono;
#endif
#endif
#ifdef FAST_COMPILE
using namespace std;
#define debug
#endif
#ifndef LOCAL
using namespace std;
#define debug
#endif
#define pb push_back
#define ll long long
#define ull unsigned ll
#define all(x) x.begin(), x.end()
#define ld long double
#define fx ld // antes estaba otra cosa
#define ull unsigned ll
#define S second
#define F first
#define THREAD_NUM 32
#define MOD 1000000007
const ll INF = 1e18, MAXN = 1e6 * 4;
typedef tree<ll, null_type, less_equal<ll>,
             rb_tree_tag, tree_order_statistics_node_update>
    TREE;

ll lazy[MAXN];
vector<ll> p;

void prop(ll n, ll l, ll r, ll di = 0)
{
    if (di > 2)
        return;
    if (lazy[n] == 0)
        return;
    if (l == r)
    {
        p[l] += lazy[n];
    }
    else
    {
        lazy[n * 2] += lazy[n];
        lazy[n * 2 + 1] += lazy[n];
    }
    lazy[n] = 0;
}

void update(ll n, ll l, ll r, ll a, ll b, ll val)
{
    assert((n > 0) and (l <= r));
    prop(n, l, r);
    if (l > b || r < a)
        return;
    if (l >= a && r <= b)
    {
        lazy[n] += val;
        prop(n, l, r);
        return;
    }
    ll m = (l + r) / 2;
    update(n * 2, l, m, a, b, val);
    update(n * 2 + 1, m + 1, r, a, b, val);
}

ll Q(ll n, ll l, ll r, ll po)
{
    assert(n > 0);
    prop(n, l, r);
    if (l == r)
    {
        return p[po];
    }
    ll m = (l + r) / 2;
    if (po <= m)
    {
        return Q(n * 2, l, m, po);
    }
    else
    {
        return Q(n * 2 + 1, m + 1, r, po);
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        for (ll i = 0; i < MAXN; i++)
        {
            lazy[i] = 0;
        }
        ll n;
        cin >> n;
        vector<ll> a(n + 30);
        p.resize(0);
        p.resize(n + 10000);

        vector<deque<ll>> q(n + 10000);
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            q[a[i]].push_back(i);
        }
        ll res = 0;
        for (ll i = 1; i <= n; i++)
        {

            if (q[a[i]].size() < 2)
                continue;
            // for (ll i = 1; i <= n; i++)
            // {
            // cerr << Q(1, 1, n, i) << " ";
            //}
            // cerr << "\n";
            q[a[i]].pop_front();
            ll b = q[a[i]].back();
            q[a[i]].pop_back();
            res += [&]()
            {
                ll aa = i;
                // cerr<< "\n" << a << " " << b;
                // cerr << aa << "  " << b << "\n";
                ll ka = aa;
                ll kb = b;
                aa += Q(1, 1, n, aa);
                b += Q(1, 1, n, b);
                // cerr << aa << "  " << b << "\n";
                // cerr << "-----------\n";
                ll sum = abs(aa - b);
                update(1, 1, n, ka + 1, n, -1);
                update(1, 1, n, kb + 1, n, -1);
                return sum;
            }();
        } // cerr << "\n---------\n";
        cout << res << "\n";
    }
    return 0;
}
