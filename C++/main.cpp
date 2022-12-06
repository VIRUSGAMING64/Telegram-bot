#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <bits/stl_algo.h>
#include <bits/cpp_type_traits.h>
using namespace std;
#define ll long long

int arr[1000000];
int res = 0;
int recbsh(int l,int r,int n)
{
    res++;
    if(l > r)return -1;
    int m = (l+r)/2;
    if(n == arr[m])
    {  
        return m;
    }
    if(arr[m] > n)return recbsh(l,m-1,n);
    else return recbsh(m+1,r,n);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i <n; i++)
    {
        arr[i] = rand()%10000;
    }
    sort(arr,arr+n);
    int f;
    cin >> f;
    f = recbsh(0,n,f);
    cout << res << endl;
    cout <<f<<": " <<arr[f] << endl;
}