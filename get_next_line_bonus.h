/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:23:05 by gasouza           #+#    #+#             */
/*   Updated: 2022/05/07 23:09:00 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_fd
{
	int			fd;
	char		buffer[BUFFER_SIZE + 1];
	char		*str;
	struct s_fd	*next;
}	t_fd;

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, char c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	add_str(char **str, const char *buffer, size_t size);
t_fd	*load_fds(int fd);
t_fd	*new_fds(int fd);

#endif
