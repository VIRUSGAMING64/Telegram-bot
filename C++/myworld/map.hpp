#include <windows.h>
#include <bits/stdc++.h>
#define CHUNKSIZE 20
#define PLAYER 0
#define DIRT 1
#define ROCK 2
#define VOID_POS 3
using namespace std;

struct PLAY_POS{
    int x,y;
};

void LoadPlayerPos(PLAY_POS &pos)
{
    ifstream po("playerpos");
    po >> pos.x >> pos.y;
}


bool InitializeChunk(int x, int y, string map_path)
{

    string chunkname = map_path + "/";
    chunkname.push_back(x + '0');
    chunkname.push_back(y + '0');
    auto chunk = CreateFileA(chunkname.c_str(), FILE_ALL_ACCESS, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
    if (chunk == INVALID_HANDLE_VALUE)
    {
        cerr << "No Created new chunck file...\n";
        return 0;
    }
    CloseHandle(chunk);
    ofstream map(chunkname.c_str());
    for (int i = 0; i < CHUNKSIZE; i++)
    {
        for (int j = 0; j < CHUNKSIZE; j++)
        {
            map << 1 + rand() % (VOID_POS - 1) << " ";
        }
        map << endl;
    }
    map.close();
    return 1;
}

bool CreateMap(string path)
{
    path += "/MAP";
    bool new_map = CreateDirectoryA(path.c_str(), NULL);
    if (!new_map)
    {
        cerr << "Map already exist..." << endl;
        return 0;
    }
    return InitializeChunk(0, 0, path);
}

vector<vector<int>> LoadChunk(int x, int y, string map_path)
{
    string chunkname = map_path + "/";
    chunkname.push_back(x + '0');
    chunkname.push_back(y + '0');
    cerr << "Loading Chunk: " << chunkname << endl;
    ifstream map(chunkname.c_str());
    vector<vector<int>> mapa(CHUNKSIZE,vector<int> (CHUNKSIZE));
    for (int i = 0; i < CHUNKSIZE; i++)
    {
        for (int j = 0; j < CHUNKSIZE; j++)
        {
            map >> mapa[i][j]; 
        }
    }
    return mapa;
}
