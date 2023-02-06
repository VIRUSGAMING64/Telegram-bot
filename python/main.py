#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll lisay(vector<ll> &x)
{
    vector<ll> doom;
    for(int i = 0; i < x.size(); i++)
    {
        ll c = x[i];
        ll res = lower_bound(doom.begin(),doom.end(),c)-doom.begin();
        ll asw = doom.size();
        if(res == asw)
        {
            doom.push_back(c);
        }
        else
        {
            doom[res] = c;
        }
    }
    return doom.size();
}

int main() {
    int n;
    cin >> n;
    vector<ll> LOCA(n);
    for(int i = 0; i < n; i++)
    {
        cin >> LOCA[i];
    }
    cout << lisay(LOCA) << endl;

}