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
  int sd;
  char buffer[100];
  char messageFromClient[100];
  struct sockaddr_in endServ;

  /* Preenchendo as informacoes de identificacao do servidor */
  endServ.sin_family = AF_INET;
  endServ.sin_port = htons(PORT);
  endServ.sin_addr.s_addr = inet_addr(localhost);

  /* Criando um socket.*/
  sd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sd < 0) {
    printf("Conexão com o Servidor falhou\n");
    exit(1);
  }
  /* Envia a mensagem  */
  printf("Digite a mensagem para enviar ao Servidor: ");
  scanf("%[^\n]", messageFromClient);
  sendto(sd, messageFromClient, strlen(messageFromClient), 0,
         (const struct sockaddr *)&endServ, sizeof(endServ));

  /* Recebe a mensagem  */
  printf("Aguardando resposta do Servidor\n");
  int tam_Serv = sizeof(endServ);
  memset(buffer, 0x0, 100);
  recvfrom(sd, buffer, 100, 0, (struct sockaddr *)&endServ, &tam_Serv);
  printf("Resposta recebida do servidor : %s\n", buffer);
  printf("Socket encerrado\n");
  return 0;
}
