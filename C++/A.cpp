#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define all(a) a.begin(), a.end()
#define ld long double
#define ll long long
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll N = 1e6;
const ll inf = 1e9;
const double pi = acos(-1);
ll n, m, a, b, d;
ll dist[N];
bool vis[N];
vector<ll> g[N];
vector<pair<ll, ll>> B;
int tin[N], low[N], timer;

void dfs(ll x = 0, ll p = -1)
{
    low[x] = tin[x] = timer++;
    vis[x] = 1;
    for (auto to : g[x])
    {
        if (to == p)
            continue;
        if (vis[to])
        {
            low[x] = min(low[x], tin[to]);
        }
        else
        {
            dfs(to, x);
            low[x] = min(low[x], low[to]);
            if (tin[x] < low[to])
            {
                B.push_back({x, to});
            }
        }
    }
}

int cnt = 0;

void find(int x){
    if(vis[x] == 1)return;
    vis[x] = 1;
    cnt++;
    for(auto to : g[x]){
        
    }
}

int32_t main()
{
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs();
    memset(vis,0,sizeof(vis));
    for(auto c:B){

    }

}