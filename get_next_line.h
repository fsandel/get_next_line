/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:32:49 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/31 10:05:50 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

char	*get_next_line(int fd);
int	ft_output_size(char *buffer, int size);
char	*ft_strjoin(char const *first, char const *second);
char	*ft_cut_newline(char *buffer);
size_t	ft_strlen(const char *str);
char	*ft_calloc(size_t nitems, size_t size);
char	*ft_strchr(char const *str, int c);
char	*ft_strdup(const char *s);




#endif
