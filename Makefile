# Variáveis
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
SRC_DIR = src/
BONUS_DIR = src/bonus/
INCLUDE_DIR = include/
OBJ_DIR = obj/
LIB_DIR = lib/

# Arquivos de origem
SRC_FILES = $(SRC_DIR)client.c $(SRC_DIR)server.c $(SRC_DIR)utils.c
BONUS_FILES = $(BONUS_DIR)client_bonus.c $(BONUS_DIR)server_bonus.c $(BONUS_DIR)utils_bonus.c
HEADER = $(INCLUDE_DIR)minitalk.h
BONUS_HEADER = $(INCLUDE_DIR)minitalk_bonus.h

# Arquivos objeto
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
BONUS_OBJ_FILES = $(BONUS_FILES:$(BONUS_DIR)%.c=$(OBJ_DIR)%.o)

# Executáveis
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

# Biblioteca estática
LIB_NAME = libminitalk.a
BONUS_LIB_NAME = libminitalk_bonus.a

# Regra padrão
all: $(CLIENT) $(SERVER) $(LIB_DIR)$(LIB_NAME)

# Regras para os executáveis principais
$(CLIENT): $(OBJ_DIR)client.o $(OBJ_DIR)utils.o $(LIB_DIR)$(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $(OBJ_DIR)client.o $(OBJ_DIR)utils.o -L$(LIB_DIR) -lminitalk

$(SERVER): $(OBJ_DIR)server.o $(OBJ_DIR)utils.o $(LIB_DIR)$(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $(OBJ_DIR)server.o $(OBJ_DIR)utils.o -L$(LIB_DIR) -lminitalk

# Regras para os executáveis bônus
bonus: $(CLIENT_BONUS) $(SERVER_BONUS) $(LIB_DIR)$(BONUS_LIB_NAME)

$(CLIENT_BONUS): $(OBJ_DIR)client_bonus.o $(OBJ_DIR)utils_bonus.o $(LIB_DIR)$(BONUS_LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $(OBJ_DIR)client_bonus.o $(OBJ_DIR)utils_bonus.o -L$(LIB_DIR) -lminitalk_bonus

$(SERVER_BONUS): $(OBJ_DIR)server_bonus.o $(OBJ_DIR)utils_bonus.o $(LIB_DIR)$(BONUS_LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $(OBJ_DIR)server_bonus.o $(OBJ_DIR)utils_bonus.o -L$(LIB_DIR) -lminitalk_bonus

# Compilação dos arquivos objeto
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(BONUS_DIR)%.c $(BONUS_HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Geração da biblioteca estática
$(LIB_DIR)$(LIB_NAME): $(OBJ_FILES)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $(OBJ_DIR)client.o $(OBJ_DIR)utils.o

$(LIB_DIR)$(BONUS_LIB_NAME): $(BONUS_OBJ_FILES)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $(OBJ_DIR)client_bonus.o $(OBJ_DIR)utils_bonus.o

# Limpeza dos arquivos objeto, biblioteca e executáveis
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS) $(LIB_DIR)$(LIB_NAME) $(LIB_DIR)$(BONUS_LIB_NAME)

# Recompila tudo
re: fclean all

.PHONY: all clean fclean re bonus
