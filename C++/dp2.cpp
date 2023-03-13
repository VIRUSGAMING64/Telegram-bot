// Server side C/C++ program to demonstrate Socket
// programming
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <unistd.h>
#define PORT 8080
#include <iostream>
using namespace std;


int main(int len, char *args[])
{
    for(int i = 0; i < len; i++)
    cout << args[i] << endl;
}
