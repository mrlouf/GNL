/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:45:51 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/07 19:04:28 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_buffer(int fd, char *stash, char *buffer)
{
	int		bytes;

	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		else if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (!stash)
			stash = ft_strdup("");
		if (!stash)
			return (NULL);
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
	}
	return (stash);
}

char	*ft_fill_line(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
	  return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	return (ft_substr(stash, 0, i + 1));
}

char	*ft_new_stash(char *stash)
{
	int		i;
	char	*new_stash;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	new_stash = ft_substr(stash, i, ft_strlen(stash) - i);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buf;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	stash = ft_read_buffer(fd, stash, buf);
	if (!stash)
	  return (NULL);
	free(buf);
	line = ft_fill_line(stash);
	if (!line)
	{
		free(stash);
		return (NULL);
	}
	stash = ft_new_stash(stash);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*path;
	char	*line;

	path = "test.txt";
	fd = open(path, O_RDONLY);
	printf("%s", line = get_next_line(fd));
	printf("%s", line = get_next_line(fd));
	printf("%s", line = get_next_line(fd));
	printf("%s", line = get_next_line(fd));
	printf("%s", line = get_next_line(fd));
	printf("%s", line = get_next_line(fd));
	printf("%s", line = get_next_line(fd));
	printf("%s", line = get_next_line(fd));
	printf("%s", line = get_next_line(fd));
	free(line);
	close(fd);
	return (0);
}*/
