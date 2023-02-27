#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
using namespace filesystem;
#define env "d:/VIRUSGAMING/STUDIO/"
#define THREADS 1
#define endl "\n"


auto GetThisProcessID()
{
    return GetCurrentThreadId();
}

auto lpcstr(string s)
{
    return s.c_str();
}

void CreateDirectory(string path)
{
    auto p = path.c_str();
    if(is_directory(filesystem::path(path)))return;
    CreateDirectoryA
    (
        p,
        NULL
    );
}

auto getcwd()
{
    char dira[100];
    memset(dira,' ',100);
    GetCurrentDirectoryA
    (
        100,
        dira
    );
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

auto chdir(string dir)
{
    SetCurrentDirectoryA
    (
        dir.c_str()
    );
}


auto GetFileDirectory(string file)
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

void ForceDirectory(string rute)
{
    vector<string> dirs;
    while(rute.size() > 3)
    {
        dirs.push_back(rute);
        rute = GetFileDirectory(rute);
        rute.pop_back();
    }
    sort
    (
        dirs.begin(),
        dirs.end()
    );
    for(int i = 0;i < dirs.size();i++)
    {
        CreateDirectory(dirs[i]);
    }
}


auto GetFileName(string rute)
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

auto GetLastDirectory(string rute,bool file = false)
{
    if(file)
    {
        rute = GetFileDirectory(rute);
    }
    int n = rute.size();
    if(rute.size() <= 2)return (string)("");
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
    try
    {
        path file1(rute);
        size_t FileZ = file_size(file1);
        return FileZ;
    }
    catch(exception a)
    {
        cerr << "Error: " << a.what() << endl;
    }
    return 0;
}

struct Task
{
    Task(string FullPath,string ToFullPath)
    {
        Rute = FullPath;
        Filename = GetFileName(Rute);
        FileRute = GetFileDirectory(FullPath);
        FileToName = GetFileName(ToFullPath);
        FolderTo = GetFileDirectory(ToFullPath);
        FileTo = FolderTo + '/' + FileToName;
    }
    string
        FileToName,
        Rute,
        Filename,
        FileRute,
        FolderTo,
        FileTo;
};

auto CreateTask(string Read,string Write) -> Task
{
    Task res
    (
        Read,
        Write
    );
    return res;
}
mutex mtx;

auto Fill(Task& task,int ID = 65536,bool recopy = true)
{
    try
    {
        ForceDirectory(task.FolderTo);
    }
    catch(exception a)
    {
        cerr << a.what() << endl;
        return;
    }
    
    FILE* file = fopen(task.Rute.c_str(),"rb");
    
    if(recopy == false)
    {
        FILE* file2 = fopen(task.FileTo.c_str(),"rb");
        if(file2 != NULL)
        {
            mtx.lock();
            cout << "File Exists: " << task.FileTo.c_str() << " ID: " << ID << endl;
            mtx.unlock();
            fclose(file2);
            return;
        }
    }
    FILE* file2 = fopen(task.FileTo.c_str(),"wb");

    mtx.lock();
    cout << task.Rute.c_str() << "  ID: " << ID << endl;
    mtx.unlock();

    int Fsize = GetFileSize(task.Rute);
    int n = Fsize / 65536;
    int i = 0;
    while(i < n)
    {
        i++;
        char buff[65536];
        fread
        (
            buff,
            sizeof(buff),
            1,
            file
        );
        fwrite
        (
            buff,
            sizeof(buff),
            1,
            file2
        );
    }
    int res = Fsize % 65536;
    char buff[res];
    fread
    (
        buff,
        sizeof(buff),
        1,
        file
    );
    fwrite
    (
        buff,
        sizeof(buff),
        1,
        file2
    );
    fclose(file);
    fclose(file2);
}

class TASK
{
    public:
    vector<Task> tlist;
    bool locked = false;
    void lock()
    {
        locked = true;
    }
    void unlock()
    {
        locked = false;
    }
    bool empty()
    {
        return tlist.empty();
    }
    void Process()
    {
        if(locked || tlist.empty()) return;
        Task actual = tlist[0];
        tlist.erase(tlist.begin());
        Fill(actual);
    }
    void GetTask(vector<pair<string,string>> tsk)
    {
        for(auto c : tsk)
        {
            tlist.push_back
            (
                CreateTask
                (
                    c.first,
                    c.second
                )
            );
        }
    }
    void GetTask(vector<Task> tsk)
    {
        for(int i = 0;i < tsk.size();i++)
        {
            tlist.push_back
            (
                tsk[i]
            );
        }
    }
};


vector<pair<string,string>> for_process;

auto dp(string in,string out)
{
    try
    {
        if(is_directory(path(in)))
        {
            SetCurrentDirectoryA(lpcstr(in));
        }
        else
        {
            string
                X1 = GetFileName(in),
                X2 = GetFileName(out);
            if(X1 != X2)
            {
                out = out + "/" + X1;
            }
            for_process.push_back
            (
                {in,out}
            );
            return;
        }
    }
    catch(exception& a)
    {
        cerr << "ACCESS ERROR: " << a.what() << endl;
        return;
    }
    try
    {
        path pth(in);
        directory_iterator act(pth);
        for(auto c : act)
        {
            dp
            (
                in + "/" +
                GetFileName
                (
                    c.path().string()
                ),
                out + "/" +
                GetFileName
                (
                    c.path().string()
                )
            );
        }
    }
    catch(exception& a)
    {
        cerr << "ACCESS ERROR: " << a.what() << endl;
        return;
    }
}

auto Work(queue<Task> q,int id)
{
    while(!q.empty())
    {
        Task t = q.front();
        q.pop();
        Fill(t,id,false);
    }
    mtx.lock();
    cout << "END THREAD: " << id << endl;
    mtx.unlock();
}

auto ManagementHandle()
{
    vector<thread> workers(THREADS);
    TASK my;
    cout << "SORTING LIST..." << endl;
    Sleep(100);
    sort(for_process.rbegin(),for_process.rend());
    my.GetTask(for_process);
    queue<Task> q,q2,q3,q4;
    unsigned long long res = 0;
    for(auto c : my.tlist)
    {
        if(res % 4 == 0)
            q.push(c);
        else if(res%4 == 1)
            q2.push(c);
        else if(res % 4 == 2)
            q3.push(c);
        else
            q4.push(c);
        res++;
    }

    my.tlist = vector<Task>();

    srand(time(0));

    int ID1 = rand() % 65536 * 16;
    int ID2 = rand() % 65536 * 16;
    int ID3 = rand() % 65536 * 16;
    int ID4 = rand() % 65536 * 16;
    thread C1(Work,q,ID1);
    thread C2(Work,q2,ID2);
    thread C3(Work,q3,ID3);
    thread C4(Work,q4,ID4);
    C1.join();
    C2.join();
    C3.join();
    C4.join();
}

auto main() -> int
{
    cout << "IN: ";
    string s; cin >> s;
    cout << endl << "OUT: ";
    string s1; cin >> s1;
    cout << endl;
    dp(s,s1);
    ManagementHandle();
    system("pause");    
}