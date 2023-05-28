#include <windows.h>
using namespace std;

bool sys_start(string exename)
{
    HKEY key_handle;
    string start_name = exename;
    char buff[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH,buff);
    string exe_path(buff);
    exe_path += "\\"+exename;
    cout << exe_path << endl;
    LONG result = RegOpenKeyExA(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_WRITE, &key_handle);

    if (ERROR_SUCCESS == result)
    {
        result = RegSetValueEx(key_handle, start_name.c_str(),
                               0,
                               REG_SZ,
                               (unsigned char *)exe_path.c_str(),
                               exe_path.length() * sizeof(wchar_t));

        if (result != ERROR_SUCCESS)
        {
            printf("Error setting key %d\n", GetLastError());
            system("pause");
            return false;
        }
    }
    else
    {
        printf("Error opening key %d\n", GetLastError());
            system("pause");
            return 0;
    }

    RegCloseKey(key_handle);
    return 1;
}