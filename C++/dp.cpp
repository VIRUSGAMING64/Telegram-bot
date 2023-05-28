#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef LOCAL
#include "debug/debug.h"
#include "nums/floatx.hpp"
#include "ttmath/ttmath.h"
#include "json/json.hpp"
#include <omp.h>
#include <unistd.h>
#include <windows.h>
using namespace flx;
using namespace ttmath;
using namespace nlohmann;
using namespace literals;
#include "win/api.hpp"
#endif
#ifndef LOCAL
#define debug
#endif
#define pb push_back
#define ll long long
#define ld long double
#define fx ld // antes estaba otra cosa
#define ull unsigned ll
#define S second
#define F first
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define THREAD_NUM 32
#define MOD 1000000007
const ll INF = 1e18, MAXN = 1e6;
typedef tree<ll, null_type, less_equal<ll>,
             rb_tree_tag, tree_order_statistics_node_update>
    TREE;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> a(n + 1);
        for (ll i = 0; i < n; i++)
            if (s[i] == '(')
                a[i + 1] = a[i] + 1;
            else
                a[i + 1] = a[i] - 1;

        if (a.back() != 0)
            cout << -1 << endl;
        else
        {
            if (*min_element(a.begin(), a.end()) == 0 || *max_element(a.begin(), a.end()) == 0)
            {
                cout << 1 << endl;
                for (ll j = 0; j < n; j++)
                {
                    if (j)
                        cout << " ";
                    cout << 1;
                }
                cout << endl;
            }
            else
            {
                cout << 2 << endl;
                vector<ll> ans;
                ll l = 0;
                while (l < n)
                {
                    ll w = (s[l] == '(' ? 1 : 2);
                    do
                    {
                        l++;
                        ans.push_back(w);
                    } while (a[l] != 0);
                }
                for (ll j = 0; j < n; j++)
                {
                    if (j)
                        cout << " ";
                    cout << ans[j];
                }
                cout << endl;
            }
        }
    }
}