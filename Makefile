# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/15 17:31:08 by volivry      #+#   ##    ##    #+#        #
#    Updated: 2018/03/28 17:00:54 by volivry     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
NAME = ft_ls
SRC = data_ls.c display.c free_ls.c ft_ls_r.c main.c mod_ls.c multi.c \
	  multi_utils.c multi_utils2.c parse_ls.c print_flag_a.c sort_utils_ls.c \
	  utils.c ft_ls.c recurse.c
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
