# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fracerba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 12:32:24 by fracerba          #+#    #+#              #
#    Updated: 2023/01/04 12:32:30 by fracerba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

OUT = so_long.out

SRCS = so_long.c \
	ft_check_map.c \
	ft_enemy_movement.c \
	ft_enemy_set.c \
	ft_events.c \
	ft_find.c \
	ft_img_render.c \
	ft_map_get_buffer.c \
	ft_map_render.c \
	ft_map_utils1.c \
	ft_map_utils2.c \
	ft_movement.c \
	ft_endings.c \
	ft_pathfinding.c \
	ft_pathfinding2.c \

OBJS = ${SRCS:.c=.o}

CC = gcc -no-pie

RM = rm -f

FLAGS = -Wall -Werror -Wextra

LINKS = -Lminilibx-linux -L/usr/lib -Iminilibx-linux -lmlx -lXext -lX11 -lm -lz

LIBFT = libft

LIBFTNAME = libft.a
	
%.o: %.c
	${CC} ${FLAGS} -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

$(NAME): ${OBJS}
	make all -C ${LIBFT}
	mv ${LIBFT}/${LIBFTNAME} ${NAME}
	${CC} ${FLAGS} ${OBJS} ${NAME} ${LINKS} -o ${OUT}

all: ${NAME}

bonus:	${OBJS}
	make all -C ${LIBFT}
	mv ${LIBFT}/${LIBFTNAME} ${NAME}
	${CC} ${FLAGS} ${OBJS} ${NAME} ${LINKS} -o ${OUT}

clean: 
	${RM} ${OBJS}
	make clean -C ${LIBFT}

fclean: clean 
	${RM} ${NAME}
	make fclean -C ${LIBFT}

re: fclean all
