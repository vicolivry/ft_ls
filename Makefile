# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/15 17:31:08 by volivry      #+#   ##    ##    #+#        #
#    Updated: 2018/03/21 16:38:25 by volivry     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc
CCFLAGS = -Wall -Wextra -Werror -g
NAME = ft_ls
SRC = data_ls.c display.c free_ls.c ft_ls_r.c main.c mod_ls.c multi.c \
	  multi_utils.c parse_ls.c print_flag_a.c sort_utils_ls.c \
	  utils.c sort_ls.c
OBJECTS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CCFLAGS) -I. -o $@ -c $<

$(NAME): $(OBJECTS)
	@make -C ./libft/
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJECTS) -L libft/ -lft

clean:
	@echo "CLEANING"
	@make clean -C ./libft/
	@rm -f $(OBJECTS)

fclean: clean
	@echo "SUPER CLEANING"
	@make fclean -C ./libft/
	@rm -f $(NAME)

re: fclean all
