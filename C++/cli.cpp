#include <iostream>
#include <winsock2.h>

using namespace std;
class Client
{ 
public:
    WSADATA WSAData;
    SOCKET server;
    SOCKADDR_IN addr;
    char buffer[1024];
    Client()
    {
        cout << "Conectando al servidor..." << endl
             << endl;
        WSAStartup(MAKEWORD(2, 0), &WSAData);
        server = socket(AF_INET, SOCK_STREAM, 0);
        addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        addr.sin_family = AF_INET;
        addr.sin_port = htons(5555);
        connect(server, (SOCKADDR *)&addr, sizeof(addr));
        cout << "Conectado al Servidor!" << endl;
    }
    void Enviar()
    {
        cout << "Escribe el mensaje a enviar: ";
        cin >> this->buffer;
        send(server, buffer, sizeof(buffer), 0);
        memset(buffer, 0, sizeof(buffer));
        cout << "Mensaje enviado!" << endl;
    }
    void Recibir()
    {
        recv(server, buffer, sizeof(buffer), 0);
        cout << "El servidor dice: " << buffer << endl;
        memset(buffer, 0, sizeof(buffer));
    }
    void CerrarSocket()
    {
        closesocket(server);
        WSACleanup();
        cout << "Socket cerrado." << endl
             << endl;
    }
};

int main()
{
    Client *Cliente = new Client();
    while (true)
    {
        Cliente->Enviar();
        Cliente->Recibir();
    }
}