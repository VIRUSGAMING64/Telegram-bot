#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 100005;
ll P[N];
vector <ll> g[N];

ll dfs(ll x)
{
    if(P[x] != -1)return P[x];
    ll ax = 0;
    for(auto to:g[x])
    {
        ax = max(ax,dfs(to));
    }
    P[x] = 1 + ax;
    return P[x];
}

int main()
{
    ll n,m;
    cin >> n >> m;
    for(ll i = 1; i <= m; i++)
    {
        ll a,b;
        cin >> a >> b;

        g[a].push_back(b);
    }
    memset(P,-1,sizeof(P));
    ll res = 0;
    for(ll i = 1; i <= n; i++)
    {
        res = max(res,dfs(i));
    }
    cout << res-1 << endl;
    return 0;
}