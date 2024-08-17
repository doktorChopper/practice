#include "../include/tcp_client.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <unistd.h>


tcp_client client;

int main (int argc, char *argv[]) {
  
  client.setup(argv[1], atoi(argv[2]));

  while(1) {
    client.Send(argv[3]);

    std::string rec = client.receive();
    if(rec != "") 
      std::cout << rec << std::endl;
    sleep(1);
  }

  return 0;
}
