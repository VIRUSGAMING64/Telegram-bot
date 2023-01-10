#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin>> n;
    ll sum = 0;
    ll res = 100000000000LL;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin >> a;
        sum += a;
        res = min(res,sum/(i+1));
    }
    cout << res << endl;
}

