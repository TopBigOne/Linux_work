#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

void test();

void test() {
    // TCP Socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {
            .sin_family = AF_INET,
            .sin_port = htons(8080), //监听8080 端口
            .sin_addr.s_addr = INADDR_ANY// 接受任意ip连接
    };

    bind(sock_fd, (const struct sockaddr *) &addr, sizeof addr);
    listen(sock_fd, 5);// 允许5个连接排队
    puts("serer start listen.....");
    //  这个地方有阻塞，直到有客户端连接
    int client_fd = accept(sock_fd, NULL, NULL);

    puts("Client Connected.");
    char buf[100];
    ssize_t n = recv(client_fd, buf, sizeof(buf), 0);
    printf("Receiveed : %.*s \n", (int) n, buf);
}

int main(void) {
    test();
    return 0;
}
