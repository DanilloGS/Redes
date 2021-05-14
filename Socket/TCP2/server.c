#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define localhost "127.0.0.1"
#define PORT 8080
#define QLEN 5

int atende_cliente(int descritor, struct sockaddr_in endCli) {
  char buffer[100];
  int n;
  while (1) {
    char returnFromServer[100] =
        "O sevidor recebeu sua resposta cliente, 127.0.0.1:";
    char port[12] = "";
    memset(&buffer, 0x0, sizeof(buffer));
    n = recv(descritor, &buffer, sizeof(buffer), 0);
    if (strncmp(buffer, "FIM", 3) == 0) break;
    printf("[%s:%u] => %s\n", inet_ntoa(endCli.sin_addr),
           ntohs(endCli.sin_port), buffer);
    sprintf(port, "%u", ntohs(endCli.sin_port));
    strcat(returnFromServer, port);
    send(descritor, returnFromServer, strlen(returnFromServer), 0);
    bzero(buffer, sizeof(buffer));
  }
  printf("Encerrando conexao com %s:%u ...\n", inet_ntoa(endCli.sin_addr),
         ntohs(endCli.sin_port));
  return 0;
}

int main() {
  int sd, rc, alen, novo_sd;
  struct sockaddr_in endServ; /* endereco do servidor   */
  struct sockaddr_in endCli;  /* endereco do cliente    */

  // Configurando socket
  endServ.sin_family = AF_INET;
  endServ.sin_port = htons(PORT);
  endServ.sin_addr.s_addr = inet_addr(localhost);

  /* Cria socket */
  sd = socket(AF_INET, SOCK_STREAM, 0);
  if (sd < 0) {
    printf("Falha ao criar socket!\n");
    exit(1);
  }

  /* liga socket a porta e ip */
  rc = bind(sd, (struct sockaddr*)&endServ, sizeof(endServ));
  if (rc < 0) {
    printf("Ligacao Falhou!\n");
    exit(1);
  }

  // Ouve os clientes
  if (listen(sd, QLEN) < 0) {
    printf("Falhou ouvindo porta!\n");
    exit(1);
  }

  /* Aceita conexoes */
  printf("Servidor ligado no endereço %s:%d\n", localhost, PORT);
  alen = sizeof(endCli);
  while (1) {
    // Conectando com socket cliente
    novo_sd = accept(sd, (struct sockaddr*)&endCli, &alen);
    if (novo_sd < 0) {
      printf("-> Falha na conexão\n");
      exit(1);
    }
    printf("Cliente %s: %u conectado.\n", inet_ntoa(endCli.sin_addr),
           ntohs(endCli.sin_port));
    if (fork() == 0) {
      // Lidando com os dados do cliente
      close(sd);
      atende_cliente(novo_sd, endCli);
    }
  }

  return 0;
}
