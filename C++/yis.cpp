#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#define N 1000005
#define MOD 1000000007 
#define ll long long
using namespace std;
ll P[N];
void Po()
{
    P[0] = 1;
    for (int i = 1; i < 1000000; i++)
    {
        P[i] = (P[i - 1] * 311) % 1000000007;
    }
}

ll hashs(string s)
{
    ll res = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        res += (s[i] * P[i]) % 1000000007;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
}