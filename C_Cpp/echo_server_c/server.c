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

  if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
    perror("bind failed");
    return 1;
  }

  if (listen(sock, 1024) < 0) {
    perror("listen failed");
    return 1;
  }

  struct sockaddr_in client_sin;
  int addr_len = sizeof(client_sin);
  int client_sock =
      accept(sock, (struct sockaddr *)&client_sin, (unsigned int *)&addr_len);

  if (client_sock < 0) {
    perror("accept failed");
    return 1;
  }

  close(sock);

  char *data_addr = "Listening for text to echo...\n";
  int data_len = strnlen(data_addr, 50);
  int sent_bytes = send(client_sock, data_addr, data_len, 0);

  if (sent_bytes < 0) {
    perror("send failed");
  }

  char buffer[4096];
  int expected_data_len = sizeof(buffer);
  while (1) {
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) { // connection is closed
      return 1;
    } else if (read_bytes < 0) { // error
      perror("recv failed");
      break;
    }
    printf("Received: %s", buffer);
    send(client_sock, buffer, read_bytes, 0);
  }

  close(client_sock);

  return 0;
}
