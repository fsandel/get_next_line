/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:32:46 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/31 08:26:31 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 5

char	*get_next_line(int fd)
{
	char		*buffer;
	int			i;
	char		c;

	buffer = malloc(BUFFER_SIZE);
	i = 0;
	while (1)
	{
		read(fd, &c, 1);
		buffer[i] = c;
		if (c == '\n' || c == 0)
		{
			break ;
		}
		i++;
	}
	buffer[i] = 0;
	return (buffer);
}
