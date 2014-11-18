/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:46:44 by rdestreb          #+#    #+#             */
/*   Updated: 2014/11/18 16:33:29 by rdestreb         ###   ########.fr       */
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

char	*get_line(char *stock, int offset)
{
	char	*line;
	int		start;

	start = offset;
	while (stock[offset] && stock[offset] != '\n')
		offset++;
	line = ft_strsub(stock, start, offset - start);
	offset += 1;
	return (line);
}

int	get_next_line(int const fd, char** line)
{
	static unsigned int	offset;
	char		*text;

	offset = 0;
	text = ft_strnew(BUFF_SIZE);
	if (fd == -1 || !(line))
		return (-1);
	if (offset == 0)
		text = text_copy(fd, text);
	printf("taille text = %ld\n", ft_strlen(text));
	*line = get_line(text, offset);
	if (ft_strlen(text) > offset)
		return (1);
	return (0);
}
