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
#define VI vector<ll>
#define VII vector<VI>
#define all(x) x.begin(), x.end()
#define ld long double
#define fx ld // antes estaba otra cosa
#define ull unsigned ll
#define S second
#define F first
#define THREAD_NUM 32
// #define MOD 1000000007
const ll INF = 1e18, MAXN = 1e5 + 5;
typedef tree<ll, null_type, less_equal<ll>,
             rb_tree_tag, tree_order_statistics_node_update>
    TREE;
const ll MOD = 1000000007;
int** fibo[2][2] = {
    {1, 1},
    {1, 0},
};
int** mul[2][1] = {
    {1},
    {0},
};

ll st[MAXN * 4][2][1];
ll a[MAXN];
ll lazy[MAXN * 4];

int** M(int** A,int** B)
{
    int** C = new int*[2];
    for (ll a = 0; a < 2; a++)
    {
        for (ll b = 0; b < 2; b++)
        {
            for (ll i = 0; i <2; i++)
            {
                C[a][b] += (A[a][i] % MOD * B[i][b] % MOD) % MOD;
                C[a][b] %= MOD;
            }
        }
    }
    return C;
}

int** S(int** , int** B)
{
    int** C = new int*[2];
    C[0] = new int
    for (ll a = 0; a < 2; a++)
    {
        for (ll b = 0; b < 1; b++)
        {
            C[a][b] = A[a][b] % MOD + B[a][b] % MOD;
            C[a][b] %= MOD;
        }
    }
    return C;
}

int** bpow(int** a, ll e)
{
    if (e == 0)
        return [&]()
        {
            int ar[2][2];
            ar[0][0]=1;
            ar[1][1]=1;
            return ar;
        }();
    if (e == 1)
        return a;
    auto T = bpow(a, e / 2);
    T = M(T,T);
    if (e & 1)
    {
        T = M (T, a);
    }
    return T;
}

void build(ll n, ll l, ll r)
{
    lazy[n] = 0;
    if (l == r)
    {
        auto R = bpow(fibo, a[l] - 1);
        R = M(R,mul);
        st[n][0][0] = R[0][0] % MOD;
        st[n][1][0] = R[1][0] % MOD;
        return;
    }
    ll m = (l + r) / 2;
    build(n * 2, l, m);
    build(n * 2 + 1, m + 1, r);
    st[n][0][0] = (st[n * 2][0][0] % MOD + st[n * 2 + 1][0][0] % MOD) % MOD;
    st[n][1][0] = (st[n * 2][1][0] % MOD + st[n * 2 + 1][1][0] % MOD) % MOD;
}

void prop(ll l, ll r, ll n)
{
    if (lazy[n] == 0)
        return;
    auto T = bpow(fibo, lazy[n]);
    ll x1 = ((st[n][0][0] % MOD * T[0][0] % MOD) % MOD) % MOD + ((st[n][1][0] % MOD * T[0][1] % MOD) % MOD) % MOD;
    ll y1 = ((st[n][0][0] % MOD * T[1][0] % MOD) % MOD) % MOD + ((st[n][1][0] % MOD * T[1][1] % MOD) % MOD) % MOD;
    st[n][0][0] = x1;
    st[n][1][0] = y1;
    st[n][0][0] %= MOD;
    st[n][1][0] %= MOD;
    if (l != r)
    {
        lazy[n * 2] += lazy[n];
        lazy[n * 2 + 1] += lazy[n];
    }
    lazy[n] = 0;
}

ll query(ll n, ll l, ll r, ll a, ll b)
{
    prop(l, r, n);
    if (r < a || l > b)
        return 0;
    if (a <= l && r <= b)
    {
        // debug(st[n]);
        return st[n][0][0] % MOD;
    }
    ll m = (l + (r - l) / 2);
    ll q1 = query(n * 2, l, m, a, b);
    ll q2 = query(n * 2 + 1, m + 1, r, a, b);
    return ((q1 % MOD) + (q2 % MOD)) % MOD;
}

void update(ll n, ll l, ll r, ll a, ll b, ll x)
{
    prop(l, r, n);
    if (r < a || l > b)
        return;
    if (a <= l && r <= b)
    {
        lazy[n] += x;
        prop(l, r, n);
        return;
    }
    ll m = (l + (r - l) / 2);
    update(n * 2, l, m, a, b, x);
    update(n * 2 + 1, m + 1, r, a, b, x);
    st[n][0][0] = (st[n * 2][0][0] % MOD + st[n * 2 + 1][0][0] % MOD) % MOD;
    st[n][1][0] = (st[n * 2][1][0] % MOD + st[n * 2 + 1][1][0] % MOD) % MOD;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--)
    {
        ll tq;
        cin >> tq;
        ll l, r, x;
        if (tq == 1)
        {
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        }
        else
        {
            cin >> l >> r;
            cout << query(1, 1, n, l, r) % MOD << "\n";
        }
    }
}

/*
1 2 3 4
1 3 3 4
4 = 8-6 = 2
5 = 10-6 = 4
6 = 12-6 = 6 12 +
7 = 14-6 = 8
*/