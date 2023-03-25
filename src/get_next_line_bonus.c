/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:28:11 by gasouza           #+#    #+#             */
/*   Updated: 2023/03/25 10:12:22 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FDS][BUFFER_SIZE + 1];
	char		*line_str;
	const char	*end_line_at;
	ssize_t		bytes_read;

	line_str = NULL;
	bytes_read = -1;
	while (!find_end_line_character(line_str) && bytes_read != 0)
	{
		end_line_at = find_end_line_character(buffer[fd]);
		if (end_line_at++)
		{
			concatenate_strs(&line_str, buffer[fd], end_line_at - buffer[fd]);
			copy_str(buffer[fd], end_line_at, get_strlen(end_line_at) + 1);
			continue ;
		}
		concatenate_strs(&line_str, buffer[fd], get_strlen(buffer[fd]));
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[fd][bytes_read] = '\0';
	}
	return (line_str);
}
