# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/13 18:35:56 by akorzhak          #+#    #+#              #
#    Updated: 2018/01/13 18:35:58 by akorzhak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

C = gcc

CFLAG = -Wall -Wextra -Werror

LINKS = -lmlx -framework OpenGL -framework AppKit

INC = -I ./includes -I ./libft -I /usr/local/include

LIBDIR = libft

LIBFT = $(LIBDIR)/libft.a

LIBMLX = $(MLXDIR)/libmlx.a

LIBS = -L /usr/local/lib/ -lmlx -L ./libft -lft

SRCDIR = src

SRC = main.c init.c messages.c draw_util.c key_hooks.c mouse_hooks.c\
		description_in_window.c basic_fractals.c additionary_fractals.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean

%.o: $(SRCDIR)/%.c
	@$(C) $(CFLAG) -c $< $(INC)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBDIR)
	@$(C) $(CFLAG) -o $(NAME) $(OBJ) $(LIBS) $(LINKS)
	@echo fractol compilation is \done
	@echo
	@echo To run fractol: ./fractol [mandelbrot/julia/burningship/buffalo/tricorn/drop]
clean:
	@make clean -C $(LIBDIR)
	@/bin/rm -f $(OBJ) *~
	@echo object files have been cleaned

fclean: clean
	@make fclean -C $(LIBDIR)
	@/bin/rm -f $(NAME)
	@echo fractol has been removed

re: fclean all
