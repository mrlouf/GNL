/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:28:51 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/08 13:29:17 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*	This function uses the function read() to try and read BUFFER_SIZE-number
	of bytes that will be stored in buffer.	*/

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

/*	This function uses the stash to fill the line to be returned by GNL
	by iterating the stash until it reaches either a linebreak or
	the EOF. Upon reaching either sign, it creates a substring including
	the final sign \n or \0.	*/

char	*ft_fill_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	line = ft_substr(stash, 0, i + 1);
	if (*line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/*	This function takes the stash and iterates it until the index reaches
	either a linebreak or the EOF. Upon reaching \n, it makes a substring
	beginning after the return.	*/

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

/*	The main functions does preliminary checks on the FD and
	the BUFFER_SIZE.
	Once passed, it initialises the buf that will receive the
	bytes read by read(), as well as the static stash which
	will store the content available for the next line.	*/

char	*get_next_line(int fd)
{
	static char	*stash[FOPEN_MAX];
	char		*line;
	char		*buf;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	stash[fd] = ft_read_buffer(fd, stash[fd], buf);
	if (!stash[fd])
		return (NULL);
	free(buf);
	line = ft_fill_line(stash[fd]);
	if (!line)
	{
		free(stash[fd]);
		return (NULL);
	}
	stash[fd] = ft_new_stash(stash[fd]);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		f1;
	int		f2;
	char	*line;

	f1 = open("test1.txt", O_RDONLY);
	f2 = open("test2.txt", O_RDONLY);
	printf("%s", line = get_next_line(f1));
	free(line);
	printf("%s", line = get_next_line(f2));
	free(line);
	printf("%s", line = get_next_line(f1));
	free(line);
	printf("%s", line = get_next_line(f2));
	free(line);
	printf("%s", line = get_next_line(f1));
	free(line);
	printf("%s", line = get_next_line(f2));
	free(line);
	printf("%s", line = get_next_line(f1));
	free(line);
	printf("%s", line = get_next_line(f2));
	free(line);
	close(f1);
	close(f2);
	return (0);
}
