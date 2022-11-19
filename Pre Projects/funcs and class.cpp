#include <bits/stdc++.h>
#include <windows.h>

using namespace std;
using namespace filesystem;

struct COPY
{
    string fileA,fileB; 
};
queue<COPY> c_queue;

string GetFileName(string file)
{
    int res = file.size()-1;
    string filename="";
    while(file[res]!='\\' || file[res] == '/')
    {  
        filename = file[res] + filename;
        res--;
    }
    return filename;
}

void createDir(string dir)
{
    LPCSTR dirname = dir.c_str();
    LPSECURITY_ATTRIBUTES n;
    CreateDirectoryA(dirname,n);
}

string getcwd()
{
    auto path = current_path();
    string s = path.string();
    return s;
}


vector<filesystem::path> listdir(string path)
{   
    vector<filesystem::path> dirs;
    for (const auto & entry : directory_iterator(path))
    dirs.push_back(entry.path());
    return dirs;
}

vector<filesystem::path> listdir()
{
    vector<filesystem::path> dirs;
    string path = getcwd();
    for (const auto & entry : directory_iterator(path))
    dirs.push_back(entry.path());
    return dirs;
}



int main()
{   
    
}