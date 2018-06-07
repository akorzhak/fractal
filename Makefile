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

INC = -I ./includes -I ./libft -I ./minilibx_macos/include

LIBDIR = libft

MLXDIR = minilibx_macos

LIBFT = $(LIBDIR)/libft.a

LIBMLX = $(MLXDIR)/libmlx.a

LIBS = -L ./minilibx_macos -lmlx -L ./libft -lft

SRCDIR = src

SRC = main.c init.c messages.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean

%.o: $(SRCDIR)/%.c
	@$(C) $(CFLAG) -c $< $(INC)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBDIR)
	@cp $(LIBFT) $(NAME)
	@make -C $(MLXDIR)
	@cp $(LIBMLX) $(NAME)
	@$(C) $(CFLAG) -o $(NAME) $(OBJ) $(LIBS) $(LINKS)
	@echo fractol compilation is \done
	@echo
	@echo run ./fractol [mandelbrot/julia/burningship]
	@echo
	@echo ----------NAVIGATION-----------
	@echo -------------------------------
	@echo '*' TO MODIFY THE MAP PRESS KEYS:  
	@echo '*' ASWD	- MOVE			  
	@echo '*' ARROWS - ROTATE 			  
	@echo '*' P - CHANGE PROJECTION 
	@echo '*' + - ENLARGE			  
	@echo '*' - - REDUCE 	
	@echo '*' PGUP, PGDN - CHANGE ALTITUDE	 			  
	@echo '*' ENTER - CHANGE COLORS	  
	@echo '*' SPACE - RESET			 
	@echo '*' ESC - CLOSE
	@echo -------------------------------
clean:
	@make clean -C $(LIBDIR)
	@make clean -C $(MLXDIR)
	@/bin/rm -f $(OBJ) *~
	@echo object files have been cleaned

fclean: clean
	@make fclean -C $(LIBDIR)
	@/bin/rm -f $(NAME)
	@echo fractol has been removed

re: fclean all
