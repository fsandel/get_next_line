/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:32:46 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/01 13:57:45 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*output;

	output = ft_read_line(fd);
	return (output);
}

char	*ft_read_line(int fd)
{
	int		bytes_read;
	char	buffer[BUFFER_SIZE + 1];
	char	*output;

	output = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = 0;
	output = ft_join_free(output, buffer);
	if (bytes_read < 1)
		return (NULL);
	while (bytes_read > 0 && !ft_strchr(output, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		output = ft_join_free(output, buffer);
	}
	return (output);
}

char *ft_join_free(char *str, char *buffer)
{
	char	*output;

	if (!str)
		return(ft_strdup(buffer));
	output = ft_strjoin(str, buffer);
	free(str);
	return (output);
}
