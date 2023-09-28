#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define F first
#define S second

using namespace std;

vector <ll> bit;

void add (ll n, ll k, ll x) {
    while (k <= n) {
        bit[k]+=x;
        k+=k&-k;
    }
}
ll sum (ll k) {
    ll s = 0;
    while (k >= 1) {
        s+=bit[k];
        k-=k&-k;
    }
    return s;
}

ll que (ll a, ll b) {
    return sum(b) - sum(a-1);
}

int main() {

  ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, k, r;
    cin >> n >> k >> r;
    //vector <bool> v (n+1, 0);
    bit.resize(n+1);
    for (ll i = 0; i < k; i++) {
        ll a; cin >> a;
        add(n, a, 1);
    }
    ll asw = 0, cc = 0;

    for (ll i = 1; i <= n; i++) {
       ll x = i+r-1;
       cc = 0;
       if (x > n) continue;
       cc = que(i,x);
       ll ro = que(x,x);
       if (cc == 0) {
           add(n, x, 1);
           add(n, x-1, 1);
           asw+=2;
       } else if (cc == 1) {
           if(ro != 1) {
            add(n, x, 1);
           }else {
            add(n, x-1, 1);
           }
           cc = que(x,x);

           asw+=1;
       }
    }

    cout << asw;

    return 0;
}
