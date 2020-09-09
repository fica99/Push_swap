# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/20 12:37:24 by aashara-          #+#    #+#              #
#    Updated: 2020/09/09 14:43:19 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  PROJECT  ----------------------------------------------------- #
NAME	=		../push_swap

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR	=		src
HDR_DIR	=		includes
OBJ_DIR	=		obj
LIB_DIR =		../lib

# ------------  LIBFT  ------------------------------------------------------- #
LFT		=		libftprintf.a
LFT_DIR	=		$(LIB_DIR)/libftprintf
LHS_DIR	=		$(LFT_DIR)/includes

# ------------  LIBSTACKINT  ------------------------------------------------- #
LSTACK_INT	=		libstackint.a
LSTACK_INT_DIR =	$(LIB_DIR)/libstackint
LSTACK_INT_HS_DIR	=	$(LSTACK_INT_DIR)/includes

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS	=		main.c\
				ps_sort.c\
				ps_sort_other.c\
				ps_rotate.c


FILL_STACK_SRC=		../check/src/fill_stack.c
FILL_STACK_OBJ=		obj/fill_stack.o
FILL_STACK_INC=		../check/includes

PS_ATOI_SRC=		../check/src/ps_atoi.c
PS_ATOI_OBJ=		obj/ps_atoi.o
PS_ATOI_INC=		../check/includes


# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		gcc
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra
LFLGS	=		-L $(LSTACK_INT_DIR) -lstackint -L $(LFT_DIR) -lftprintf -lm
IFLGS	=		-I $(HDR_DIR) -I $(FILL_STACK_INC) -I $(LHS_DIR) -I $(LSTACK_INT_HS_DIR)
DFLGS	=		-MMD -MP
OFLGS	=		-O3

# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re

all: $(NAME)

$(LFT_DIR)/$(LFT):
	$(MAKE) -C $(LFT_DIR)

$(LSTACK_INT_DIR)/$(LSTACK_INT):
	$(MAKE) -C $(LSTACK_INT_DIR)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLGS) $(DFLGS) $(OFLGS) -c -o $@ $< $(IFLGS)

-include $(DEPS)
$(FILL_STACK_OBJ): $(FILL_STACK_SRC) | $(OBJ_DIR)
	$(CC) $(CFLGS) $(DFLGS) $(OFLGS) -c -o $@ $< $(IFLGS)

-include $(DEPS)
$(PS_ATOI_OBJ): $(PS_ATOI_SRC) | $(OBJ_DIR)
	$(CC) $(CFLGS) $(DFLGS) $(OFLGS) -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LFT_DIR)/$(LFT) $(LSTACK_INT_DIR)/$(LSTACK_INT) $(OBJS) $(FILL_STACK_OBJ) $(PS_ATOI_OBJ)
	$(CC) -o $(NAME) $(OBJS) $(FILL_STACK_OBJ) $(PS_ATOI_OBJ) $(LFLGS)

$(NAME): $(OBJS)

clean:
	$(MAKE) -C $(LFT_DIR) clean
	$(MAKE) -C $(LSTACK_INT_DIR) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LFT_DIR) fclean
	$(MAKE) -C $(LSTACK_INT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
