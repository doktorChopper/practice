#include "../include/client.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

tcp_client::tcp_client() {
  sock_ = -1;
  port_ = 0;
  addr_ = "";
}

bool tcp_client::setup(std::string address, int port) {

  if(sock_ == -1) {
    sock_ = socket(AF_INET, SOCK_STREAM, 0);

    if(sock_ == -1) {
      std::cout << "could not create socket" << std::endl;
    }
  }

  server_.sin_port = htons(port_);
  server_.sin_family = AF_INET;
  server_.sin_addr.s_addr = inet_addr(address.c_str());

  if(connect(sock_, (struct sockaddr *)&server_, sizeof(server_)) < 0) {
    perror("connect failed. Error");
    return false;
  }
  return true;
}

bool tcp_client::Send(std::string msg) {
  if(sock_ != -1) {

    if(send(sock_, msg.c_str(), strlen(msg.c_str()), 0) < 0) {
      std::cout << "send failed. Error" << std::endl;
      return false;
    }

  } else 
    return false;
  return true;
}

//TODO

std::string tcp_client::receive(int size) {
  char buffer[size];
  memset(&buffer, 0, sizeof(buffer));

  std::string reply;
  if(recv(sock_, &buffer, sizeof(buffer), 0)){
    std::cout << "receive failed. Error" << std::endl;
    return nullptr;
  }
 
  buffer[size - 1] = '\0'; 
  reply = buffer; 
  return reply;
}


