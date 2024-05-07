/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:29:23 by crystal           #+#    #+#             */
/*   Updated: 2024/05/07 14:48:56 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*current(int fd, char *str)
{
	
}

char	*get_next_line(int fd)
{
	static char	str[BUFF_SIZE + 1];

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