# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/20 12:29:11 by aashara-          #+#    #+#              #
#    Updated: 2020/08/26 17:40:23 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

checker := check

checker := check

.PHONY: all $(checker) clean fclean re

all: $(checker)

$(checker):
	$(MAKE) all --no-print-directory -C $(checker)

clean:
	$(MAKE) clean --no-print-directory -C $(checker)

fclean:
	$(MAKE) fclean --no-print-directory -C $(checker)

re: fclean all
