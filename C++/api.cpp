#pragma comment(linker, "/STACK:16777216")
#include <windows.h>
#include <bits/stdc++.h>
#define pause system("pause")
#define ll long long
#define CHUNK_SIZE 131072
using namespace std;
using namespace filesystem;
queue<pair<string,string>> WRITE_QUEUE;
mutex mtx;
atomic<int> threads;
vector<thread> ThreadPool;

DWORD GetThisProcessID()
{
    return GetCurrentThreadId();
}

void CreateDirectory(string path)
{
    auto p = path.c_str();
    CreateDirectoryA(p,NULL);
}

string getcwd()
{
    char dira[100];
    memset(dira,' ',100);
    GetCurrentDirectoryA(100,dira);
    LPCSTR a = "";
    bool b = true;
    for(int i = sizeof(dira) - 1; i >= 0; i--)
    {
        if(dira[i] != ' '){ b = false; }
        if(b)continue;
        a += dira[i];
    }
    string dir = dira;
    return dir;
}

void chdir(string dir)
{
    SetCurrentDirectoryA(dir.c_str());
}


string GetFileDirectory(string file)
{
    string aux = "";
    bool f = false;
    for(int i = file.size(); i >= 0;i--)
    {
        if(file[i] == '\\' || file[i] == '/')f = true;
        if(f)
        {
            aux = file[i] + aux;
        }
    }
    return aux;
}

string GetFileName(string rute)
{
    int  i = rute.size() - 1;
    string s = "";
    while(rute[i] != '\\' && rute[i] != '/')
    {
        s = rute[i] + s;
        i--;
    }
    return s;
}

string GetLastDirectory(string rute,bool file = false)
{
    if(file)
    {
        rute = GetFileDirectory(rute);
    }
    int n = rute.size();
    if(rute.size() <= 2)return "";
    if(rute[n - 1] == '\\' || rute[n - 1] == '/')
    {
        if(rute[n - 2] == ':')return rute;
        rute.pop_back();
    }
    rute = GetFileName(rute);
    return rute;
}

size_t GetFileSize(string rute)
{
    path file1(rute);
    size_t FileZ = file_size(file1);
    return FileZ;
}

void CPfile(string file,string fileto)
{
    threads++;
    FILE* f = fopen(file.c_str(),"rb");
    FILE* ft = fopen(fileto.c_str(),"wb");
    size_t
        Chunks,
        ResChunks;
    try
    {
        auto size1 = GetFileSize(file);
        Chunks = size1 / CHUNK_SIZE;
        ResChunks = size1 % CHUNK_SIZE;
    }
    catch(exception a)
    {
        cerr << file << " no is file  " << a.what() << endl;
        return;
    }

    while(Chunks != 0)
    {
        char buff[CHUNK_SIZE];
        memset(buff,0,CHUNK_SIZE);
        fread(buff,sizeof(buff),1,f);
        fwrite(buff,sizeof(buff),1,ft);
        Chunks--;
    }
    char buff[ResChunks];
    memset(buff,0,ResChunks);
    fread(buff,sizeof(buff),1,f);
    fwrite(buff,sizeof(buff),1,ft);
    fclose(f);
    fclose(ft);
    mtx.lock();
    cout << file << "  --->  " << fileto << "   writer: " << GetThisProcessID() << endl;
    threads--;
    mtx.unlock();
}

void __fastcall Copy(string A,string B)
{
    try
    {
        chdir(A);
    }
    catch(exception a)
    {
        cerr << "Exeption chdir: " << a.what() << endl;
        Sleep(2000);
    }
    try
    {
        directory_iterator ITER(A);
        for(auto& i : ITER)
        {
            string aux_dir = i.path().string();
            if(i.is_directory())
            {
                try
                {
                    if(GetFileName(aux_dir) == "$RECYCLE.BIN")
                        continue;
                    A = aux_dir;
                    chdir(B);
                    CreateDirectory(GetLastDirectory(aux_dir));
                    string
                        AX = A,
                        BX = B + '/' + GetLastDirectory(aux_dir);
                    thread(Copy,AX,BX).join();
                }
                catch(exception& a)
                {
                    cerr << "Error creating directory " << aux_dir << endl;
                    cerr << a.what() << endl;
                }
            }
            else
            {
                A = aux_dir;
                string
                    AX = A,
                    BX = B + '\\' + GetFileName(aux_dir);
                WRITE_QUEUE.push({AX,BX});
            }
        }
    }
    catch(filesystem_error a)
    {
        cerr << "Exception iterator: " << a.what() << endl;
        Sleep(2000);
    }
}

HANDLE CreateFile(string name,int mode,int share_mode,int CreateConfiguration,int Atributes)
{
    auto x = CreateFileA(
        name.c_str(),
        mode,
        share_mode,
        NULL,
        CreateConfiguration,
        Atributes,
        NULL
    );
    return x;
}
void c(string a,string b)
{
    cout << "2 strings\n";
}

int ID;
void th()
{
    ID = GetThisProcessID();
    while(true)
    {
        Sleep(100);
        Beep(1100,100);
    }
}

int main()
{
    
}
