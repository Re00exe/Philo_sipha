#Color:

RED		= \033[0;31m
DEFAULT	= \033[0;39m
PINK	= \033[1;35m
BLUE	= \033[1;34m

#Make_file

SRC_DIR		= code
OBJ_DIR		= obj
BIN			= $(BIN_DIR)/$(NAME)
BIN_DIR		= bin
NAME		= philo
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror 
RM			= rm -rf
PRINTF 		= printf

SRC = main.c ft_file.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


all : $(NAME)

$(NAME) : creat_dir $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@$(PRINTF) "\r%100s\r$(BLUE)$(NAME) is up to date!$(DEFAULT)\n"
		@mv $(NAME) $(BIN_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(PRINTF) "\rCompiling $(BLUE)$<$(DEFAULT)..."

bonus : all

creat_dir :
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)

clean :
	@$(PRINTF) "$(PINK)Cleaning $(NAME) ... $(DEFAULT)\n"
	@$(RM) -r $(OBJ_DIR)
	@$(PRINTF) "$(RED) Objects_files removed successfully. $(DEFAULT)\n"

fclean: clean
	@$(RM) -r $(BIN_DIR)
	@$(PRINTF) "$(RED) $(NAME) removed successfully. $(DEFAULT)\n"
	
re : fclean 
	@make all