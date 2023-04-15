# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iragusa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 15:15:27 by iragusa           #+#    #+#              #
#    Updated: 2022/10/28 17:09:02 by iragusa          ###   ########.fr        #
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

NAME = libft.a

CC = gcc

AR = ar -rcs

FLAG = -Werror -Wall -Wextra -g

SRC = ft_atoi.c ft_split.c ft_isdigit.c ft_lstadd_front.c \
	ft_lstnew.c ft_lstsize.c ft_lstadd_back.c\
	ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
	ft_matfree.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $(FLAG) -I. $< -o $@

clean: 
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re
