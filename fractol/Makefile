# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/10 10:57:30 by ltimsit-          #+#    #+#              #
#    Updated: 2019/06/12 18:31:32 by ltimsit-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
INCLUDE = -I include
CC = gcc $(INCLUDE)
FLAG = -c -Wall -Wextra -Werror
SRCS = main init_wd fractol_calc thread
HEADERS = $(addprefix include/, fractol.h libft.h ft_printf.h)
LIBFTSRCS = ft_strcmp
LIBFTPRINTF = libftprintf.a
LIBMLX = libmlx.a
FRAMEWORKS = -framework OpenGL -framework AppKit
CSRCS = $(addsuffix .c, $(SRCS))
OSRCS = $(addsuffix .o, $(SRCS))
LIBFTO = $(addprefix libft/, $(addsuffix .o, $(LIBFTSRCS)))

all : $(NAME)

$(NAME) : $(OSRCS) $(LIBFTO) Makefile
	make -C libft
	gcc $(FLAG) $(INCLUDE) $(CSRCS) 
	gcc -o $(NAME) $(OSRCS) $(LIBFTO) $(LIBFTPRINTF) $(LIBMLX) $(FRAMEWORKS)

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
