/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:45:51 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/04 20:28:25 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*ft_buffer_split(char *buffer, char *stash)
{
	int	i;

	i = -1;
	while (++i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n')
		{
			stash = ft_substr(buffer, i + 1, BUFFER_SIZE - (i + 1));
			return (buffer = ft_substr(buffer, 0, i + 1));
		}
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE];
	char		*buffer;
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = "";
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		free(buffer);
	buffer[BUFFER_SIZE] = '\0';
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		if (ft_strchr(stash, '\n') != NULL)
			return (ft_strjoin(line, ft_buffer_split(buffer, stash)));
		line = ft_strjoin(line, ft_buffer_split(buffer, stash));
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	/*		TODO
	 * - in case of error or EOF, return NULL
	 * - what happens if the document is empty? incorrect? full of \n?
	 */
	free(buffer);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*path;

	path = "test.txt";
	fd = open(path, O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);

	/*	TODO
	 * - the main receives and prints every stash returned by
	 *   get next line until it returns 0, indicating the EOF.
	 */
}
