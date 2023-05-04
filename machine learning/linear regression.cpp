
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef LOCAL
#include <omp.h>
#include <unistd.h>
#include <windows.h>
#define endl "\n"
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
#define ITERS 10000000
vector<int> grade = {1};
// F(x) = xxx+xx
vector<fx> va = {0,0}, y = {2, 12, 36, 80, 150,252, 392, 1100};
vector<vector<fx>> x = {
    {1, 2, 3, 4, 5, 6, 7, 10}};

ll lg = 0;
fx B = 0;
fx learn = 1e-4;


void learnF() // linear
{             // X data is matrix of n * number of va

    if (va.size() > x.size() || va.size() > grade.size())
        throw "variables or data for variable lossed";
    for (int i = 0; i < ITERS; i++)
    {
        fx preds = B;
        fx AC = y[i % y.size()];
        for (int j = 0; j < va.size(); j++)
        {
            preds += va[j] * pow(x[j][i % x[j].size()], grade[j]);
        }
        fx err = preds - AC;
        for (int j = 0; j < va.size(); j++)
        {
            va[j] = va[j] - (pow(x[j][i % x[j].size()], grade[j]) * err * learn);
            // cout << va[j] << " ba: ";
        }
        B = B - err * learn;
        // cout << B << " err: " << err << endl;
    }
}

int sign(fx res)
{
    return (res < 0) ? (-1) : (1);
}

void eval()
{
    fx ep = 0;
    for (int i = 0; i < y.size(); i++)
    {
        fx preds = B;
        for (int j = 0; j < va.size(); j++)
        {
            preds += va[j] * pow(x[j][i % x[j].size()], grade[j]);
        }
        cout << preds * lg << " < -> " << y[i] * lg << endl;
        ep += (preds * lg - y[i] * lg);
    }
    ep /= y.size();
    cerr << "prom error:  +- " << ep * sign(ep) << endl;
}

void adjust()
{
    fx mx = 0;
#pragma omp parallel for
    for (int i = 0; i < y.size(); i++)
    {
        mx = max(mx, y[i]);
    }
#pragma omp parallel for
    for (int i = 0; i < x.size(); i++)
    {
        for (int j = 0; j < y.size(); j++)
        {
            mx = max(mx, x[i][j]);
        }
    }
    lg = log10(mx);
    lg = pow(10, lg);
#pragma omp parallel for
    for (int i = 0; i < y.size(); i++)
    {
        y[i] /= lg;
    }
#pragma omp parallel for
    for (int i = 0; i < x.size(); i++)
    {
        for (int j = 0; j < y.size(); j++)
        {
            x[i][j] /= lg;
        }
    }
}

signed main()
{
    omp_set_num_threads(THREAD_NUM);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cerr << "float sizeof = " << sizeof(float) << endl;
    cerr << "long double sizeof = " << sizeof(long double) << endl;
    adjust();
    learnF();
    for (int i = 0; i < va.size(); i++)
    {
        cout << "B" << i << ": " << va[i] << " grade: " << grade[i] << endl;
    }
    cout << "A: " << B << endl;
    eval();
    cout << "diga x: ";
    fx dx,res = 0;
    cin >> dx;
    for (int i = 0; i < va.size();i++){
        fx ans = 1;
        for (int j = 0; j < grade[i]; j++){
            ans *= dx;
        }
        res +=  (ans * va[i]);
    }
    cout << res << endl;
}