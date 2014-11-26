/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 17:23:48 by rdestreb          #+#    #+#             */
/*   Updated: 2014/11/25 14:12:57 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

int	main(void)
{
	int 	fd;
	int		ret;
	char	*line = NULL;

	ret = 0;

//	fd = 0;
//	fd = -1;
	fd = 42;
//	fd = open ("noCRtest", O_RDONLY);
//	fd = open ("lorem_ipsum", O_RDONLY);
//	fd = open ("file_test", O_RDONLY);
//	fd = open ("ldap", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("ret: %d, str:%s\n", ret, line);
		ft_putendl(line);
		ft_strdel(&line);
	}
	printf("ret: %d, str:%s\n", ret, line);
	close (fd);
	return (0);
}
