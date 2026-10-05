# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/21 03:15:10 by ktiew             #+#    #+#              #
#    Updated: 2025/07/01 11:14:51 by hho-jia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS 		=	./ft_printf.c		./ft_printf_utils.c \

OBJS		=	$(SRCS:.c=.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

AR			=	ar
AFLAGS		=	rcs

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		:	$(OBJS)
				$(AR) $(AFLAGS) $(NAME) $(OBJS)

all			:	${NAME}

bonus		:	all

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all bonus clean fclean re
