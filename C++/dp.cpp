    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    #ifdef LOCAL
    #define FAST_COMPILE
    #endif
    #ifndef FAST_COMPILE
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
    using namespace std;
    using namespace chrono;
    #include "win/api.hpp"
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

    ll dp[1000][1000];

    signed main()
    {
        ll n,k,d;
        cin >> n >> k >> d;
        dp[0][0] = 1;
        for(ll i = 0 ;  i  <= n; i++){
            for(ll j = 1; j <= k; j++){
                for (ll is = 0; is <= 1; is++)
                {
                    dp[i + j][is || j >= d] += dp[i][is];
                    dp[i + j][is] %= MOD;
                }
            }
        }
        cout << dp[n][1]%MOD << endl;
    }

