#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <netinet/in.h>
#include <string>
#include <stdbool.h>


class tcp_client {
  private:
  
  int sock_;
  int port_;
  std::string addr_;
  struct sockaddr_in server_;

  public:

  tcp_client();
  bool setup(std::string, int);

  bool Send(std::string);

  std::string receive(int size = 4096);

};

#endif // _CLIENT_H_
