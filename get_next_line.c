/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:45:51 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/04 21:13:42 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	This function splits the current buffer in two:
	the string incl. the \n into buffer and the rest in the stash.
	If no \n is found, it returns the full buffer.
*/

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

	line = "";
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		free(buffer);
	buffer[BUFFER_SIZE] = '\0';
	while (read(fd, buffer, BUFFER_SIZE) != 0)
	{
		if (ft_strchr(buffer, '\n') != NULL)
			return (ft_strjoin(line, ft_buffer_split(buffer, stash)));
		line = ft_strjoin(line, ft_buffer_split(buffer, stash));
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
