#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

bool check()
{
    FILE *F = fopen("D:/loaded/key.k", "r");
    bool B = 0;
    if (F != NULL)
        B = 1, fclose(F);
    return B;
}

int main(int argc, char *argv[])
{
    bool Check = check();
    if (!Check)
    {
        cout << "Creating new key at: D:/loaded/key.k\n";
        CreateDirectoryA("D:/loaded/", NULL);
        SetCurrentDirectoryA("D:/loaded/");
        CloseHandle(CreateFileA("key.k", FILE_ALL_ACCESS, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));
    }
    HINSTANCE hand = NULL, error = ShellExecuteA(NULL, NULL, "E:/28gb.vhdx", NULL, NULL, SW_NORMAL);
    hand = ShellExecuteA(NULL, NULL, "E:/128gb.vhdx", NULL, NULL, SW_NORMAL);
    while (hand == error)
    {
        cout << "Error 0x000001\n";
        Sleep(1000);
        hand = ShellExecuteA(NULL, NULL, "E:/128gb.vhdx", NULL, NULL, SW_NORMAL);
    }
    cout << "MD_OK\nDisk loaded...\n";
    Sleep(1000);
    system("pause");
    if (Check)
        return 0;
    cout << "saving in registery\n";
    try
    {
        HKEY *key;
        LPCTSTR ruta = TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run\\");
        long status = RegOpenKey(HKEY_LOCAL_MACHINE, ruta, key);
        if (status != 0)
        {
            cout << "No se puede abrir la clave" << endl;
        }
        else
        {
            cout << "Nombre de la subclave: ";
            string subclave;
            getline(cin, subclave);
            cout << "Valor de la subclave: ";
            string valor;
            getline(cin, valor);
            LPCTSTR _subclave = TEXT(subclave.c_str());
            LPCTSTR _valor = TEXT(valor.c_str());
            long crear = RegSetValueEx(*key, _subclave, 0, REG_SZ, (LPBYTE)_valor, strlen(_valor) * sizeof(char));
            if (crear != 0)
            {
                cout << "Ha ocurrido un error al crear la subclave" << endl;
            }
            else
            {
                cout << "Subclave creada correctamente" << endl;
            }
        }

        RegCloseKey(*key);

        system("PAUSE");
    }
    catch (const std::exception &e)
    {
        cout << e.what() << "\n";
        Sleep(5000);
    }
    return 0;
}