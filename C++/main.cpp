#pragma GCC Optimize("Ofast")
#include "bits/stdc++.h"
// #include "ext/pb_ds/assoc_container.hpp"
// #include "ext/pb_ds/tree_policy.hpp"
// using namespace __gnu_pbds;
#ifdef LOCAL
#define FAST_COMPILE
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
#define PII pair<ll, ll>
#define ull unsigned ll
#define VI vector<ll>
#define VII vector<VI>
#define all(x) x.begin(), x.end()
#define ld long double
#define fx ld // antes estaba otra cosa
#define ull unsigned ll
#define S second
#define F first
#define THREAD_NUM 32
#define MOD 998244353
const ll INF = 1e18, MAXN = 2e5 + 5;
// typedef tree<ll, null_type, less_equal<ll>,rb_tree_tag, tree_order_statistics_node_update> TREE;

class poll
{
public:
    double x, y;
    poll(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    poll(pair<double, double> a)
    {
        x = a.first;
        y = a.second;
    }
    poll() {}
    double MANJ(poll a)
    {
        return (fabs(a.x - x) + fabs(a.y - y));
    }
    double EUC(poll a)
    {
        double R1 = fabs(a.y - y);
        double R2 = fabs(a.x - x);
        return sqrt(R1 * R1 + R2 * R2);
    }
    friend istream &operator>>(istream &in, poll &a)
    {
        in >> a.x >> a.y;
        return in;
    }
};
ll F(ll a, ll b)
{
    ll c;
    c = max(a, b);
    return c;
}
void build(ll n, ll l, ll r)
{
    if (l == r)
    {
        st[n] = a[l - 1] - a[l];
        return;
    }
    ll m = (l + r) / 2;
    build(n * 2, l, m);
    build(n * 2 + 1, m + 1, r);
    st[n] = F(st[n * 2], st[n * 2 + 1]);
}
ll query(ll n, ll l, ll r, ll a, ll b)
{
    if (r < a || l > b)
        return -INF;
    if (l >= a && r <= b)
        return st[n];
    ll m = (l + r) / 2;
    auto q1 = query(n * 2, l, m, a, b);
    auto q2 = query(n * 2 + 1, m + 1, r, a, b);
    return F(q1, q2);
}
void update(ll n, ll l, ll r, ll pos, ll val)
{
    if (l == r)
    {
        a[l] = val;
        st[n] = a[l - 1] - a[l];
        return;
    }
    ll m = (l + r) / 2;
    if (pos <= m)
    {
        update(n * 2, l, m, pos, val);
    }
    else
    {
        update(n * 2 + 1, m + 1, r, pos, val);
    }
    st[n] = F(st[n * 2], st[n * 2 + 1]);
}

vector<ll> a;
vector<ll> st;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {

    }
}
