#ifndef _SERVER_H_
#define _SERVER_H_

#include <pthread.h>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAXPACKETSIZE 1024

struct descript_socket {
  int socket = -1;
  std::string msg;
};

class tcp_server {
  private:
    int port_;
    int sockfd_;
    std::string addr_;
    struct sockaddr_in server_;
    pthread_t server_thread_[32];
    
    static void * task(void *argv); 
    static char msg[MAXPACKETSIZE];

  public:

    int setup(int);

    int accepted();

    int get_port() const;

    void closed();

};

#endif // _SERVER_H_
