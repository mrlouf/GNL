char	*get_next_line(int fd)
{
	static char	*stash;

		open(fd, stash, BUFFERSIZE);
	/*	TODO
	 * - read from the file descriptor
	 * - extract (substr?) buffer-sized string
	 * - return it to the static char
	 * - when \n is met, clear 
	 * - in case of error or EOF, return NULL
	 * - malloc buffer-sized string to receive each iteration
	 * - free the string afterwards
	 *
	 *
	 */

	return (str);
}

int	main(void)
{
	/*	TODO
	 * - the main receives 
	 *
	 *
	 */
}
