#pragma GCC Optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifdef LOCAL
#define FAST_COMPILEr
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

int n;
vector<vector<int>> m(13, vector<int>(13));
void marck(int i, int j, int au)
{
    for (int l = 0; l < n; l++)
    {
        m[i][l] += au;
        m[l][j] += au;
    }
    for (int l = 0; l < n; l++)
    {
        if (i + l < n && j + l < n)
        {
            m[i + l][j + l] += au;
        }
        if (i - l >= 0 && j - l >= 0)
        {
            m[i - l][j - l] += au;
        }
        if (i - l >= 0 && j + l < n)
        {
            m[i - l][j + l] += au;
        }
        if (i + l < n && j - l >= 0)
        {
            m[i + l][j - l] += au;
        }
    }
}

ll it = 0;
ll dp(int x, int y)
{
    if (x == 0)
    {
        return 1;
    }
    ll cnt = 0;
    for (int j = 0; j < n; j++)
    {
        if (m[y][j] >= 1)
            continue;
        marck(y, j, 1);
        cnt += dp(x - 1, y + 1);
        marck(y, j, -1);
    }
    return cnt;
}

// if col break 42649393
//
signed main()
{
    cin >> n;
    cout << dp(n,0) << endl;
}

/*
A * B  C + D - +




*/