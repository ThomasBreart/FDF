# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbreart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/29 13:22:18 by tbreart           #+#    #+#              #
#    Updated: 2015/05/11 23:18:14 by tbreart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
LMLX = minilibx_macos/libmlx.a# -lmlx
FRAMEWORK = -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
IDIR = includes/
SDIR = src/
LIBFT = libft/
SRC = $(SDIR)color_max_hight.c \
	$(SDIR)create_elem.c \
	$(SDIR)display.c \
	$(SDIR)draw_line.c \
	$(SDIR)key_hook.c \
	$(SDIR)main.c \
	$(SDIR)parse.c \
	$(SDIR)prepare_draw.c \
	$(SDIR)projections.c \
	$(SDIR)draw_line_x.c \
	$(SDIR)draw_line_y.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@make -C minilibx_macos
	@echo "-> Creation $(NAME)"
	@$(CC) -o $@ $^ $(FLAGS) $(LIBFT)libft.a $(LMLX) $(FRAMEWORK) -I $(IDIR)

%.o: %.c
	@echo "-> Compilation $<"
	@$(CC) $(FLAGS) -o $@ -c $< -I $(IDIR)

clean:
	@echo "Suppression des fichiers objet"
	@rm -f $(OBJ)
	@make -C $(LIBFT) clean

fclean: clean
	@echo "Suppression du binaire"
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
