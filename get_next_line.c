/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:46:44 by rdestreb          #+#    #+#             */
/*   Updated: 2014/11/18 08:20:17 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*get_line(int const fd, char *str)
{
	char	stock[BUFF_SIZE];
	char 	*tmp;
	static char *offset;

	stock[0] = 0;
	while(!(offset = ft_strchr(stock, '\n')))
	{
		read(fd, stock, BUFF_SIZE);
		tmp = str;
		stock[BUFF_SIZE] = 0;
		str = ft_strjoin(str, stock);
		ft_strdel(&tmp);
	}
//	printf("stock = %s\n", stock);
//	printf("offset = %s\n", offset);
//	printf("line = %s\n", str);
	return (str);
}

int	get_next_line(int const fd, char** line)
{
	char	*stock;
	int	ret;

	stock = ft_strnew(BUFF_SIZE);
	ret = read(fd, stock, BUFF_SIZE);
	if (fd == -1 || !(line) || ret == -1)
		return (-1);
//	stock = ft_strnew(BUFF_SIZE);
	if (ret == BUFF_SIZE)
	{
		*line = get_line(fd, stock);
		return(1);
	}
	else
		return (0);
	//	printf("offset = %s\n", offset);
}

