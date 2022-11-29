# math.dll Content
## Mod Exponentiation
###   name: `bpow`
###   prototype: `long long bpow(long long a,long long exp,long long mod)`

## Mod Sum
###   name: `modsum`
###  prototype: `long long modsum(long long a,long long b,long long mod)`


## Mod Rest
###   name: `modrest`
###   prototype: `long long modrest(long long a,long long b,long long mod)`


## Mod Multiplication
###   name: `modmult`
###   prototype: `long long modmult(long long a,long long b,long long mod)`

## Mod Division
###   name: `moddiv`
###   prototype: `long long moddiv(long long a,long long b,long long mod)`
###   note: this function use b*bpow(a,mod-2)

## How Charge DLL
### use: `HINSTANCE LibDLL = LoadLibraryA("math.h")`

## How use funtions
### use: `typedef double(WINAPI *op)(long long a,long long b,long long mod);`
### then `op modsum;`
###     `modsum = (op)GetProcAddress(LibDLL,"modsum");`
### use  `cout << modsum(8,14,10) << endl;`
# example: 

- int main()
- {
-     HINSTANCE LibDLL = LoadLibraryA("math.dll");
-     typedef ll (WINAPI* op)(ll a,ll b,ll mod);
-     op suma;
-     suma = (op)GetProcAddress(LibDLL, "modsum");
-     cout << suma(8,18,10) << endl;
- }