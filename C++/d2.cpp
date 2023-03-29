#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define N 1000000
#define MOD 1000000007


vector<vector<ll>> pas = {{1},{1,1}};
/*

    for(int i = 1; i <= 2001; i++){
        vector<ll> P = {1};
        for(int k = 0; k < pas[i].size()-1; k++){
            P.push_back((pas[i][k] + pas[i][k+1])%MOD);
        }
        P.push_back(1);
        pas.push_back(P);
    }
*/
ll n,k;
ll F(int x){
    if(x == 1)return n-k+1;
    return ((x-1) * (F(x-1)-1))%MOD;
}

int main()
{
    cin >> n >> k;
    for(int i = 1 ; i <= k ; i++)
    {
        cout << F(i) << endl;
    }
}

