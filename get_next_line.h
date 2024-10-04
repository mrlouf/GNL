/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:45:27 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/04 16:43:42 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *dst, char *src);
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
char	*ft_buffer_split(char *buffer, char *stash);
char	*ft_strdup(char *str);
char	*ft_strchr(const char *s, int c);

#endif
