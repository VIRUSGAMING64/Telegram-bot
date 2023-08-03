#include <bits/stdc++.h>
#include <Windows.h>
#include <winuser.h>
using namespace std;
/*
mira F te voy a poner comentarios para que sepas
super como es todo XD 
*/
LRESULT CALLBACK MouseCall(int code, WPARAM par, LPARAM ppar) // esta funcion pide el codigo de error el parametro y el puntero a eso
{
    POINT pos;          // esto es un struct
    GetCursorPos(&pos); // obvio lo que hace
    cout << ((par == 512) ? "MOUSE MOVED: " : "click at: ") << "  " << pos.x << " " << pos.y << " " << endl;
    return CallNextHookEx(NULL, code, par, ppar); // esto le manda el evento al proccimo intermediario
}

int main()
{
    HHOOK mousehoock = SetWindowsHookEx(WH_MOUSE_LL, MouseCall, NULL, 0);
    // aqui declaramos un hook y decimos que para los eventos del mause vamos a llamar a MouseCall  NULL es para decirle que no es para una ventana en especifico
    //  y 0 es el ID del hilo (porque pusimos NULL)
    //  la funcion lo que pide es el evento la funcion que vas a llamar la ventana que vaz a recoger los eventos y el hilo de esa ventana
    //  si ponemos NULL el coge de todo el mundo XD
    if (mousehoock == NULL)
    {
        cerr << "No se instalo...\n";
        return 1;
    }
    MSG message;                                 // esto es un mensage que manda el SO en general
    while (GetMessage(&message, NULL, 0, 0) > 0) // lo recogemos
    {
        TranslateMessage(&message); // mandamos el mensage a nuestra funcion
        DispatchMessage(&message);  // le enviamos el msg a la ventana que le corresponde
    }
    UnhookWindowsHookEx(mousehoock); // desintalamos el hoock (dejamos de ser intermediario)
}

// esto mismo se puede hacer para el teclado XD