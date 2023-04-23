# Hi there 👋
## Repository of useful functions and scripts in C++ and Python
### 1- Updates all week 
### 2 - to use the telegram bot use the command: 
```bash
python -m pip install pyrogram
```
## Telegram Bot Example:

```python
from pyrogram import Client, filters
bot = Client("bot", API_ID, API_HASH)

async def on_message(client, message):
    message.reply("Hello, world!")

bot.run()
```
### this is a simple example of telegram bot made with python.
## My snippet main: 
```c++
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef LOCAL
#include "debug/debug.h"
#include <windows.h>
#endif
#define ll long long
using namespace std;
using namespace __gnu_pbds;

signed main()
{
}
```
### Load DLL with python:
```python
from ctypes import WinDLL
k32 = WinDLL("kernel32.dll",use_last_error=1)
k32.CreateDirectoryW("Example Directory",None)
```
### this is a example of use windows api in python now in c++ ...
```c++
#include <bits/stdc++.h>
#include <windows.h>

signed main()
{
    HINSTANCE LibDLL = LoadLibraryA("kernel32.dll");
    typedef WINBOOL(WINAPI * func)(LPCSTR name,LPSECURITY_ATTRIBUTES hand);
    func MyCreateDirectoryA = (func)GetProcAddress(LibDLL, "CreateDirectoryA");
    cout << MyCreateDirectoryA("Hello World", NULL);
} 
```

## coming soo:
####    golang,javascript,competitive programing algorithms and more...
