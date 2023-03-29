#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define ull unsigned long long ll
#define ll long long
#define F first
#define S second
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
auto mul(vector<vector<ll>> a1,vector<vector<ll>> b1){
    auto c = a1;
    for(ll a = 0; a < a1.size(); a++){
        for(ll b = 0; b < b1.size(); b++){
            c[a][b] = 0;
            for(ll i = 0; i < a1.size(); i++){
                c[a][b] += (a1[a][i]%MOD * b1[i][b]%MOD)%MOD;
                c[a][b] %= MOD;
            }
        }
    }
    return c;
} 

auto bpow(vector<vector<ll>> m,ll e){
    if(e    == 1)return m; 
    if(e == 0){
        vector<vector<ll>> t(m.size(),vector<ll> (m.size(),1));
        for(ll i=0;i<m.size();i++){
            t[i][i] = 0;
        }
        return t;
    }
    auto T = bpow(m,e/2);
    T = mul(T   ,T);
    if(e%2 == 1){
        T = mul(T,m);
    }
    return T;
}
 
int main(){
    FAST;
    ll n;
    cin >> n;
    vector<vector<ll>> a(2,vector<ll>(2,1));
    a[0][0] = 0;
    a = bpow(a,n+1);
    cout << a[0][0] << endl;
    return 0;
}

