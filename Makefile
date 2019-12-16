# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/10 10:57:30 by ltimsit-          #+#    #+#              #
#    Updated: 2019/06/23 13:52:25 by ltimsit-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
INCLUDE = -I include
CC = gcc $(INCLUDE)
FLAG = -c -Wall -Wextra -Werror
SRCS = main init_wd fractol_calc thread change_param hook side_panel \
	   switch_fractal
HEADERS = $(addprefix include/, fractol.h libft.h ft_printf.h)
LIBFTPRINTF = libftprintf.a
LIBSRCS = $(addprefix libft/, ft_strcmp)
LIBMLX = libmlx.a
FRAMEWORKS = -framework OpenGL -framework AppKit
CSRCS = $(addsuffix .c, $(SRCS))
OSRCS = $(addsuffix .o, $(SRCS))
OLIBSRCS = $(addsuffix .o, $(LIBSRCS))

all : $(NAME)

$(NAME) : $(OSRCS) $(OLIBSRCS) Makefile
	make -C libft
	gcc $(FLAG) $(INCLUDE) $(CSRCS) 
	gcc -o $(NAME) $(OSRCS) $(OLIBSRCS) $(LIBFTPRINTF) $(LIBMLX) $(FRAMEWORKS)

clean :
	rm -rf $(OSRCS)
	make clean -C libft

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft

re : fclean all

norme :
	norminette $(CSRCS) $(HEADERS)
.PHONY : re clean fclean all
