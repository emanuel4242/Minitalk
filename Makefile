# Nome dos executáveis
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include
RM = rm -f

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj

# Arquivos fonte e objetos
CLIENT_SRC = $(SRC_DIR)/client.c
SERVER_SRC = $(SRC_DIR)/server.c
CLIENT_OBJ = $(OBJ_DIR)/client.o
SERVER_OBJ = $(OBJ_DIR)/server.o

# Nomes dos executáveis
CLIENT = client
SERVER = server

# Regras padrão
all: $(CLIENT) $(SERVER)

# Compila o cliente
$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compila o servidor
$(SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compila os arquivos objeto para o cliente
$(OBJ_DIR)/client.o: $(SRC_DIR)/client.c $(INCLUDE_DIR)/minitalk.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Compila os arquivos objeto para o servidor
$(OBJ_DIR)/server.o: $(SRC_DIR)/server.c $(INCLUDE_DIR)/minitalk.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Limpa os arquivos compilados
clean:
	$(RM) -r $(OBJ_DIR)

# Remove os executáveis
fclean: clean
	$(RM) $(CLIENT) $(SERVER)

# Recompila tudo
re: fclean all

.PHONY: all clean fclean re
