#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define F first
#define S second
#define INF 10000000000000000LL
using namespace std;
int n, m, a, b, l;
#define pii pair<int, int>
vector<vector<pii>> g;
ll dis[10000];
void dj1(int x)
{   
    memset(dis,INF,sizeof(dis));
    dis[x] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push(0,x);
    while(!q.empty())
    {
        int a = q.front().S;
        int d_a = q.back().F;
        q.pop();
        if(d_a!=dis[a])continue;
        for(auto c:g[a])
        {
            int 
            b = c.F,
            w = c.S;
            if(w == 0)continue;
            if(dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }
}
#define INF 100000
#define vi vector<int> 
#define vvi vector<vector<int>>
vvi bfs(int x,int y)
{
    vvi dis(n,vi(m,INF));
    dis[x][y] = 0;
    queue<pair<int,pair<int,int>>> q;
    q.push({x,{y,0}});
    while(!q.empty())
    {
        x = q.top().F;
        y = q.top().S.F;
        int d = q.top().S.S;
        q.pop();
        if(x >= n || x <0 || y >= m || y < 0)continue;
        if(vis[x][y] || g[x][y] == '*')continue;
        vis[x][y] = 1;
        dis[x][y] = d;
        q.push({x+1,{y,d+1}});
        q.push({x-1,{y,d+1}});
        q.push({x,{y+1,d+1}});
        q.push({x,{y-1,d+1}});
    }
    return dis;
}

int main()
{
    cin >> n >> m >> a >> b >>l;
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin >> x >> y >> w;
        cin >> x >> y >> w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    dj1(a);
    
}