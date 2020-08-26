# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/20 12:29:11 by aashara-          #+#    #+#              #
#    Updated: 2020/08/26 18:09:25 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

checker := check

push_swap := push

.PHONY: all $(checker) $(push_swap) clean fclean re

all: $(checker) $(push_swap)

$(push_swap):
	$(MAKE) all --no-print-directory -C $(push_swap)

$(checker):
	$(MAKE) all --no-print-directory -C $(checker)

clean:
	$(MAKE) clean --no-print-directory -C $(checker)
	$(MAKE) clean --no-print-directory -C $(push_swap)

fclean:
	$(MAKE) fclean --no-print-directory -C $(checker)
	$(MAKE) fclean --no-print-directory -C $(push_swap)

re: fclean all
