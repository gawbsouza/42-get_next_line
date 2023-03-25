# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 08:25:35 by gasouza           #+#    #+#              #
#    Updated: 2023/03/25 10:56:59 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libgnl.a
NAME_BONUS	=	libgnlbonus.a

SRCS_D		=	src
INCS_D		=	inc

SRCS_F		=	get_next_line.c get_next_line_utils.c
SRCS		=	$(addprefix $(SRCS_D)/, $(SRCS_F))

B_SRC_F		=	get_next_line_bonus.c get_next_line_utils_bonus.c
B_SRC		= 	$(addprefix $(SRCS_D)/, $(B_SRC_F))

OBJS		=	$(SRCS:.c=.o)
B_OBJS		=	$(B_SRC:.c=.o)

CFLAGS		=	-Wall -Werror -Wextra
COMPILER	=	gcc $(CFLAGS) -I $(INCS_D) -c
ARCHIVE		=	ar -rc
CLEANUP		=	rm -f

.PHONY: 		all
all: 			$(NAME)

.PHONY:			bonus
bonus:			$(NAME_BONUS)

$(NAME): 		$(OBJS)
				$(ARCHIVE) $@ $^

$(NAME_BONUS): 	$(B_OBJS)
				$(ARCHIVE) $@ $^

%.o: 			%.c
				$(COMPILER) $< -o $@

.PHONY: 		clean
clean:
				$(CLEANUP) $(OBJS) $(B_OBJS)

.PHONY: 		fclean
fclean: 		clean
				$(CLEANUP) $(NAME) $(NAME_BONUS)

.PHONY: 		re
re: 			fclean all
