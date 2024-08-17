#include "../include/tcp_server.h"
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <pthread.h>
#include <sys/socket.h>
#include <unistd.h>


char tcp_server::msg[MAXPACKETSIZE];


int tcp_server::get_port() const {
  return port_;
}


int tcp_server::setup(int port) {

  sockfd_ = socket(AF_INET, SOCK_STREAM, 0);
  memset(&server_, 0, sizeof(server_));

  port_ = port;
  server_.sin_family = AF_INET;
  server_.sin_port = htons(port_);
  server_.sin_addr.s_addr = htonl(INADDR_ANY);

  if(bind(sockfd_,  (struct sockaddr *) &server_, sizeof(server_)) < 0) {
    std::cerr << "error bind" << std::endl;
    return -1;
  }

  if(listen(sockfd_, 3) < 0) {
    std::cerr << "error listen" << std::endl;
    return -1;
  }

  return 0;
}

void* tcp_server::task(void *arg){

  int n;

  descript_socket * ds = (descript_socket*) arg;
  pthread_detach(pthread_self());

  while(1) {
    n = recv(ds->socket, msg, MAXPACKETSIZE, 0);
    if(n != -1) {
      
    }

    usleep(600); 
  }

  return 0;
}

int tcp_server::accepted() {

  descript_socket * ds = new descript_socket;

  if((ds->socket = accept(sockfd_, nullptr, nullptr)) < 0) {
    std::cerr << "error accept" << std::endl;
    return -1;
  }

  pthread_create(&server_thread_[1], nullptr, task, (void*) ds); 

  return 0;
}

void tcp_server::closed() {
  close(sockfd_);
}
