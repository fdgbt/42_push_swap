# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 17:34:44 by fdagbert          #+#    #+#              #
#    Updated: 2019/03/27 01:47:25 by fdagbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = srcs
FUNCTIONS = ft_printf.c			\
			ft_check_flags.c	\
			ft_check_conf.c		\
			ft_set_wild.c		\
			ft_addbuff.c		\
			ft_imtoa_base.c		\
			ft_umtoa_base.c		\
			ft_conv_int.c		\
			ft_fill_int.c		\
			ft_conv_new.c		\
			ft_conv_char.c		\
			ft_conv_utf8.c		\
			ft_conv_string.c	\
			ft_conv_wstr.c		\
			ft_conv_address.c	\
			ft_conv_pct.c		\
			ft_conv_ctrl.c		\
			ft_conv_date.c		\
			ft_format_date.c	\
			ft_conv_fd.c		\
			ft_conv_file.c		\
			ft_conv_crypt.c		\
			ft_text_effects.c
SRC = $(addprefix $(SRC_PATH)/,$(FUNCTIONS))

OBJ_PATH = objects
OBJ_FUNCT = $(FUNCTIONS:.c=.o)
OBJ_SRC = $(addprefix $(OBJ_PATH)/,$(OBJ_FUNCT))

OBJECTS = $(OBJ_SRC)

LIBFT_PATH = ../libft
LIBFT_NAME = libft.a

INCLUDES = $(LIBFT_PATH)/includes includes
INC_CC = $(foreach DIR,$(INCLUDES),-I$(DIR))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re, lib

all: lib $(NAME)

lib:
	make -C $(LIBFT_PATH)

$(NAME): $(OBJECTS)
	@cp $(LIBFT_PATH)/$(LIBFT_NAME) $(NAME) 2> /dev/null || true
	ar -rcs $(NAME) $^
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -g $(CFLAGS) $(INC_CC) -o $@ -c $<

clean:
	make -C $(LIBFT_PATH) clean
	rm -fv $(OBJECTS)
	@rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	rm -fv $(NAME)

re: fclean all
