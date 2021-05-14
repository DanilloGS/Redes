#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define localhost "127.0.0.1"
#define PORT 8080

int main() {
  int sd;
  struct sockaddr_in ladoServ;
  char buffer[100];

  // Configurando Socket
  ladoServ.sin_family = AF_INET;
  ladoServ.sin_port = htons(PORT);
  ladoServ.sin_addr.s_addr = inet_addr(localhost);

  /* Cria socket */
  sd = socket(AF_INET, SOCK_STREAM, 0);
  if (sd < 0) {
    printf("Criação do socket falhou!\n");
    exit(1);
  }

  /* Conecta socket ao servidor */
  if (connect(sd, (struct sockaddr*)&ladoServ, sizeof(ladoServ)) < 0) {
    printf("Tentativa de conexão falhou!\n");
    exit(1);
  }

  // Envia o buffer para o servidor
  while (1) {
    memset(buffer, 0x0, 100);  // Limpando Buffer
    printf("> ");
    fgets(buffer, 100, stdin);
    send(sd, &buffer, strlen(buffer), 0);
    if (strncmp(buffer, "FIM", 3) == 0) break;
    recv(sd, buffer, 100, 0);  // Recebe a resposta do servidor
    printf("Server: %s\n", buffer);
  }
  printf("------- Encerrando conexão com o servidor -----\n");
  return 0;
}