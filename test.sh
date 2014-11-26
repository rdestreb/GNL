# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/26 15:50:59 by rdestreb          #+#    #+#              #
#    Updated: 2014/11/26 15:51:40 by rdestreb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make -C libft/ fclean
make -C libft/
gcc -Wall -Wextra -Werror -I libft/includes/ -c get_next_line.c
gcc -Wall -Wextra -Werror -I libft/includes/ -c main.c
gcc -o test_gnl get_next_line.o main.o -L libft/ -lft