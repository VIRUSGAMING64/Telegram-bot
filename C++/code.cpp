#pragma GCC optimize("Ofast")
#include <ext/pb_ds/tree_policy.hpp>
#include <thread>
#include <atomic>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
#include <bits/stdc++.h>
using namespace std;
vector<int> dijsktra(vector<vector<pair<int,int> > > g/*{[a].{b,w}}*/,int x);
#define vvT vector<vector<T> >
#define TCT template<class T>
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define vT vector<T>
#define vvT vector<vector<T> >
#define sortv(v) sort((v).begin(),(v).end())
#define sortvr(v) sort((v).rbegin(),(v).rend())
#define FOR(a) for(int i=0;i<(a);i++)
#define ATOB(a,b) for(int i=(a);i<(b);i++)
#define RESIZEMAX(a,b) ((a).size()>(b).size())?((b).resize((a).size())):((a).resize((b).size()));
#define sh short
#define db double
#define ll long long 
#define ld long db
#define int2 atomic<int>
#define ll2 atomic<ll>
#define ld2 atomic<ld>
#define db2 atomic<db>
#define endl "\n"
#define pb push_back
#define vi vector<int>
#define vvi vector<vi >
#define pii pair<int,int>
#define vpii vector<pii>
#define vvl vector<vl >
#define vbool vector<bool>
#define vl vector<ll>
#define vdb vector<db>
#define vld vector<ld>
#define vsh vector<sh>
#define rsz resize
#define sz size
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define ms998  for(int i=0;i<10e6*8+10e6+10e5*5;i++){cnt++;}
#define inicio auto main() -> int {threads();return 0;}
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define RAYA cout<<"==========================================="<<endl
#define COUNTBITS(a) __builtin_popcount((a))
#define outputfile freopen("salida.txt","w",stdout);
struct block
{
    int act = 0;
    int ini = 0;
    int fin = 1000000000;
    int mini = 1000000000;
    int minipos = 1000000000;
};

struct edge
{
    int a,b,w;
};

struct punto
{
    ld x = 0;
    ld y = 0;
};
inline vector<edge> makeG(int,bool);
inline ld integral(ld func(ld x),ld a,ld b);
template<class T>
inline T sum_to_n(T n);
template<class T>
inline T ceil(T n,T m);
template<class T>
inline T floor(T n,T m);
inline int nxt();
template<class T>
inline void nxt(T& x);
template<class T>
inline int findv(vT,T);
inline vector<ll>fibonacci(int,int);
template<class T>
inline istream& operator>>(istream& in,vector<T>& v);
template<class T>
inline bool existM(vector<vector<T> >,T);
template<class T>
inline void coutmatrix(vector<vector<T> >);
template<class T>
inline void cinmatrix(vector<vector<T> >&);
template<class T>
inline int bsh(vector<T>,T);
template<class T>
inline int lsh(vT,T);
template<class T>
inline T gcd(T,T);
inline int acmquery(vvi,int,int,int,int);
inline vvi acmatrix(vvi org);
template<class T,class R>
inline void cinv(vector<pair<T,R> >&);
template<class T>
inline vector<bool> sieve(T);
template<class T>
inline void coutv(vector<T> v);
template<class T>
inline void cinv(vector<T>& v);
template<class T,class R>
inline void coutv(vector<pair<T,R>>);
inline vl fibsum(vl);
template<class T>
inline vT fromset(vT);
template<class T>
inline void dfs(T,vector<bool>,vvT);
inline ll fastgcd(ll,ll);
inline vi bfs(vvi,int);
template<class T>
inline T lcm(T,T);
inline void threads();
template<class T>
inline ostream& operator<<(ostream& out,vector<T> v);
inline void makeG(vvi&,int,int,bool,bool);
inline void coutdist(vi,int);
inline string cifrar(string);
inline vector<bool> segmentedSieve(ll,ll);
inline void core1();
inline void core2();
inline void core3();
inline void core4();
template<class T>
inline bool isprime(T);
inline vl coprimos(ll);
inline vi coprimos(int);
inline void setbit(int&,int);
inline void setbit(ll&,ll);
inline void updatesqrt(vi& v,vector<block>& vs,int in,int newe);
inline block sqrtquery(vector<block>,vi,int,int);
inline void coutblock(block);
template<class T>
inline vector<block> buildsqrt(vector<T> v);
inline punto operator+(punto a,punto b);
inline punto operator*(punto a,punto b);
inline punto operator/(punto a,punto b);
inline punto operator-(punto a,punto b);
template<class T>
inline vT facprim(T n);
inline string bin(int);
inline string bin(ll);
template<class T>
inline vT randarr(int _tsize_,int modo);
inline ll phi(ll n);
inline vvi randG(int maxn,int a,int maxp);
inline vvi randmatrix(int n,int m,int modo);
inline int query(vi segment_tree,int nod,int ini,int fin,int a,int b);
inline void buildST(vi& segment_tree,vi& list,int nod,int ini,int fin);
template<class T>
inline short count1(T n);
inline string operator*(string a,ll n);
inline string operator*(ll n,string a);
inline string __addl__(string a,ll n);
inline void operator*=(string& a,ll n);
inline vi bellmanfort(vector<edge>,int,int);
template<class T>
inline void debug(T t);
template<class T>
inline void debug(vector<vector<T> > v);
template<class T,class R>
inline void debug(vector<pair<T,R> > v);
template<class T>
inline void debug(vector<T> v);
template<class T,class... res>
inline void debug(T t,res... resto);
template<class T>
inline vector<T> operator+(vector<T> a,vector<T> b);
template<class T>
inline vector<T> operator-(vector<T> a,vector<T> b);
template<class T>
inline vector<T> operator/(vector<T> a,vector<T> b);
template<class T>
inline vector<T> operator*(vector<T> a,vector<T> b);
template<class T>
inline void operator+=(vector<T>& a,vector<T> b);
template<class T>
inline void operator-=(vector<T>& a,vector<T> b);
template<class T>
inline void operator*=(vector<T>& a,vector<T> b);
template<class T>
inline void operator/=(vector<T>& a,vector<T> b);
template<class T>
inline int bsh_left(vector<T> __find_vector_,T _num_for_find_);
inline bool NUMBER_OF_BITS(long long a,long long b);
template<class T>
inline void IN(vector<vector<T> >& v);
template<class T,class R>
inline void IN(vector<pair<T,R> >& v);
template<class T>
inline void IN(vector<T>& v);
template<class T>
inline void IN(T& t);
template<class T,class... res>
inline void IN(T& t,res&...resto);
template<class T>
inline pair<ll,pair<ll,ll> > egcd(ll a,ll b);
inline ll modinv(ll den,ll m);
inline ll moddiv(ll num,ll den,ll m);
const ld learn = 0.00000001;
const ll MAXSHORT = 32767ll;
const ll MAXINT = 2147483647ll;
const ll MAXLL = 9223372036854775807ll;
const ll MOD = (ll)10e9 + 7;
template<class T>
inline T bpow(T a,T b,ll mod = MAXLL)
{
    if(b == 0)return 1 % mod;
    if(b == 1)return a % mod;
    T temp = bpow(a,b / 2,mod);
    temp = (temp % mod * temp % mod) % mod;
    if(b & 1)temp = (temp % mod * a % mod) % mod;
    return temp % mod;
}

namespace modOP
{
template<class T>
inline T add(T a,T b,ll mod = MAXLL)
{
    return (T)((a % mod + b % mod) % mod);
}
template<class T>
inline T sub(T a,T b,ll mod = MOD)
{
    return (T)((a % mod - b % mod) % mod);
}
template<class T>
inline T mult(T a,T b,ll mod = MOD)
{
    return (T)((a % mod * b % mod) % mod);
}
}
//sking.nat.cu
using namespace modOP;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace chrono;
/*
                             /*************************************
                              *DELPHI LIC: 44CL-J9DD2M-K9N567-AE8D*
                              *************************************/
///****************************************************************************************************************
///****************************************************************************************************************
///****************************************************************************************************************
///****************************************************************************************************************
///****************************************************************************************************************

inline void core1()
{
    for(int i =1 ; i  < 100000; i++){
        if(i%2 == 0 && i % 3 == 0 && i % 4 == 0 && i % 5 == 0 && i % 6 == 0)cout << i << " ";
    }
}

inline void core2()
{

}

inline void core3()
{

}

inline void core4()
{

}

///****************************************************************************************************************
///****************************************************************************************************************
///****************************************************************************************************************
///****************************************************************************************************************
///****************************************************************************************************************



inline ld integral(ld func(ld x),ld a,ld b)
{
    int N = 100000;
    ld h = (b - a) / N;
    ld s = func(a) + func(b);
    for(int i = 0; i <= N; ++i)
    {
        ld x = a + h * i;
        s += func(x) * ((i & 1) ? 4 : 2);
    }
    s *= h / 3;
    return s;
}

template<class T>
inline vT randarr(int _tsize_,int max_num)
{
    vT created_vector(_tsize_);
    srand(time(0));
    max_num *= 100;
    generate(created_vector.begin(),created_vector.end(),[&](){return (T)(rand() % max_num) / 100;});
    return created_vector;
}

inline void updatesqrt(vi& v,vector<block>& vs,int in,int newe)
{
    int iniblock = 0;
    for(int i = 0;i<int(vs.size());i++)
    {
        if(in <= vs[i].fin && in >= vs[i].ini)
        {
            iniblock = vs[i].act;
            break;
        }
    }
    v[in] = newe;
    if(vs[iniblock].mini > newe)
    {
        vs[iniblock].mini = newe;
        vs[iniblock].minipos = in;
    }
}

template<class T>
inline vector<block> buildsqrt(vector<T> v)
{
    int n = v.size();
    int b = sqrt(n) + 1;
    int act = 0;
    vector<block> vb(b);
    int cnt2 = 0;
    for(int i = 0;i < n;i++)
    {

        if(cnt2 == b)
        {
            cnt2 = 0;
            vb[act].act = act;
            vb[act].fin = i;
            act++;
            vb[act].ini = i + 1;
        }

        if(v[i] < vb[act].mini)
        {
            vb[act].mini = v[i];
            vb[act].minipos = i;
        }


        cnt2++;

    }
    if(vb[act].fin == 1000000000)
    {
        vb[act].act = act;
        vb[act].fin = v.size() - 1;
    }
    return vb;
}


inline block sqrtquery(vector<block> v,vi vq,int in,int fi)
{
    int iniblock = 0;
    for(int i = 0;i<int(v.size());i++)
    {
        if(in <= v[i].fin && in >= v[i].ini)
        {
            iniblock = v[i].act;
            break;
        }
    }

    block minimo;
    for(int i = in;i <= v[iniblock].fin && i <= fi;i++)
    {
        if(minimo.mini > vq[i])
        {
            minimo.mini = vq[i];
            minimo.minipos = i;
        }
    }
    int actbl = iniblock + 1;
    for(int i = actbl; i < int(v.size()); i++)
    {
        actbl = i;
        if(v[i].fin > fi)
        {
            break;
        }
        if(minimo.mini > v[i].mini)
        {
            minimo = v[i];
        }
    }
    for(int i = max(v[actbl].ini,in);i <= fi;i++)
    {
        if(minimo.mini > vq[i])
        {
            minimo.mini = vq[i];
            minimo.minipos = i;
            minimo.ini = i;
            minimo.fin = i;
            minimo.act = actbl;
        }
    }
    return minimo;
}

inline int acmquery(vvi v,int i,int j,int ii,int jj)
{
    if(ii == 0 || jj == 0)
    {
        return v[ii][jj] - v[i][j];
    }
    if(j == 0 && i == 0)
    {
        return v[ii][jj];
    }
    if(j == 0)
    {
        return v[ii][jj] - v[i - 1][jj];
    }
    if(i == 0)
    {
        return v[ii][jj] - v[ii][j - 1];
    }
    return v[ii][jj] - v[i - 1][jj] - v[ii][j - 1] + v[i - 1][j - 1];
}


inline vvi acmatrix(vvi org)
{
    vvi acu = org;
    for(int i = 1;i<int(org[0].size());i++)
    {
        acu[0][i] += acu[0][i - 1];
    }
    for(int i = 1;i<int(org.size());i++)
    {
        for(int j = 0;j<int(org[i].size());j++)
        {
            if(j == 0)
            {
                acu[i][j] += acu[i - 1][j];
            }
            else
            {
                acu[i][j] += acu[i - 1][j] + acu[i][j - 1] - acu[i - 1][j - 1];
            }
        }
    }
    return acu;
}

inline vector<bool> segmentedSieve(ll L,ll R)
{
    vbool isPrime(R - L + 1,true);
    ll lim = (int)sqrt(R);
    for(ll i = 2; i <= lim; ++i)
        for(ll j = max(i * i,(L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if(L == 1)
        isPrime[0] = false;
    return isPrime;
}

inline int query(vi segment_tree,int nod,int ini,int fin,int a,int b)
{
    if(a <= ini && fin <= b)
    {
        return segment_tree[nod];
    }
    if(fin < a || b < ini)
    {
        return 1000000000;
    }
    int mit = (ini + fin) / 2;
    int q1 = query(segment_tree,nod * 2,ini,mit,a,b);
    int q2 = query(segment_tree,nod * 2 + 1,mit + 1,fin,a,b);
    return min(q1,q2);
}
inline void buildST(vi& segment_tree,vi& list,int nod,int ini,int fin)
{
    if(ini == fin)
    {
        segment_tree[nod] = list[ini];
        return;
    }
    int mit = (ini + fin) / 2;
    buildST(segment_tree,list,nod * 2,ini,mit);
    buildST(segment_tree,list,nod * 2 + 1,mit + 1,fin);
    segment_tree[nod] = min(segment_tree[nod * 2],segment_tree[nod * 2 + 1]);
    return;
}

inline void makeG(vvi& grafo,int nodos,int aristas,bool dirigido = false,bool inicio0 = false)
{
    grafo.resize(nodos);
    for(int i = 0;i < aristas;i++)
    {
        int a,b;
        nxt(a);nxt(b);
        if(!inicio0)
        {
            a--;
            b--;
        }
        if(!dirigido)
        {
            grafo[a].pb(b);
            grafo[b].pb(a);
        }
        else
        {
            grafo[a].pb(b);
        }
    }
}

inline vector<edge> makeG(int aristas,bool dirigido = false)
{
    vector<edge> v;
    FOR(aristas)
    {
        int a,b,w;
        cin >> a >> b >> w;
        edge e;
        e.a = a;e.b = b;e.w = w;
        v.pb(e);
        if(!dirigido)
        {
            e.b = a;e.a = b;
            v.pb(e);
        }
    }
    return v;
}


template<class T>
inline void dfs(T x,vector<bool>& visited,vvT &grafo)
{
    if(visited[x])return;
    visited[x] = true;
    for(auto c : grafo[x])
    {
        dfs(c,visited,grafo);
    }
}

inline vi bfs(vvi grafo,int x)
{
    vi dist(int(grafo.size()),1e8);
    vector<bool> visited(int(grafo.size()));
    visited[x] = 1;
    dist[x] = 0;
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int s = q.front();q.pop();
        for(auto c : grafo[s])
        {
            if(visited[c])continue;
            visited[c] = 1;
            dist[c] = dist[s] + 1;
            q.push(c);
        }
    }
    return dist;
}

template<class T>
inline vbool sieve(T n)
{
    vector<bool> v(n + 1,1);
    v[0] = v[1] = false;
    for(T i = 4; i <= n; i += 2)
    {
        v[i] = false;
    }
    for(T i = 3; i * i <= n; i += 2)
    {
        if(v[i])
        {
            for(T j = i * i; j <= n; j += 2 * i)
            {
                v[j] = false;
            }
        }
    }
    return v;
}

inline ll fastgcd(ll a,ll b)
{
    if(!a || !b)
    {
        return a | b;
    }
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do
    {
        swap(a,b);
        b = b - a;
    } while(b);
    b >>= __builtin_ctz(b);
    if(a > b)
        return a << shift;
    return 1;
}

template<class T>
inline T gcd(T a,T b)
{
    if(b == 0)return a;
    return gcd(b,a % b);
}
template<class T>
inline T lcm(T a,T b)
{
    return (a * b) / gcd(a,b);
}

template<class T>
inline bool md2(T a)
{
    int t = a / 2;
    db t2 = a / 2;
    return (t == t2);
}

template<class T>
inline int lsh(vT v,T fi)
{
    int n = int(v.size());
    for(int i = 0; i < n; i++)
    {
        if(v[i] == fi)
        {
            return i;
        }
    }
    return -1;
}

template<class T,class R>
inline void cinv(vector<pair<T,R> >& input__vector)
{
    for(int i = 0; i<int(input__vector.size()); i++)
    {
        cin >> input__vector[i].f >> input__vector[i].s;
    }
}


template<class T,class R>
inline void coutv(vector<pair<T,R>> __output__vector)
{
    for(int i = 0; i<int(__output__vector.size()); i++)
    {
        cout << __output__vector[i].f << " " << __output__vector[i].s << endl;
    }
}

template<class T>
inline void cinv(vector<T>& input__vector_)
{
    for(int i = 0; i<int(input__vector_.size()); i++)
    {
        cin >> input__vector_[i];
    }
}

template<class T>
inline void coutv(vector<T> __output_vector_)
{
    for(int i = 0; i<int(__output_vector_.size()); i++)
    {
        cout << __output_vector_[i] << " ";
    }
    cout << endl;
}
template<class T>
inline int bsh(vector<T> __find_vector_,T _num_for_find_)
{
    int m = int(__find_vector_.size()),n = 0,mn;
    for(int i = 0;n <= m; i++)
    {
        mn = n + (m - n) / 2;
        if(__find_vector_[mn] == _num_for_find_)
        {
            return mn;
        }

        if(_num_for_find_ < __find_vector_[mn])
        {
            m = mn - 1;
        }
        else if(_num_for_find_ > __find_vector_[mn])
        {
            n = mn + 1;
        }
    }
    return -1;
}


template<class T>
inline int bsh_left(vector<T> __find_vector_,T _num_for_find_)
{
    if(_num_for_find_ > __find_vector_[__find_vector_.size() - 1])return __find_vector_.size() - 1;
    int m = int(__find_vector_.size()) + 1,n = -1,mn;
    int res = n;
    for(int i = 0;n <= m && i <= 65; i++)
    {
        mn = n + (m - n) / 2;
        if(__find_vector_[mn] == _num_for_find_)
        {
            return mn;
        }

        if(_num_for_find_ < __find_vector_[mn])
        {
            m = mn;
        }
        else if(_num_for_find_ > __find_vector_[mn])
        {
            n = mn;
        }
    }
    return mn;
}


template<class T>
inline void cinmatrix(vector<vector<T> >& __cin__matrix)
{
    for(int i = 0; i<int(__cin__matrix.size()); i++)
    {
        for(int j = 0; j<int(__cin__matrix[i].size()); j++)
        {
            cin >> __cin__matrix[i][j];
        }
    }
}


template<class T>
inline void coutmatrix(vector<vector<T> > v)
{
    for(int i = 0; i < int(v.size()); i++)
    {
        for(int j = 0; j < int(v[i].size()); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T>
inline bool existM(vector<vector<T> > v,T findm)
{
    int mx = -1;
    for(int i = 0;i < v.size();i++)
    {
        for(int j = 0;j < v[i].size();j++)
        {
            if(v[i][j] == findm)
            {
                return true;
            }
        }
    }
    return false;
}

inline vector<ll>fibonacci(ll n,ll modo = 0)
{
    if(modo == 0)modo = MAXLL;
    vl v(2);
    v[0] = 0;
    v[1] = 1;
    for(int i = 1; i < n; i++)
    {
        v.pb(((v[i - 1] % modo) + (v[i] % modo)) % modo);
    }
    return v;
}

template<class T>
inline int findv(vector<T> v,T f)
{
    for(int i = 0;i < v.size();i++)
    {
        if(v[i] == f)
        {
            return i;
        }
    }
    return -1;
}

template<class T>
inline vT fromset(vT v)
{
    vT to_set;
    set<T> aux_set;
    for(int i = 0;i<int(v.size());i++)
    {
        aux_set.insert(v[i]);
    }
    for(auto& c : aux_set)
    {
        to_set.pb(c);
    }
    return to_set;
}

template<class _temp_var>
inline void nxt(_temp_var& __cin__)
{
    cin >> __cin__;
}

inline int nxt()
{
    int x;
    cin >> x;
    return x;
}

inline void threads()
{
    thread c1(core1);
    thread c2(core2);
    thread c3(core3);
    thread c4(core4);
    c1.join();
    c2.join();
    c3.join();
    c4.join();
}

inline string cifrar(string s)
{
    int l;
    ifstream clave("18073830967516288756");
    if(clave.is_open())
    {

        for(int i = 0; i<int(s.size()); i++)
        {
            clave >> l;
            s[i] ^= l % sizeof(s) / sizeof(char);
            if(i == 0)
            {
                s[i] ^= l;
            }
            while(s[i] == 0)
            {
                s[i] ^= i;
            }
        }
    }
    else
    {
        ofstream claveo("18073830967516288756");
        string claves = "";
        for(int i = 100; i < 100000009; i++)
        {
            claves += to_string((1 + rand() % 100000000 + 1) % i) + " ";
        }
        claveo << claves;
        s = cifrar(s);
    }
    return s;
}

inline punto operator+(punto a,punto b)
{
    punto c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}
inline bool operator==(punto a,punto b)
{
    return (a.x == b.x && a.y == b.y) ? (true) : (false);
}
inline punto operator-(punto a,punto b)
{
    punto c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

template<class T>
inline bool isprime(T n)
{
    if((!(n & 1)) && n != (1 << 1))return false;
    for(T i = 3;i * i < n;i += 2)
    {
        if(n % i == 0){
            return false;
        }
    }
    return true;
}


template<class T>
inline vT facprim(T n)
{
    vT f;
    for(T i = 2;i * i <= n;i++)
    {
        while(n % i == 0)
        {
            f.pb(i);
            n /= i;
        }
    }
    if(n > 1)
    {
        f.pb(n);
    }
    return f;
}

inline string bin(int a)
{
    string bi = "";
    for(int i = 0;i < 32;i++)
    {
        if(a & (1 << i))
        {
            bi = "1" + bi;
        }
        else
        {
            bi = "0" + bi;
        }
    }
    return bi;
}

inline string bin(ll a)
{
    string bi = "";
    for(ll i = 0;i < 64LL;i++)
    {
        if(a & (1LL << i))
        {
            bi = "1" + bi;
        }
        else
        {
            bi = "0" + bi;
        }
    }
    return bi;
}


inline vvi randmatrix(int n,int m,int modo)
{
    srand(time(0));
    vvi _rand_matrix(n,vi(m,rand() % modo));
    FOR(n)
    {
        generate(_rand_matrix[i].begin(),_rand_matrix[i].end(),[&](){return (int)(rand() % modo) / 100;});
    }
    return _rand_matrix;
}

template<class T>
inline void setbit(T& num,T bit)
{
    T _move = 1;
    if(num & (_move << bit))
    {
        num = num ^ (_move << bit);
    }
    else
    {
        num = num | (_move << bit);
    }
}

template<class T>
inline bool par(T x)
{
    T __aux = 1;
    if(x & __aux)return false;
    return true;
}

inline ll phi(ll n)
{
    ll ans = n;
    auto fact = fromset(facprim(n));
    for(int i = 0;i<int(fact.size());i++)
    {
        ll p = fact[i];
        ans /= p;
        ans *= (p - 1);
    }
    return ans;
}

template<class T>
inline short count1(T n){
    int cnt3 = 0;
    string ss = bin(n);
    for(int i = 0;i < ss.size();i++)
    {
        if(ss[i] == '1')
        {
            cnt3++;
        }
    }
    return cnt3;
}

inline vi bellmanfort(vector<edge> v,int nodos = 50,int x = 0)
{
    vi dist(nodos,100000);
    dist[x] = 0;
    for(int i = 0;i < nodos;i++)
    {
        for(auto c : v)
        {
            int a = c.a,b = c.b,w = c.w;
            dist[b] = min(dist[b],dist[a] + w);
        }
    }
    return dist;
}



inline string __addl__(string a,ll n)
{
    if(n == 0)
    {
        return "";
    }
    if(n % 2 == 0)
    {
        string t = __addl__(a,n / 2);
        return t + t;
    }
    else
    {
        string t = __addl__(a,n / 2);
        return t + t + a;
    }
}

inline string __addl__(ll n,string a)
{
    if(n == 0)
    {
        return "";
    }
    if(n % 2 == 0)
    {
        string t = __addl__(a,n / 2);
        return t + t;
    }
    else
    {
        string t = __addl__(a,n / 2);
        return t + t + a;
    }
}

inline string operator*(string a,ll n)
{
    return __addl__(a,n);
}

string operator*(ll n,string a)
{
    return __addl__(a,n);
}

inline void operator*=(string& a,ll n)
{
    a = __addl__(a,n);
}

inline void operator*=(ll n,string& a)
{
    a = __addl__(a,n);
}

inline vvi randG(int maxn,int a,int maxp)
{
    srand(time(0));
    vvi __rand_graph(a + 1);
    __rand_graph[0].pb(maxn);
    __rand_graph[0].pb(a);
    for(int i = 1;i < a;i++)
    {
        __rand_graph[i].pb(rand() % maxn);
        __rand_graph[i].pb(rand() % maxn);
        __rand_graph[i].pb(1 + rand() % maxp);
    }
    return __rand_graph;
}

template<class T>
inline istream& operator>>(istream& in,vector<T>& v)
{
    for(int i = 0;i < (int)v.size();i++)
    {
        in >> v[i];
    }
    return in;
}

template<class T>
inline ostream& operator<<(ostream& out,vector<T> v)
{
    for(auto c : v)out << c << " ";
    out << "\n";
    return out;
}


template<class T>
inline void debug(T t)
{
    cout << t << " ";
    cout << endl;
}


template<class T>
inline void debug(vector<vector<T> > v)
{
    for(int i = 0; i < int(v.size()); i++)
    {
        for(int j = 0; j < int(v[i].size()); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T,class R>
inline void debug(vector<pair<T,R> > v)
{
    for(int i = 0;i < v.size();i++)
    {
        cout << v[i].f << " " << v[i].s << endl;
    }
}

template<class T>
inline void debug(vector<T> v)
{
    for(int i = 0; i<int(v.size()); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

template<class T>
inline void IN(vector<vector<T> >& v)
{
    for(int i = 0;i<int(v.size());i++)
    {
        for(int j = 0;j<int(v[i].size());j++)
        {
            cin >> v[i][j];
        }
        cout << endl;
    }
}

template<class T,class R>
inline void IN(vector<pair<T,R> >& v)
{
    for(int i = 0;i < v.size();i++)
    {
        cin >> v[i].first >> v[i].second;
    }
}

template<class T>
inline void IN(vector<T>& v)
{
    for(int i = 0; i<int(v.size()); i++)
    {
        cin >> v[i];
    }
}


template<class T>
inline void IN(T& t)
{
    cin >> t;
}

template<class T,class... res>
inline void IN(T& t,res&...resto)
{
    cin >> t;
    IN(resto...);
}

template<class T,class... res>
inline void debug(T t,res... resto)
{
    cout << t << " ";
    debug(resto...);
}

template<class T>
inline T sum_to_n(T n)
{
    return (n * n + n) / 2;
}

template<class T>
inline T ceil(T n,T m)
{
    if(n % m == 0)
    {
        return n / m;
    }
    return (int(n / m) + 1);
}

template<class T>
inline T floor(T n,T m)
{
    if(n % m == 0)
    {
        return n / m;
    }
    return (int(n / m));
}

template<class T>
inline bool NUMBER_OF_BITS(T a,T b)
{
    T r = COUNTBITS(a);
    T r1 = COUNTBITS(b);
    return !(r >= r1);
}

template<class T>
inline vector<T> operator+(vector<T> a,vector<T> b)
{
    RESIZEMAX(a,b);
    for(int i = 0;i<int(a.size());i++)
    {
        a[i] += b[i];
    }
    return a;
}

template<class T>
inline vector<T> operator-(vector<T> a,vector<T> b)
{
    RESIZEMAX(a,b);
    for(int i = 0;i<int(a.size());i++)
    {
        a[i] -= b[i];
    }
    return a;
}

template<class T>
inline vector<T> operator/(vector<T> a,vector<T> b)
{
    RESIZEMAX(a,b);
    for(int i = 0;i<int(a.size());i++)
    {
        a[i] /= b[i];
    }
    return a;
}

template<class T>
inline vector<T> operator*(vector<T> a,vector<T> b)
{
    RESIZEMAX(a,b);
    for(int i = 0;i<int(a.size());i++)
    {
        a[i] *= b[i];
    }
    return a;
}

template<class T>
inline void operator+=(vector<T>& a,vector<T> b)
{
    RESIZEMAX(a,b);
    for(int i = 0;i<int(a.size());i++)
    {
        a[i] += b[i];
    }

}

template<class T>
inline void operator-=(vector<T>& a,vector<T> b)
{
    RESIZEMAX(a,b);
    for(int i = 0;i<int(a.size());i++)
    {
        a[i] -= b[i];
    }
}

template<class T>
inline void operator*=(vector<T>& a,vector<T> b)
{
    RESIZEMAX(a,b);
    for(int i = 0;i<int(a.size());i++)
    {
        a[i] *= b[i];
    }

}

template<class T>
inline void operator/=(vector<T>& a,vector<T> b)
{
    RESIZEMAX(a,b);
    for(int i = 0;i<int(a.size());i++)
    {
        a[i] /= b[i];
    }
}

inline pair<ll,pair<ll,ll> > egcd(ll a,ll b)//return g,x,y     
{
    pair<ll,pair<ll,ll> > ret;
    if(a == 0)
    {
        ret.F = b;
        ret.S.F = 0;
        ret.S.S = 1;
    }
    else
    {
        ll g,x,y;
        pair<ll,pair<ll,ll> > temp = egcd(b % a,a);
        g = temp.F;
        x = temp.S.F;
        y = temp.S.S;
        ret.F = g;
        ret.S.F = y - (b / a) * x;
        ret.S.S = x;
    }
    return ret;
}

inline ll modinv(ll den,ll m)
{
    pair<ll,pair<ll,ll> > ans = egcd(den,m);
    if(ans.F == 1)
    {
        return (ans.S.F + m) % m;
    }
    return 1;
}

inline ll moddiv(ll num,ll den,ll m)        // den and m must be coprime
{
    if(isprime(m))
    {
        return ((num % m) * (bpow(den,m - 2,m) % m)) % m;
    }
    return (num * modinv(den,m)) % m;
}
/*
For call DSU class
move to the start of the
file or create reference
*/
class DSU
{
    public:
    vector<int> sizes,parent;
    DSU(int n)
    {
        sizes.resize(n);
        parent.resize(n);
        for(int i = 0;i < n;i++)
        {
            sizes[i] = 1;
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if(x == parent[x])
        {
            return x;
        }
        else
        {
            return parent[x] = find(parent[x]);
        }
    }
    bool join(int a,int b)
    {
        a = find(a);
        b = find(b);
        if(a == b)return false;
        if(sizes[b] > sizes[a])swap(a,b);
        sizes[a] += sizes[b];
        parent[b] = a;
        return true;
    }
};

vector<int> dijsktra(vector<vector<pair<int,int> > > g/*{[a].{b,w}}*/,int x)
{
    vector<int> dist(g.size(),10000000);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    dist[x] = 0;
    q.push({0,x});
    while(!q.empty())
    {
        int a = q.top().second;
        q.pop();
        for(auto c : g[a])
        {
            int
                w = c.second,
                b = c.first;
            if(dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
                q.push({-dist[b],b});
            }
        }
    }
    return dist;
}

inicio                                                                                                                                                                                                                                  /*
USERNAMES
* * * * * * * * * * * * * * * * * *
*                                 *
*  dmoj.uclv.edu.cu: Virusgaming  *
*  codeforces.com: VIRUSGAMING    *
*  gmail: virusroger6@gmail.com   *
*  Telegram: @Virusgaming6        *
*  WhatsApp: +5356563068          *
*                                 *
* * * * * * * * * * * * * * * * * */
