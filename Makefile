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

.PHONY: all clean fclean re

NAME = ft_retro
CPPFILES = main.cpp Entity.cpp Star.cpp
FLAGS = -Wall -Wextra -Werror
COMPILER = clang++
RMU = /bin/rm -f

all: $(NAME)

$(NAME):
	@$(COMPILER) $(FLAGS) $(CPPFILES) -o $(NAME) -lncurses

clean:
	@echo 'nothing to clean'

fclean:
	@$(RMU) $(NAME)

re: fclean all
