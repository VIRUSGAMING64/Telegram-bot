#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#define N 1000005
#define MOD 1000000007
#define ll long double
using namespace std;
#define F first
#define S second
struct P
{
    ll x,y;
};

struct F
{
    ll m,n;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<P> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    if(k == 1)
    {
        cout << "Infinity" << endl;
        return 0;
    }
    else if(n == 1)
    {
        cout << 0 << endl;
    }
    ll cnt = 0;
    set<pair<ll,ll>> lines;
    for(int i =0;i < n;i++)
    {
        for(int j = 0;j  < n; j++)
        {
            if(i == j)
            continue;
            if(a[i].x - a[j].x == 0)
            {
                cnt++;
                continue;   
            }
            ll m = (((a[i].y - a[j].y) / (a[i].x - a[j].x)));
            ll n = a[i].y - (m*a[i].x);
            lines.insert({m,n});
        }
    }
    cnt =(int)sqrt(cnt)-1;
    for(auto c:lines)
    {
        ll res = 0;
        for(auto p : a)
        {
            ll res2 = c.F*p.x + c.S;
            if(res2-0.05 <= p.y && res2+0.05 >= p.y)
            {
                res++;
            }
        }
        if(res >= k)cnt++;
    }
    cout << cnt << endl;
}