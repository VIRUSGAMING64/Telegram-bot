#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pb push_back
#define F first
#define S second
#define MAXN 2010000
#define MOD 998244353
#define SU(x) ((x * x + x) / 2)
typedef tree<ll, null_type, less_equal<ll>,
             rb_tree_tag, tree_order_statistics_node_update>
    TREE;

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
            st[n] = (l == a[l]);
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

ll bpow(ll &a,ll e,const ll &mod){
    if(e == 0)return 1;
    if(e == 1)return a;
    ll t = bpow(a,e/2,mod);
    t = (t%mod*t%mod)%mod;
    if(e & 1){
        t = (t%mod * a%mod)%mod;
    }
    return t;
}
/*
un record es j < i and a[j] < a[i] para todo J de 0 a i-1
*/

signed main()
{
    
}