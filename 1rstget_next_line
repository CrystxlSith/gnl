/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1rstget_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 02:04:52 by crystal           #+#    #+#             */
/*   Updated: 2024/05/07 14:29:15 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_error(const int fd, char **line)
{
	if (fd == -1)
		return (-1);
	if (!line)
		return (-1);
	return (0);
}

char	*next_line(char *str, int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while ((bytes_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		strcat(str, buf);
	}
	return (str);
}

int	get_next_line(const int fd, char **line)
{
	static char	str[BUFF_SIZE + 1];
	int				i;

	if (check_error(fd, line) == -1)
		return (-1);
	str = next_line(str, fd);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		(*line)[i] = str[i];
		i++;
		if (str[i] == '\n')
		{
			str += (i + 1);
			(*line)[i] = '\0';
			return (1);
		}
	}
	return (0);
}

int main(void)
{
	int fd;
	char *str;

	str = (char *)malloc(sizeof(char) * BUFF_SIZE);
	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &str);
	printf("%s\n", str);
		get_next_line(fd, &str);
	printf("%s\n", str);
		get_next_line(fd, &str);
	printf("%s\n", str);
	free(str);
	return 0;
}