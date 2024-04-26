#include <iostream>
#include <fstream>

#include <sys/epoll.h>
#include <sys/socket.h>

#include <netinet/in.h> //sockaddr_in

#include <fcntl.h>
#include <unistd.h> //close

#include <cstring>


int main(){
    int server_socket,client_socket;
    int opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int MAX_EVENTS = 10;
    int MAX_SIZE = 1024;

    char* buffer = new char[MAX_SIZE]; //记得delete

    if (server_socket = socket(AF_INET, SOCK_STREAM,0) == 0){
        perror("服务器套接字错误...");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("设置套接字");
        exit(EXIT_FAILURE);
    }

    //定义地址信息
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("绑定失败");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        perror("监听失败");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    int epfd = epoll_create1(0);
    struct epoll_event ev, events[MAX_EVENTS];
    ev.events = EPOLLIN;
    ev.data.fd = server_socket;

    if (epoll_ctl(epfd, EPOLL_CTL_ADD, server_socket, &ev) == -1) {
        perror("事件未注册:server");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    while (true){
        int ev_num = epoll_wait(epfd, events, MAX_EVENTS, -1);

        for (int n = 0; n < ev_num; ++n) {
            if (events[n].data.fd == server_socket) {
                //接收
                client_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen);
                if (client_socket < 0) {
                    perror("接受错误");
                    continue;
                }

                // 设置客户端文件属性
                int flags = fcntl(client_socket, F_GETFL, 0);
                fcntl(client_socket, F_SETFL, flags | O_NONBLOCK);

                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = client_socket;
                epoll_ctl(epfd, EPOLL_CTL_ADD, client_socket, &ev);
            } else {
                //处理文件
                int count = read(events[n].data.fd, buffer, MAX_SIZE);
                if (count == -1) {
                    perror("读取错误");
                    close(events[n].data.fd);
                } else if (count == 0) {
                    close(events[n].data.fd);
                } else {
                    std::string filename(buffer, count);
                    std::ifstream file(filename, std::ifstream::binary);

                    if (!file.is_open()) {
                        const char* errMsg = "not file";
                        send(events[n].data.fd, errMsg, std::strlen(errMsg), 0);
                    } else {
                        while (file.read(buffer, MAX_SIZE) || (count = file.gcount()) > 0) {
                            send(events[n].data.fd, buffer, count, 0);
                        }
                        file.close();
                    }
                    close(events[n].data.fd);
                }
            }
        }

    }


    delete[] buffer;
    return 0;
}



