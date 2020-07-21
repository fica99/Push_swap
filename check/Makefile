# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/20 12:37:24 by aashara-          #+#    #+#              #
#    Updated: 2020/07/21 16:04:25 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  PROJECT  ----------------------------------------------------- #
NAME	=		../checker

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR	=		src
HDR_DIR	=		includes
OBJ_DIR	=		obj
LIB_DIR =		../lib

# ------------  LIBFT  ------------------------------------------------------- #
LFT		=		libft.a
LFT_DIR	=		$(LIB_DIR)/libft
LHS_DIR	=		$(LFT_DIR)/includes

# ------------  LIBSTACKINT  ------------------------------------------------- #
LSTACK_INT	=		libstackint.a
LSTACK_INT_DIR =	$(LIB_DIR)/libstackint
LSTACK_INT_HS_DIR	=	$(LSTACK_INT_DIR)/includes

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS	=		main.c\
				check_commands.c\
				print_stacks.c\
				fill_stack.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		gcc
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra
LFLGS	=		-L $(LSTACK_INT_DIR) -lstackint -L $(LFT_DIR) -lft
IFLGS	=		-I $(HDR_DIR) -I $(LHS_DIR) -I $(LSTACK_INT_HS_DIR)
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

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LFT_DIR)/$(LFT) $(LSTACK_INT_DIR)/$(LSTACK_INT) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LFLGS)

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
