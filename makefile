# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 17:34:44 by fdagbert          #+#    #+#              #
#    Updated: 2019/04/01 17:48:37 by fdagbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECK = checker
NAME_PUSH = push_swap

SRC_PATH = srcs

SRC_CHECK_PATH = $(SRC_PATH)/$(NAME_CHECK)
CHECK_FCT = ft_check_list.c			\
			ft_init_file.c			\
			ft_check_inst.c			\
			ft_apply_inst.c			\
			ft_end.c				\
			ft_check_sort.c			\
			ft_print_verbose.c		\
			main.c
CHECK_SRC = $(addprefix $(SRC_CHECK_PATH)/,$(CHECK_FCT))

SRC_PUSH_PATH = $(SRC_PATH)/$(NAME_PUSH)
PUSH_FCTS = ft_check_list.c			\
			ft_init_file.c			\
			ft_apply_inst.c			\
			ft_end.c				\
			ft_check_sort.c			\
			ft_add_inst.c			\
			ft_sort_list.c			\
			ft_unit_sort.c			\
			ft_qsort_a.c			\
			ft_qsort_b.c			\
			ft_insert_sort_b.c		\
			ft_clone_tab.c			\
			main.c
PUSH_SRC = $(addprefix $(SRC_PUSH_PATH)/,$(PUSH_FCTS))

OBJ_PATH = objects

OBJ_CHECK_PATH = $(OBJ_PATH)/$(NAME_CHECK)
OBJ_CHECK_FUNCT = $(CHECK_FCT:.c=.o)
OBJ_CHECK_SRC = $(addprefix $(OBJ_CHECK_PATH)/,$(OBJ_CHECK_FUNCT))

OBJ_PUSH_PATH = $(OBJ_PATH)/$(NAME_PUSH)
OBJ_PUSH_FUNCT = $(PUSH_FCTS:.c=.o)
OBJ_PUSH_SRC = $(addprefix $(OBJ_PUSH_PATH)/,$(OBJ_PUSH_FUNCT))

OBJECTS = $(OBJ_CHECK_SRC) $(OBJ_PUSH_SRC)

LIB_PATH = .
LIB_NAME = libftprintf.a

LIBFT_PATH = $(LIB_PATH)/libft
FTPRINTF_PATH = $(LIB_PATH)/ft_printf

INC_PATH = includes

INCLUDES = $(LIBFT_PATH)/$(INC_PATH) $(FTPRINTF_PATH)/$(INC_PATH) $(INC_PATH)
INC_CC = $(foreach DIR,$(INCLUDES),-I$(DIR))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -L$(LIB_PATH)/ft_printf
LDLIBS = -lftprintf

.PHONY: all, clean, fclean, re, lib

all: lib $(NAME_CHECK) $(NAME_PUSH)

lib:
	make -C $(FTPRINTF_PATH)

$(NAME_CHECK): $(OBJ_CHECK_SRC)
	$(CC) -o $(NAME_CHECK) $(OBJ_CHECK_SRC) $(INC_CC) $(LDFLAGS) $(LDLIBS)

$(OBJ_CHECK_PATH)/%.o: $(SRC_CHECK_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_CHECK_PATH) 2> /dev/null || true
	$(CC) -g $(CFLAGS) $(INC_CC) -o $@ -c $<

$(NAME_PUSH): $(OBJ_PUSH_SRC)
	$(CC) -o $(NAME_PUSH) $(OBJ_PUSH_SRC) $(INC_CC) $(LDFLAGS) $(LDLIBS)

$(OBJ_PUSH_PATH)/%.o: $(SRC_PUSH_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_PUSH_PATH) 2> /dev/null || true
	$(CC) -g $(CFLAGS) $(INC_CC) -o $@ -c $<

clean:
	make -C $(FTPRINTF_PATH) clean
	rm -fv $(OBJECTS)
	@rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make -C $(FTPRINTF_PATH) fclean
	rm -fv $(NAME_CHECK)
	rm -fv $(NAME_PUSH)

re: fclean all
