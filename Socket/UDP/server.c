#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* memset() */
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> /* close() */

#define localhost "127.0.0.1"
#define PORT 8080

int main() {
  int sd, rc, tam_Cli, n;
  char buffer[100];
  char messageFromServer[100];
  struct sockaddr_in endServ;
  struct sockaddr_in endCli;

  /* Criacao do socket UDP */
  sd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sd < 0) {
    printf("Ocorreu uma falha na hora de criar o servidor\n");
    exit(1);
  } else {
    printf("Servidor criado com sucesso\n");
  }

  /* Criacao do socket UDP */
  endServ.sin_family = AF_INET;
  endServ.sin_addr.s_addr = inet_addr(localhost);
  endServ.sin_port = htons(PORT);

  /* Fazendo um bind na porta local do servidor */
  rc = bind(sd, (const struct sockaddr *)&endServ, sizeof(endServ));
  if (rc < 0) {
    printf("Conexão com o Cliente falhou\n");
    exit(1);
  }

  /* Recebe a mensagem  */
  memset(buffer, 0x0, 100);
  tam_Cli = sizeof(endCli);
  printf("Aguardando resposta do Cliente\n");
  n = recvfrom(sd, buffer, 100, 0, (struct sockaddr *)&endCli, &tam_Cli);
  printf("Resposta recebida do Cliente : %s\n", buffer);

  /* Envia a mensagem  */
  printf("Digite a mensagem para enviar ao Cliente: ");
  scanf("%[^\n]", messageFromServer);
  sendto(sd, messageFromServer, strlen(messageFromServer), 0,
         (const struct sockaddr *)&endCli, tam_Cli);
  printf("Socket encerrado\n");
  return 0;
}
