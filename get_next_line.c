/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:32:46 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/01 16:48:46 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*output;
	static char *left = NULL;
	char		*temp;

	if (fd < 0)
		return (NULL);
	if (ft_strchr(left, '\n'))
	{
		output = ft_find_return(left);
		left = ft_strchr(left, '\n') + 1;
		return (output);
	}
	temp = ft_read_line(fd, left);
	if (ft_strchr(temp, '\n'))
	{
		output = ft_find_return(temp);
		left = ft_strchr(temp, '\n') + 1;
		free(temp);
	}
	else
		output = temp;
	return (output);
}

char	*ft_read_line(int fd, char *left)
{
	int		bytes_read;
	char	buffer[BUFFER_SIZE + 1];
	char	*output;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 1)
		return (NULL);
	buffer[bytes_read] = 0;
	output = ft_strdup(left);
	output = ft_join_free(output, buffer);
	while (bytes_read == BUFFER_SIZE && !ft_strchr(output, '\n'))
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

	if (str == NULL)
	{
		output = ft_strdup(buffer); 
		return(output);
	}
	output = ft_strjoin(str, buffer);
	free(str);
	return (output);
}

char	*ft_find_return(char *left)
{
	char	*output;
	int		i;
	if (!ft_strchr(left, '\n'))
		return (left);
	i = 0;
	while (left[i] != '\n')
		i++;
	output = malloc(i + 1);
	i = 0;
	while (left[i] != '\n')
	{
		output[i] = left[i];
		i++;
	}
	output[i] = '\n';
	output[i + 1] = 0;
	return (output);
}
