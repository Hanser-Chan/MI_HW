#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <fstream>



int main(int argc, char *argv[]) {

    int MAX_EVENTS = 5;
    int MAX_SIZE = 1024;
    int sock;
    struct sockaddr_in serv_addr;
    //char buffer[MAX_SIZE] = {0};
    char* buffer = new char[MAX_SIZE];
    const char* server_ip = "127.0.0.1";
    int server_port = 8080;

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    const char* file_request = argv[1];

    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(server_port);

    
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        return -1;
    }

    //连接到服务器
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        return -1;
    }

    
    send(sock, file_request, strlen(file_request), 0);

    
    std::ofstream file_output;
    file_output.open("接收文件", std::ofstream::binary);

    if (!file_output.is_open()) {
        perror("打开文件失败");
        return -1;
    }

    
    int bytes_received;
    while ((bytes_received = read(sock, buffer, MAX_SIZE)) > 0) {
        file_output.write(buffer, bytes_received);
    }

    if (bytes_received < 0) {
        perror("读取失败");
        file_output.close();
        close(sock);
        return -1;
    }

    file_output.close();
    close(sock);
    std::cout << "成功接收文件" << std::endl;
    return 0;
}
