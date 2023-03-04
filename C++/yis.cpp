#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#define N 1000005
#define MOD 1000000007
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvi vector<vi>
ll md, ot;
set<ll> S;
bool vis[N];
vector<vector<ll>> g;
void dfs(ll x, ll p = -1, ll d = 0)
{
    if (vis[x])return;
    S.insert(x);
    if(d+1 > md)return;
    vis[x] = 1;
    for (auto to : g[x])
    {
        if (p == to) continue;
        dfs(to, x, d + 1);
    }
}

void bfs(int x)
{
    vis[x] = 1;
    S.insert(x);
    queue<pair<int,int>> q;
    q.push({x,0});
    while (!q.empty())
    {
        int a = q.front().first;
        int d = q.front().second;
        q.pop();
        if(d > md)continue;
        S.insert(a);
        for(auto c:g[x])
        {
            if(vis[c])continue;
            vis[c] = 1; 
            if(d+1 > md)continue;
            q.push({c,d+1});
        }
    }
    
}

vector<vector<ll>> DP(N,vector<ll> (4,-1));

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    g.resize(n + 10);
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll q;
    cin >> q;
    while (q--)
    {
        cin >> ot >> md;
        if(DP[ot][md] != -1)
        {
            cout << DP[ot][md] << endl;
            continue;
        }
        bfs(ot);
        ll sum = 0;
        for (auto c : S)
        {
            sum += c;
            vis[c] = 0;
        }
        S.clear();
        DP[ot][md] = sum;
        cout << sum << endl;
    }
}