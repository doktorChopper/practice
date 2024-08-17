#include "../include/tcp_server.h"
#include <iostream>

tcp_server server;

int main (int argc, char *argv[]) {
  
  if(server.setup(atoi(argv[1])) == 0) {
    while(1) {
      server.accepted();
      std::cout << "Accepted" << std::endl;
    }

  } else 
    std::cerr << "tcp_server: setup error" << std::endl;

  return 0;
}
