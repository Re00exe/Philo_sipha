#Color:

RED		= \033[0;31m
DEFAULT	= \033[0;39m
PINK	= \033[1;35m
BLUE	= \033[1;34m

#Make_file

SRC_DIR		= code
BIN			= $(BIN_DIR)/$(NAME)
BIN_DIR		= bin
NAME		= philo
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror 
RM			= rm -rf
PRINTF 		= printf

SRC = code/main.c code/ft_file.c code/threads.c code/utils.c code/utils1.c

all : $(BIN)

$(BIN) : $(SRC)
			@mkdir -p $(BIN_DIR)
			@$(CC) $(CFLAGS) $(SRC)  -o $(NAME) 
			@$(PRINTF) "\r%100s\r$(BLUE)$(NAME) is up to date!$(DEFAULT)\n"
			@mv $(NAME) $(BIN_DIR)

clean :
	@$(PRINTF) "$(PINK)Cleaning $(NAME) ... $(DEFAULT)\n"
	@$(PRINTF) "$(RED) Objects_files removed successfully. $(DEFAULT)\n"

fclean: clean
	@$(RM) -r $(BIN_DIR)
	@$(PRINTF) "$(RED) $(NAME) removed successfully. $(DEFAULT)\n"
	
re : fclean 
	@make all
.PHONY : all bonus clean fclean re