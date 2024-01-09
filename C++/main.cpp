#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define u_ll unsigned ll
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
using namespace std;
#define MAXN 1100000
#define MOD 1000000007
#define INF 100000000000000000ll
typedef tree<ll, null_type, less_equal<ll>,
             rb_tree_tag, tree_order_statistics_node_update>
    TREE;

ll mult(ll a, ll b)
{
    return (a % MOD * (b % MOD)) % MOD;
}
ll bpow(ll a, ll e)
{
    if (e == 0)
        return 1;
    if (e == 1)
        return a;
    ll t = bpow(a, e / 2) % MOD;
    t = mult(t, t);
    if (e & 1)
    {
        t = mult(t, a);
    }
    return t;
}

bool cmp(vector::_ForwardIterator poi, int va)
{
    
    if (((val * a) + (n - val) * b) < i)
        return true;
    return false;
}

void sol()
{

    ll n, a, b;
    cin >> a >> b >> n;
    if (a > b)
    {
        swap(a, b);
    }
    vector<int> fi;
    for (int i = 0; i <= n; i++)
    {
        fi.push_back(i);
    }
    for (int i = n * a; i <= n * b; i++)
    {
        ll k = -1;
        auto pos = lower_bound(fi.begin(), fi.end(), i, cmp) - fi.begin();
        cout << pos << endl;
    }
}
signed main()
{
    sol();
}
