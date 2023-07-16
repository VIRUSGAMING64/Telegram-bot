#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifdef LOCAL
#define FAST_COMPILE
#endif
#ifndef FAST_COMPILE
#ifdef LOCAL
#include "debug/debug.h"
#include "nums/floatx.hpp"
#include "ttmath/ttmath.h"
#include "json/json.hpp"
#include <omp.h>
#include <unistd.h>
#include <windows.h>
using namespace flx;
using namespace ttmath;
using namespace nlohmann;
using namespace literals;
using namespace std;
using namespace chrono;
#include "win/api.hpp"
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
#define ld long double
#define fx ld // antes estaba otra cosa
#define ull unsigned ll
#define S second
#define F first
#define THREAD_NUM 32
#define MOD 1000000007
#define MOD2 998244353
const ll INF = 1e18, MAXN = 1e6;
typedef tree<ll, null_type, less_equal<ll>,
             rb_tree_tag, tree_order_statistics_node_update>
    TREE;

ll bpow(ll a, ll e, ll mod)
{
    if (e == 0)
        return 1;
    if (e & 1)
    {
        return (a % mod * bpow(a, e - 1,MOD2) % mod) % mod;
    }
    auto t = bpow(a, e / 2, mod);
    return (t % mod * t % mod) % mod;
}

ll inv(ll x)
{
    return bpow(x, MOD2 - 2,MOD2);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> ta(n + 1);
    for (ll i = 0; i < n; i++){
        cin >> a[i];
        a[i] *= inv(100);
        a[i] = inv(a[i]);
    }
    ll sum = 0;
    for (ll i = 0; i < n; i++){
        sum = ((sum+1)%MOD2 * a[i]);
        sum %= MOD2;
    }
    cout << sum << endl;
}