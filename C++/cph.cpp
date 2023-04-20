
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef LOCAL
#include "debug/debug.h"
#include <omp.h>
#include <unistd.h>
#include <windows.h>
#include "json/json.hpp"
using namespace nlohmann;
using namespace literals;
#endif
#define pb push_back
#define ll long long
#define ull unsigned ll
#define S second
#define F first
    using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define THREAD_NUM 16

int main()
{
    json res;
    ifstream in("D:/SteamLibrary/steamapps/common/dota 2 beta/game/dota/team_info_cache.json");
    in >> res;
    cout << res["teams"][0]["members"][0]["account_id"] << endl;

    cout << "EXIT SUCCESSFUL" << endl;
}