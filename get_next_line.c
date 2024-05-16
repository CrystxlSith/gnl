/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:29:23 by crystal           #+#    #+#             */
/*   Updated: 2024/05/16 11:28:18 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_start(char	*str)
{
	char	*adv_str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str)
	{
		free(str);
		return(NULL);
	}
	adv_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!adv_str)
		return (NULL);
	i += 1;
	while (str[i])
	{
		adv_str[j] = str[i];
		i++;
		j++;
	}
	adv_str[j] = '\0';
	free(str);
	return (adv_str);
}

char	*return_line(char *str)
{
	char	*newstr;
	int	i;

	i = 0;
	while (str[i] != '\n'&& str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	newstr = (char *)malloc(sizeof(char)  * (i + 2));
	if (!newstr)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		newstr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		newstr[i] = '\n';
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
} 

char	*next_line(char *str, int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while (!ft_strchr(str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFF_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buf[bytes_read] = '\0';
		str = ft_strjoin(str, buf);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	if (!str)
		str = NULL;
	if (fd == -1)
		return (NULL);
	str = next_line(str, fd);
	line = return_line(str);
	str = new_start(str);
	if (!str || !line)
		return (NULL);
	return (line);
}

int main(void)
{
	int fd;
	char	*res;
	int i = 0;

	fd = open("text.txt", O_RDONLY);
	while (i < 3)
	{
		res = get_next_line(fd);
		printf("%s\n", res);
		free(res);
		i++;
	}
	close(fd);
	return 0;
}