#include "unp.h"
#include <time.h>

int main(int argc, char const *argv[])
{
    int listenfd, connfd;
    socklen_t len;
    char buff[MAXLINE];
    time_t ticks;
    struct sockaddr_storage cliaddr;

    if (argc != 2)
        err_quit("usage: daytimetcpsrv1 <service or port#>");

    listenfd = Tcp_listen(NULL, argv[1], NULL);

    while (1) {
        len = sizeof(cliaddr);
        connfd = Accept(listenfd, (SA *) &cliaddr, &len);
        printf("connection from %s\n", Sock_ntop((SA *) &cliaddr, len));

        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        Write(connfd, buff, strlen(buff));

        Close(connfd);
    }
    return 0;
}
