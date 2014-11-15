/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:46:44 by rdestreb          #+#    #+#             */
/*   Updated: 2014/11/15 17:52:24 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str, int const fd)
{
//	int		ret;
	char	stock[BUFF_SIZE];

//	ret = 0;
	if(!(ft_strchr(stock, '\n')))
		while(/*ret = */read(fd, stock, BUFF_SIZE))
			str = ft_strjoin(str, stock);
	return (str);
}
/*
int	get_next_line(int const fd, char** line)
{
	char	stock[BUFF_SIZE];
	int		i;
	int		ret;

	if (fd == -1)
		return (-1);
	ret = 0;
	while (read(fd, stock, BUFF_SIZE) == BUFF_SIZE)

	return(0);
}
*/
