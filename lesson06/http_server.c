#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <unistd.h>

int main(){
    int sock, ret, send_sock;
    struct sockaddr_in addr;
    struct sockaddr_in client;
    socklen_t length;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    ret = bind(sock,  (struct sockaddr *)&addr, sizeof(addr) );

    listen(sock, 5);
    while(1) {
        length = sizeof(client);
        send_sock = accept(sock , (struct sockaddr *)&client, &length);
        send(send_sock, "HTTP/1.0 200OK\r\n" "Content-Length:6\r\n"
"Content-Type:text/html\r\n" "\r\n" "HELLO\n", 66, 0);
        close(send_sock);
    }
    close(sock);
}
