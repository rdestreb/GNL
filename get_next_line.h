/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:48:03 by rdestreb          #+#    #+#             */
/*   Updated: 2014/11/26 17:08:33 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 100
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft/libft.h"

int	get_next_line(int const fd, char **line);

#endif
