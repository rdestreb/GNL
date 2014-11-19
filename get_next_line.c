/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:46:44 by rdestreb          #+#    #+#             */
/*   Updated: 2014/11/19 12:08:58 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*text_copy(int const fd, char *text)
{
	char	*stock;
	char 	*tmp;
	int		ret;

	stock = ft_strnew(BUFF_SIZE);
	ret = 0;
	while ((ret = read(fd, stock, BUFF_SIZE)))
	{
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
		//	printf("TMP = %s\n", tmp);
		*line = ft_strsub(offset, 0, ft_strlen(offset) - ft_strlen(tmp));
//		printf("%s\n", tmp);

		offset = ft_strdup(tmp + 1);
//		printf("offset 1 = %s\n", offset);

	}
	else
	{
		*line = ft_strdup(offset);
		ft_strdel(&offset);
	}
	return (offset);
}

int		get_next_line(int const fd, char **line)
{
	static char	*offset;

	if (fd == -1 || !(line))
		return (-1);
	if (!offset)
	{
//		printf("coucou\n");
		offset = ft_strnew(BUFF_SIZE);
		offset = text_copy(fd, offset);
	}
//	printf("taille text = %ld\n", ft_strlen(offset));
	offset = get_line(offset, line);
//	printf("offset 2 = %s\n", offset);
	if (offset[0] != 0)
		return (1);
	else
		return (0);
}
