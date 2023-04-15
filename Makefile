# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iragusa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 18:37:54 by iragusa           #+#    #+#              #
#    Updated: 2023/03/12 18:52:59 by iragusa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# \ = is used to Splitting Long Lines 3.1.1

# ;\ = indicates a multiline command and keeps the instance of the terminal for
# the next command

# % = the same as * 'wildcard'
# $@ = means what is before the : in the target
# $^ = means what is after the : in the target
# $< = the first prerequisite (usually a source file)
# -I.  = adds include directory of header files.
# -f = force the removal even if the files have been already deleted.

# -c = Compile or assemble the source files, but do not link.
# cp = copy.
# The linking stage simply is not done. The ultimate output is
# in the form of an object file for each source file.
# By default, the object file name for a source file is made by replacing
# the suffix .c, .i, .s, etc., with .o. Unrecognized input files,
# not requiring compilation or assembly, are ignored.
# -s = silent
# @echo = stampa quello che viene dopo

NAME = push_swap

CC = gcc

CFLAGS = -Werror -Wall -Wextra -g

SRC = push_swap.c utils.c list.c moves.c moves_2.c radix.c index.c smallsort.c

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

R = \033[0;31m
G = \033[0;32m
Y = \033[0;33m
LB = \033[1;34m
MAG = \033[1;35m
B = \033[0;34m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "⌛${Y}compiling...⌛${NC}"
	$(MAKE) -s -C libft/
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "🎉${G}push_swap compiled!${NC}🎉"

clean: 
	@echo "🧽 ${LB}cleaning... ${NC}🧽"
	@rm -rf $(OBJ) 
	@make clean -s -C libft/
	
fclean: clean
	@echo "🚮♻️ ${G}spring cleaning, rm $(NAME)...${NC} ♻️🚮" 
	rm -rf $(NAME)

re: fclean all

.SILENT:
