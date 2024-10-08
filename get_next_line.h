/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:45:27 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/07 16:05:38 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# include <unistd.h>
# include <stdlib.h>

// GET NEXT LINE

char	*get_next_line(int fd);
char	*ft_free(char *stash);
char	*ft_fill_line(char *stash);
char	*ft_read_buffer(int fd, char *stash, char *buffer);

//  UTILS

char	*ft_strjoin(char *dst, char *src);
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *str);
char	*ft_strchr(const char *s, int c);

#endif
