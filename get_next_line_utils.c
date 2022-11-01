/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:32:36 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/31 14:55:17 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *first, char const *second)
{
	char	*joined;
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	joined = ft_calloc((ft_strlen(first) + ft_strlen(second) + 1), 1);
	if (!joined)
		return (NULL);
	while (first && first[i1])
	{	
		joined[i1] = first[i1];
		i1++;
	}
	while (second && second[i2])
	{
		joined[i1 + i2] = second[i2];
		i2++;
	}
	joined[i1 + i2] = '\0';
	return (joined);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_calloc(size_t nitems, size_t size)
{
	char	*ptr;
	size_t	i;

	if (size && (SIZE_MAX / size < nitems))
		return (NULL);
	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nitems * size)
		ptr[i++] = 0;
	return (ptr);
}

char	*ft_strchr(char const *str, int c)
{
	int				length;
	unsigned char	chr;
	char			*strr;

	if (str == NULL)
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

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	str = ft_calloc(ft_strlen(s) + 1, 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
