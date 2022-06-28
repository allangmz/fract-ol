# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 13:25:20 by aguemazi          #+#    #+#              #
#    Updated: 2022/05/28 14:37:33 by aguemazi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	fractol.c fractol_utils.c draw_fractal.c gestion_key_mouse.c

OBJS = $(SRC:.c=.o)

NAME = fractol.a

%.o: %.c
			gcc -Imlx -c $< -o $@
			# @ gcc -c -I./src $< -o ${<:.c=.o} 

$(NAME) : 	$(OBJS)
			$(MAKE) -C mlx/
			cp mlx/libmlx.a $(NAME)
			ar rcs $@ $^
			gcc $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o fractol

all : ${NAME}

re :		fclean all

clean :
			rm -f ${OBJS}
			$(MAKE) clean -C mlx/

fclean : clean
			$(MAKE) clean -C mlx/
			rm -f ${OBJS}
			rm -f  ${NAME}

.phony : all flean clean re