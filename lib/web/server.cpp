#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 3001
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0'; // 将接收到的数据变成字符串
        printf("接收到的按钮: %s\n", buffer); // 输出按钮名称
    }

    close(client_socket);
    printf("客户端已断开连接。\n");
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;

    // 创建套接字
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("套接字创建失败");
        exit(1);
    }

    // 配置服务器地址和端口
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // 绑定套接字
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("绑定失败");
        exit(1);
    }

    // 开始监听
    if (listen(server_socket, 5) < 0) {
        perror("监听失败");
        exit(1);
    }

    printf("服务器正在监听端口 %d...\n", PORT);

    while (1) {
        addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);
        if (client_socket < 0) {
            perror("客户端连接失败");
            continue;
        }

        printf("客户端已连接。\n");
        handle_client(client_socket);
    }

    close(server_socket);
    return 0;
}
