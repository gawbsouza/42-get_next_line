/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:28:11 by gasouza           #+#    #+#             */
/*   Updated: 2023/03/24 09:03:02 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line_str;
	const char	*end_line_at;
	ssize_t		bytes_read;

	line_str = NULL;
	bytes_read = -1;
	while (!find_end_line_character(line_str) && bytes_read != 0)
	{
		end_line_at = find_end_line_character(buffer);
		if (end_line_at++)
		{
			concatenate_strs(&line_str, buffer, end_line_at - buffer);
			copy_str(buffer, end_line_at, get_strlen(end_line_at) + 1);
			continue ;
		}
		concatenate_strs(&line_str, buffer, get_strlen(buffer));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
	}
	return (line_str);
}
