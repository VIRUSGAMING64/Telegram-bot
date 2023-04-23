
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef LOCAL
#include <omp.h>
#include <unistd.h>
#include <windows.h>
#endif
#define pb push_back
#define ll long long
#define ld long double
#define fx long double // antes estaba otra cosa
#define ull unsigned ll
#define S second
#define F first
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define THREAD_NUM 32
#define ITERS 1000000
vector<fx> va = {0, 0}, y = {4, 8, 12, 16, 20,24,28,40};
vector<vector<fx>> x = {
    {1, 2, 3, 4, 5,6,7,10}, {1, 2, 3, 4, 5,6,7,10}
};

fx B = 0;
fx learn = 0.0001;

void learnF() // linear
{             // X data is matrix of n * number of va
#pragma omp parallel for
    for (int i = 0; i < ITERS; i++)
    {
        fx preds = B;
        fx AC = y[i % y.size()];
        for (int j = 0; j < va.size(); j++)
        {
            preds += va[j] * x[j][i % x[j].size()];
        }
        fx err = preds - AC;
        for (int j = 0; j < va.size(); j++)
        {
            va[j] = va[j] - x[j][i % x[j].size()] * err * learn;
        }
        B = B - err * learn;
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
            preds += va[j] * x[j][i % x[j].size()];
        }
        cout << preds << " < -> " << y[i] << endl;
        ep += (preds - y[i]);
    }
    ep /= y.size();
    cerr << "prom error:  +- " << ep * sign(ep) << endl;
}





signed main()
{   
    omp_set_num_threads(THREAD_NUM);
    learnF();
    for (auto c : va)
    {
        cout << c << endl;
    }
    cout << B << endl;
    eval();
}