#pragma GCC Optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifdef LOCAL
#define FAST_COMPILE
#endif
#ifndef FAST_COMPILE
#ifdef LOCAL
#include "includes/debug/debug.h"
#include "includes/nums/floatx.hpp"
#include "includes/ttmath/ttmath.h"
#include "includes/json/json.hpp"
#include <omp.h>
#include <unistd.h>
#include "includes/win/api.hpp"
#include <windows.h>
using namespace literals;
using namespace flx;
using namespace ttmath;
using namespace nlohmann;
using namespace std;
using namespace chrono;
#endif
#endif
#ifdef FAST_COMPILE
using namespace std;
#define debug
#endif
#ifndef LOCAL
using namespace std;
#define debug
#endif
#define pb push_back
#define ll long long
#define ull unsigned ll
#define all(x) x.begin(), x.end()
#define ld long double
#define fx ld // antes estaba otra cosa
#define ull unsigned ll
#define S second
#define F first
#define THREAD_NUM 32
#define MOD 1000000007
const ll INF = 1e18, MAXN = 1e6;
typedef tree<ll, null_type, less_equal<ll>,
             rb_tree_tag, tree_order_statistics_node_update>
    TREE;

class sol
{
public:
    vector<int> a;
    vector<vector<int>> st;
    int rec(int n, int l, int r)
    {
        if (l == r)
        {
            st[n] = {a[l]};
            return 0;
        };
        int m = (l + r) / 2;
        int q1 = rec(n * 2, l, m);
        int q2 = rec(n * 2 + 1, m + 1, r);
        if (st[n * 2][st[n * 2].size() - 1] == st[n * 2 + 1][0] - 1)
        {

            for (auto c : st[n * 2])
            {
                st[n].push_back(c);
            }
            for (auto c : st[n * 2 + 1])
            {
                st[n].push_back(c);
            }
            return q1 + q2;
        }
        for (auto c : st[n * 2 + 1])
        {
            st[n].push_back(c);
        }
        for (auto c : st[n * 2])
        {
            st[n].push_back(c);
        }
        return q1 + q2 + 1;
    }
    sol()
    {
        int n;
        cin >> n;
        a.resize(n);
        st.resize(n * 5);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        auto c = rec(1,0,n-1);
        if(is_sorted(all(st[1]))){
            cout << c << endl;
        }else{
            cout << -1 << endl;
        }
    }
};

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        sol s;
    }
}

/*
A * B  C + D - +

*/