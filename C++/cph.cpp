
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
#define fx long double // antes estaba otra cosa
#define ull unsigned ll
#define S second
#define F first
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define THREAD_NUM 32

class num
{
public:
    bool neg = false; // true if negative number
    string N = "0";
    short THREADS = 16;
    void in_line_rep()
    {
        mutex mtx;
        omp_set_num_threads(this->THREADS);
        for (int j = 0; j < 10; j++)
        {
#pragma omp parallel for
            for (int i = 0; i < N.size(); i++)
            {
                mtx.lock();
                if (N[i] < '0' || N[i] > '9')
                {
                    if (i < 0 || i > N.size())
                        continue;
                    N.erase(N.begin() + i);
                }
                mtx.unlock();
            }
        }
    }
    num() {}
    num(int res)
    {
        if (res < 0)
            neg = 1;
        N = to_string(res);
        if (res < 0)
            in_line_rep();
    }
    num(long long res, bool inl = 0)
    {
        if (res < 0)
            neg = 1;
        if (res < 0)
            in_line_rep();
        N = to_string(res);
    }
    num(string res, bool inl = 1)
    {
        N = res;
        if (inl)
            in_line_rep();
        if (res[0] == '-')
            neg = 1;
    }
    int size()
    {
        return this->N.size();
    }
    bool up(num &b)
    {

        if (this->neg && !b.neg)
        {
            return false;
        }
        else if (!this->neg && b.neg)
        {
            return 1;
        }
        else if (this->neg && b.neg)
        {
            if (this->size() > b.size())
            {
                return 0;
            }
            else if (this->size() < b.size())
            {
                return 1;
            }
            else
            {
                for (int i = 0; i < this->size(); i++)
                {
                    if (this->N[i] < b.N[i])
                        return 1;
                }
            }
        }
        else
        {
            if (this->N.size() > b.N.size())
            {
                return 1;
            }
            else if (this->N.size() < b.N.size())
            {
                return 0;
            }
            else
            {
                for (size_t i = 0; i < this->size(); i++)
                {
                    if (this->N[i] > b.N[i])
                    {
                        return 1;
                    }
                }
                return 0;
            }
        }
        return 0;
    }
    bool eq(num &b)
    {
        if (this->N == b.N && this->neg == b.neg)
            return 1;
        return 0;
    }

    void sum(num &b)
    {
        if (this->neg == b.neg) // sum normal
        {
            while (this->size() < b.size())
                this->N = "0" + this->N;
            while (b.size() < this->size()) // optimizar luego XD
                b.N = "0" + b.N;
            int i = this->size() - 1;
            bool carry = 0;
            while (i != -1)
            {
                int res = (int)this->N[i] + (int)b.N[i] - (int)'0' + carry - (int)'0';
                carry = 0;
                this->N[i] = res % 10 + '0';
                if (res > 9)
                {
                    carry = 1;
                }
                i--;
            }
            if (carry)
            {
                this->N = "1" + this->N;
            }
        }
        else
        {
        }
    }
    string to9()
    {
        string st = "";
        for (auto &c : this->N)
        {
            st += '9' - (c - '0');
        }
        return st;
    }
};

num operator+(num a, num b)
{
    a.sum(b);
    return a;
}

bool operator==(num a, num b)
{
    return a.eq(b);
}
bool operator!=(num a, num b)
{
    return !a.eq(b);
}
bool operator>=(num a, num b)
{
    return a.eq(b) || a.up(b);
}
bool operator<=(num a, num b)
{
    return a.eq(b) || (!(a.up(b)));
}
bool operator<(num a, num b)
{
    if (a == b)
        return 0;
    return !(a.up(b));
}
bool operator>(num a, num b)
{
    return a.up(b);
}
ostream &operator<<(ostream &out, num t)
{
    if (t.neg)
        out << "-";
    out << t.N;
    return out;
}

signed main()
{
    int err = 0;



    cout << "total errors: " << err << endl;
}