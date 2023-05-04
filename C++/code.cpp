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
#define fx ld // antes estaba otra cosa
#define ull unsigned ll
#define S second
#define F first
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define THREAD_NUM 32
const ll MOD = 1e9 + 7, INF = 1e18, MAXN = 1e6;

bool eval(vector<int> &a)
{
    ll sum = 0;
    map < int, bool> m;
    int n = a.size();
    for(int i = 0 ;i < n;i++){
        sum += a[i];
        sum%=a.size();
        if(m[sum]){
            return 0;
        }
        m[sum] = 1;
    }
    return 1;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int te;
    cin >> te;
    while (te--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        if (n % 2)
        {
            for (int i = 0; i < n; i++)
            {
                a[i] = i+1;
            }
            auto F = eval(a);
            if (F)
            {
                for (auto c : a)
                {
                    cout << c << " ";
                }
            }
            else
            {
                cout << "-1";
            }
        }
        else
        {
            for (int i = 0; i < n;i++){
                if(i%2){
                    cout << i << " ";
                }else{
                    cout << n - i << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}

/*
n, n-1, 2, n-3 ...
*/