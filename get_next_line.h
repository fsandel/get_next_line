/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:32:49 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/01 10:36:23 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_cut_newline(char *buffer);
char	*ft_join_free(char *first, char *second);
char *ft_leftys(char *str);


char	*ft_strjoin(char const *first, char const *second);
size_t	ft_strlen(const char *str);
char	*ft_calloc(size_t nitems, size_t size);
char	*ft_strchr(char const *str, int c);
char	*ft_strdup(const char *s);

#endif
