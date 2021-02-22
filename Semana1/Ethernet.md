# Ethernet e Endereços MAC
- O protocolo mais usado para enviar dados em links individuais é o Ethernet
- Ethernet e a camada de enlace de dados (Segunda camada) são um meio para que os softwares em níveis mais altos da pilha (Camada) enviem e recebam dados
- O propósito dessa camada é eliminar a necessidade de que outras camadas se encarreguem da camada física e de qual hardware está em uso.
- Dessa forma, as camadas mais superiores podem trabalhar de forma independente.
## Ethernet
- O protocolo surgiu com o objetivo de detectar colisões utilizando a técnica CSMA/CD.
   - CSMA/CD: Usado para determinar quando os canais de comunicação estão livres e quando o aparelho pode transmitir os dados.
   - Se detectar que ambos os computadores estão enviando dados ao mesmo tempo, o protocolo envia um sinal para interrupção dos dados. Isso evita que ocorram colisões.
 
## Endereço MAC
 
- É um identificador global conectado a uma interface de rede individual.
- É representado por Hexadecimais dividido 6 Octetos (Número que representa 8 bits)
```
   A3-1C-BE-3D-1A-C4
```
- Os 3 primeiros Octetos são identificadores do hardware do PC (Placa de rede) os fabricantes podem repetir esses endereços.
- Os 3 últimos dígitos devem ser diferentes garantindo que todos os endereços MAC gerados sejam diferentes.
 
- O MAC é utilizado pelo Ethernet para garantir que os dados mandados tenham o endereço da máquina transmissora e receptora.
 

