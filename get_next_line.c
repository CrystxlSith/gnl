/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:29:23 by crystal           #+#    #+#             */
/*   Updated: 2024/05/07 15:27:37 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_error(int fd, char **str)
{
	if (fd == -1)
		return (-1);
	if (!str)
		*str = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (!str)
		return (-1);
	return (0);
}

char	*next_line(char *str, int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while ()
	{
		bytes_read = read(fd, buf, BUFF_SIZE);
		buf[bytes_read] = '\0';
		strcat(str, buf);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;

	if (check_error(fd, str) == -1)
		return (NULL);
	str = next_line(fd, str);

	return (0);
}

int main(void)
{
	int fd;

	fd = open("text.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));

	return 0;
}