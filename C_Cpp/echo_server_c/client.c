#define _POSIX_C_SOURCE 200809L
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("sock() failed");
    return 1;
  }

  struct sockaddr_in sin;
  memset(&sin, 0, sizeof(sin));
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = inet_addr("127.0.0.1");
  sin.sin_port = htons(8080);

  if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
    perror("connection failed");
    return 1;
  }

  // char *data_addr = "Hello from Client!";
  // int data_len = strnlen(data_addr, 50);
  // int sent_bytes = send(sock, data_addr, data_len, 0);

  // if (sent_bytes < 0) {
  //   perror("send failed");
  // }

  while (1) {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) { // connection is closed
      return 1;
    } else if (read_bytes < 0) { // error
      perror("recv failed");
      break;
    }
    printf("%s", buffer);
    fgets(buffer, sizeof(buffer), stdin);
    send(sock, buffer, sizeof(buffer), 0);
  }

  close(sock);

  return 0;
}
