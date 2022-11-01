/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:32:46 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/31 18:39:37 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*output;
	static char	*leftovers = NULL;
	int			byte_read;
	char		*temp;

	byte_read = 1;
	if (ft_strchr(leftovers, '\n'))
	{
		temp = ft_strchr(leftovers, '\n') + 1;
		output = ft_cut_newline(leftovers);
		leftovers = NULL;
		free(leftovers);
		leftovers = temp;
		return (output);
	}
	output = leftovers;
	leftovers = NULL;
	while (byte_read > 0)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 1)
		{
			free(buffer);
			return (output);
		}
		output = ft_strjoin(output, buffer);
		free(buffer);
		if (ft_strchr(output, '\n'))
		{
			leftovers = ft_strchr(output, '\n') + 1;
			output = ft_cut_newline(output);
			return (output);
		}
	}
	return (output);

}

char	*ft_cut_newline(char *buffer)
{
	int		i;
	int		len;
	char	*output;

	if (ft_strchr(buffer, '\n') == NULL)
		return (buffer);
	len = ft_strlen(buffer);
	output = ft_calloc(len + 1, 1);
	i = 0;
	while (i < len)
	{
		output[i] = buffer[i];
		i++;
		if (output[i] == '\n')
			break ;
	}
	output[i] = 0;
	return (output);
}

char	*ft_join_free(char *first, char *second)
{
	char	*output;

	output = ft_strjoin(first, second);
	free(first);
	free(second);
	return (output);
}
