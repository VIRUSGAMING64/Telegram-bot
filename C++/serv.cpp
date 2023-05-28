#include <iostream>
#include <winsock2.h>

using namespace std;

class Server
{
public:
    WSADATA WSAData;
    SOCKET server, client;
    SOCKADDR_IN serverAddr, clientAddr;
    char buffer[1024];
    bool con = 0;
    Server()
    {
        FreeConsole();
        WSAStartup(MAKEWORD(2, 0), &WSAData);
        server = socket(AF_INET, SOCK_STREAM, 0);
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(5555);
        bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
        listen(server, 0);
        int clientAddrSize = sizeof(clientAddr);
        if ((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
        {
            con = 1;
        }
    }

    void Recibir()
    {
        recv(client, buffer, sizeof(buffer), 0);



        memset(buffer, 0, sizeof(buffer)); // clean buffer for new messages
    }

    void Enviar()
    {
        cout << "Escribe el mensaje a enviar: ";
        cin >> this->buffer;
        send(client, buffer, sizeof(buffer), 0);
        memset(buffer, 0, sizeof(buffer));
        cout << "Mensaje enviado!" << endl;
    }
    
    void CerrarSocket()
    {
        closesocket(client);
        cout << "Socket cerrado, cliente desconectado." << endl;
    }
};

int main()
{
    Server *Servidor = new Server();
    while (true)
    {
        Servidor->Recibir();
    }
}