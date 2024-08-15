# Nome do compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Arquivos fonte e objetos
CLIENT_SRC = client.c
SERVER_SRC = server.c
UTILS_SRC = utils.c
CLIENT_OBJ = client.o
SERVER_OBJ = server.o
UTILS_OBJ = utils.o

# Nomes dos executáveis
CLIENT = client
SERVER = server

# Regras padrão
all: $(CLIENT) $(SERVER)

# Compila o cliente
$(CLIENT): $(CLIENT_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compila o servidor
$(SERVER): $(SERVER_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compila os arquivos objeto para o cliente
client.o: client.c minitalk.h
	$(CC) $(CFLAGS) -c client.c

# Compila os arquivos objeto para o servidor
server.o: server.c minitalk.h
	$(CC) $(CFLAGS) -c server.c

# Compila os arquivos objeto para as utilidades
utils.o: utils.c minitalk.h
	$(CC) $(CFLAGS) -c utils.c

# Limpa os arquivos compilados
clean:
	$(RM) *.o

# Remove os executáveis
fclean: clean
	$(RM) $(CLIENT) $(SERVER)

# Recompila tudo
re: fclean all

.PHONY: all clean fclean re
