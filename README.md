# Minitalk

Minitalk é um projeto que demonstra a comunicação entre processos (IPC) usando sinais UNIX. Ele consiste em um servidor que recebe mensagens de clientes, enviadas bit a bit através de sinais, e um cliente que envia essas mensagens.
Funcionalidades

1. Comunicação IPC: Envio e recebimento de mensagens usando sinais SIGUSR1 e SIGUSR2.
2. Servidor: Recebe mensagens de clientes e as exibe no terminal.
3. Cliente: Envia mensagens ao servidor bit a bit.
4. Parte Bônus: Confirmação de recebimento de mensagens e melhor controle de fluxo.

## Requisitos

1. Sistema operacional baseado em UNIX (Linux ou macOS).
2. Compilador GCC.

## Compilação

Para compilar o servidor e o cliente, utilize os seguintes comandos:

```sh
gcc -o server server.c
gcc -o client client.c

```
Para a parte bônus:

```sh
gcc -o server_bonus server_bonus.c
gcc -o client_bonus client_bonus.c

```
# Execução

1. Inicie o servidor:
```sh
./server

```
Ou para a versão bônus:
```sh
./server_bonus

```
O servidor exibirá seu PID. Anote este PID, pois ele será necessário para o cliente enviar mensagens.

2. Execute o cliente:

```sh
./client <server_pid> "Sua mensagem aqui"

```
Substitua <server_pid> pelo PID do servidor exibido anteriormente. E "Sua mensagem aqui" pela mensagem que deseja enviar.

Ou para a versão bônus:

``` sh

./client_bonus <server_pid> "Sua mensagem aqui"

```

## Explicação do Código
### Servidor

- server.c:
    - Configura manipuladores de sinal para SIGUSR1 e SIGUSR2.
    - Recebe bits e reconstrói caracteres, exibindo a mensagem recebida.
- server_bonus.c:
    - Adiciona confirmação de recebimento enviando SIGUSR1 ao cliente após receber cada caractere completo.

### Cliente

- client.c:
    - Converte uma mensagem em bits e envia cada bit ao servidor usando sinais SIGUSR1 e SIGUSR2.
- client_bonus.c:
    - Espera por uma confirmação do servidor (SIGUSR1) antes de enviar o próximo caractere, garantindo melhor controle de fluxo.

### Estrutura de Diretórios

minitalk/ <br>
├── client.c <br>
├── client_bonus.c <br>
├── server.c <br>
├── server_bonus.c <br>
├── README.md <br>

### Notas Adicionais

Segurança: O código lida com possíveis erros de sistema e inclui mecanismos de espera para garantir que o servidor tenha tempo para processar os sinais.
Sincronização: A espera (usleep) entre o envio dos bits pode precisar de ajustes dependendo do desempenho do sistema e do tempo de resposta do servidor.

### Licença

Este projeto é licenciado sob a MIT License.
<hr>
Este README fornece uma visão geral do projeto Minitalk, incluindo como compilar, executar e entender a implementação do servidor e do cliente, bem como a estrutura do diretório e exemplos de uso.