# Destrinchando Ethernet
 
## Data Packet
- É um pacote de dados que representa qualquer conjunto único de dados binários enviados através de um link de rede
- Pacotes de dados no nível Ethernet são conhecidos como Ethernet Frame
 
## Ethernet Frame
- É um conjunto altamente estruturado de informações apresentadas em uma ordem específica.
- O Ethernet Frame é dividido em:
   - Preamble - 8 bytes
       - Funcionam parcialmente como um buffer entre os frames e também é utilizado para sincronizar os relógios internos que as interfaces de rede utilizam para regular a velocidade em que enviam dados.
   - SFD (Start Frame Delimiter) - 1 bytes
       - Byte que representa o fim do Preamble
   - Endereço de destino - 6 bytes
       - Endereço MAC da máquina destino
   - Endereço fonte - 6 bytes
       - Endereço MAC da máquina fonte
   - EtherType - 2 bytes
       - Usado para descrever o conteúdo do quadro
   - Cabeçalho VLAN - 4 bytes
       - Informar que o próprio quadro se chama, se o mesmo estiver presente o EtherType vem logo em seguida
       - Utilizado para segregar diferentes formas de tráfego
   - Payload - 0/1500 bytes
       - É a carga real de dados que está sendo transportada, tudo que não é um cabeçalho.
       - Contém todos os dados das camadas mais altas, como IP, transporte e aplicação
   - FCS - 4 bytes
       - Representa um valor da soma para de todo o quadro. É um valor de verificação. Realiza uma verificação de redundância cíclica (CRC) do quadro.
       - CRC: Conceito para integridade de dados
           - Transformação matemática que usa divisão de polinômios para criar um número que representa um conjunto maior de dados. Informa se os dados foram corrompidos durante a transmissão (Integridade de dados)
  
 

