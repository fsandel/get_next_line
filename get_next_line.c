/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:32:46 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/01 12:04:53 by fsandel          ###   ########.fr       */
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
		temp = leftovers;
		output = ft_cut_newline(leftovers);
		leftovers = ft_leftys(temp);
		free(temp);
		return (output);
	}
	output = leftovers;
	leftovers = NULL;
	while (byte_read > 0 && !ft_strchr(output, '\n'))
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
		byte_read = read(fd, buffer, BUFFER_SIZE);
		output = ft_strjoin(output, buffer);
		free(buffer);
	}
	temp = output;
	leftovers = ft_leftys(output);
	output = ft_cut_newline(temp);
	//free(temp);
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
	free(buffer);
	return (output);
}

char *ft_leftys(char *str)
{
	char	*output;
	int		i;
	int		j;

	if (!ft_strchr(str, '\n'))
		return (NULL);
	i = 0;
	while(str[i] != '\n')
		i++;
	i++;
	j = i;
	while(str[j])
		j++;
	output = ft_calloc(j - i + 1, 1);
	while (str[i])
	{
		output[i] = str[i];
		i++;
	}
	//free(str);
	return(output);
}
