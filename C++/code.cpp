#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef LOCAL
#include "debug/debug.h"
#include "float/floatx.hpp"
#include "ttmath/ttmath.h"
#include "json/json.hpp"
#include <omp.h>
#include <unistd.h>
#include <windows.h>
using namespace flx;
using namespace ttmath;
using namespace nlohmann;
using namespace literals;
#endif
#define pb push_back
#define ll long long
#define ld long double
#define fx long double // antes estaba otra cosa
#define ull unsigned ll
#define S second
#define F first
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define THREAD_NUM 32
const ll MOD = 1e9 + 7, INF = 1e18, MAXN = 1e6;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> v(n);
        for (int &e : v)
        {
            cin >> e;
        }
        sort(v.begin(), v.end());
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += upper_bound(v.begin(), v.end(), r - v[i]) - v.begin();
            ans -= lower_bound(v.begin(), v.end(), l - v[i]) - v.begin();
            if (l <= 2 * v[i] && 2 * v[i] <= r)
            {
                ans--;
            }
        }
        cout << ans / 2 << "\n";
    }
    return 0;
}

/*
5 4 0 0
0 1 5 5
*/







/*
1 2 3 4 5
*/