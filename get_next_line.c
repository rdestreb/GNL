/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:46:44 by rdestreb          #+#    #+#             */
/*   Updated: 2014/11/19 17:19:07 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*text_copy(int const fd, char *text)
{
	char	stock[BUFF_SIZE + 1];
	char 	*tmp;
	int		ret;
	int		flag;

	flag = 0;
	ret = 0;
	while ((!flag && !ret) || !(ft_strchr(text, '\n'))) 
	{
		flag = 1;
		ret = read(fd, stock, BUFF_SIZE);
		tmp = text;
		stock[ret] = 0;
		text = ft_strjoin(text, stock);
		ft_strdel(&tmp);
	}
	return (text);
}

char	*get_line(char *offset, char **line)
{
	char 	*tmp;

	if ((tmp = ft_strchr(offset, '\n')))
	{
		*line = ft_strsub(offset, 0, ft_strlen(offset) - ft_strlen(tmp));
		offset = tmp + 1;
	}
	else
	{
		*line = ft_strdup(offset);
		ft_strclr(offset);
	}
	return (offset);
}

int		get_next_line(int const fd, char **line)
{
	static char	*offset = NULL;

	if (fd < 0 || !(line))
		return (-1);
	offset = text_copy(fd, offset);
	offset = get_line(offset, line);
	if (offset[0] != 0)
		return (1);
	else
		return (0);
}
