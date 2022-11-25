#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
#define ll long long

ll cont(ll b,vector<ll> a)
{
    ll cnt = 0;
    for(ll i = 0;i<a.size();i++)
    {
        if(a[i] == b)cnt++;
    }
    return cnt;
}
vector<ll> l0(vector<ll> a)
{
    for(ll i = 0; i < a.size(); i++)
    {
        if(a[i] == 0)
        {
            a[i] = 1;
            return a;
        }
    }
    return a;
}

vector<ll> r1(vector<ll> a)
{
    for(ll i = a.size()-1; i >=0 ; i--)
    {
        if(a[i] == 1)
        {
            a[i] = 0;
            return a;
        }
    }
    return a;
}

vector<ll> taC(vector<ll> a)
{
    vector<ll> ta(a.size()+1);
    for(ll i=1; i<ta.size(); i++)
    {
        ta[i] = ta[i-1] + a[i-1];
    }
    ta.erase(ta.begin());
    return ta;
}


ll sum(vector<ll> a)
{
    ll sum = 0;
    for(ll i=0;i<a.size();i++)
    {
        sum+=a[i];
    }
    return sum;
}

void clean(vector<ll> &b,vector<ll> a)
{
    for(ll i=0;i<a.size();i++)
    {
        if(a[i] == 1)
        {
            b[i] = 0;
        }
    }
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i=0;i<n;i++)
        {
            cin >> a[i];
        }
        ll u = cont(1,a);
        ll z = cont(0,a);
        if(u == n || z == n)
        {
            cout << n-1 <<endl;
            continue;
        }
        vector<ll> ax = l0(a);
        auto F = taC(ax);
        clean(F,ax);
        ll mx = sum(F);

        ax = r1(a);
        F = taC(ax);
        clean(F,ax);

        mx = max(mx,sum(F));
        
        F =taC(a);
        clean(F,a);
        mx = max(mx,sum(F));

        cout << mx << endl;
    }
}
