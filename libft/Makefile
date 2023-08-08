# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariaavoletta <mariaavoletta@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 11:52:24 by htomas-d          #+#    #+#              #
#    Updated: 2023/08/02 23:17:54 by mariaavolet      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	$(wildcard *.c)

OBJS		= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.

NAME		= libft.a

all:	$(NAME)

$(NAME):	$(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re
