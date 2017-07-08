# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akalmyko <akalmyko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/08 12:07:14 by akalmyko          #+#    #+#              #
#    Updated: 2017/07/08 12:35:53 by akalmyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONE: all clean fclean re

NAME = ft_retro
CPPFILES = main.cpp
FLAGS = -Wall -Wextra -Werror
COMPILER = clang++
RMU = /bin/rm -f
# INC = -I /nfs/2016/a/akalmyko/goinfre/brew/opt/ncurses/lib -I /nfs/2016/a/akalmyko/goinfre/brew/opt/ncurses/include

all: $(NAME)

$(NAME):
	@$(COMPILER) $(FLAGS) $(CPPFILES) -o $(NAME) -lncurses

clean:
	@echo 'nothing to clean'

fclean:
	@$(RMU) $(NAME)

re: fclean all
