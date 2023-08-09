#
#
CC			= 	cc -g
CFLAGS		= 	 -Wall -Wextra -Werror #-fsanitize=address
RM			= 	/bin/rm -f
NAME		= 	pipex
INCLUDES	= 	-I include/

#COLORS                                                                         
GREEN = \033[1;32m
RED = \033[1;31m
ORANGE = \033[38;5;208m
DEFAULT = \033[0m
YELLOW = \033[1;33m

SRCS = ./sources/pipex_main.c \
		./sources/utils.c \
		./sources/children.c \
		./sources/errors.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@echo
	@make -s -C ./libft/
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
	@echo "$(GREEN)Have fun... $(YELLOW)$(NAME) is done!$(DEFAULT)"

clean:
	@make clean -s -C ./libft/
	@$(RM) $(OBJS)
	@echo "\$(RED)Object Files are gone$(DEFAULT)"

fclean: clean
	@make fclean -s -C ./libft/
	@$(RM) $(NAME)
	@echo "$(RED)Pipex executable no longer existes$(DEFAULT)"

re: fclean all

run: re
	$(MAKE) all
	clear
	./$(NAME) infile cat cat outfile

watch:
	@printf "Watching files..\n"
	@while true; do $(MAKE) -q --no-print-directory || $(MAKE) --no-print-directory; sleep 2; done;

.PHONY: all re clean fclean