/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:32:46 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/31 10:08:59 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*output;
	int			BUFFER_SIZE;
	int			byte_read;
	static char	*leftovers = NULL;

	BUFFER_SIZE = 100;
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	output = leftovers;
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (ft_strchr(buffer, '\n'))
		{
			leftovers = ft_strdup(ft_strchr(buffer, '\n') + 1);
			buffer = ft_cut_newline(buffer);
			output = ft_strjoin(output, buffer);
			return (output);
		}
		output = ft_strjoin(output, buffer);
	}
	return (0);
}
