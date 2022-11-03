/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:08:30 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/03 09:08:33 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//returns length of string str
//change here, protected if no input string
size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

//search for c in str and returns pointer to it
//change here, protected if no input string
char	*ft_strchr(char *str, int c)
{
	int				length;
	unsigned char	chr;
	char			*strr;

	if (!str)
		return (0);
	strr = (char *)str;
	chr = (unsigned char)c;
	length = ft_strlen(strr);
	while (*strr != chr)
	{
		if ((length) == 0)
			return (NULL);
		strr++;
		length--;
	}
	return (strr);
}

//adds string second at the end of string first and returns it
char	*ft_strjoin(char *first, char *second)
{
	char	*joined;
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	joined = malloc(ft_strlen(first) + ft_strlen(second) + 1);
	if (!joined)
		return (NULL);
	while (first[i1])
	{
		joined[i1] = first[i1];
		i1++;
	}
	while (second[i2])
	{
		joined[i1 + i2] = second[i2];
		i2++;
	}
	joined[ft_strlen(first) + ft_strlen(second)] = 0;
	return (joined);
}
