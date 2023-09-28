#include <bits/stdc++.h>
#ifdef LOCAL
#include "includes/debug/debug.h"
#endif
#define ll long long
#define pb push_back
#define F first
#define S second
using namespace std;
#define MOD 1000000007

ll bpow(ll a, ll e)
{
   if (e == 0)
      return 1;
   if (e == 1)
      return a;
   if (e & 1)
      return (a % MOD * bpow(a, e - 1) % MOD) % MOD;
   ll t = bpow(a, e / 2);
   return (t % MOD * t % MOD) % MOD;
}

signed main()
{
   int n, k;
   cin >> n >> k; 
   cout << (((((1+bpow(n,k)))%MOD * n%MOD)%MOD) * bpow(2,MOD-2) % MOD) %MOD << endl;
}