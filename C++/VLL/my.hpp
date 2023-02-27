#include <bits/stdc++.h>
#define ll long long
#define S second
#define F first
using namespace std;
template<class T>
void out(T a)
{
    cout << a << "\n";
}
template<class... res,class T>
void out(T a,res... b)
{
    cout << a << " ";
    out(b...);
}
template<class T>  
void in(T& a)
{
    cin >> a;
}
template<class...res,class T>
void in(T& a,res&... b)
{
    cin >> a;
    in(b...);
}

