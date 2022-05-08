/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:28:11 by gasouza           #+#    #+#             */
/*   Updated: 2022/05/07 23:08:35 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_fd	*new_fds(int fd)
{
	t_fd	*tmp;

	tmp = (t_fd *) malloc(sizeof(t_fd));
	if (tmp != NULL)
	{
		tmp->fd = fd;
		tmp->str = NULL;
		tmp->buffer[0] = '\0';
		tmp->next = NULL;
	}
	return (tmp);
}

t_fd	*load_fds(int fd)
{
	static t_fd	*fds;
	t_fd		*tmp;

	if (fds == NULL)
	{
		fds = new_fds(fd);
		return (fds);
	}
	tmp = fds;
	while (tmp->fd != fd && tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->fd != fd)
	{
		tmp->next = new_fds(fd);
		tmp = tmp->next;
	}
	tmp->str = NULL;
	return (tmp);
}

char	*get_next_line(int fd)
{
	t_fd	*fds;
	char	*n_pos;
	ssize_t	b_read;

	fds = load_fds(fd);
	b_read = -1;
	while (!ft_strchr(fds->str, '\n') && b_read != 0)
	{
		n_pos = ft_strchr(fds->buffer, '\n');
		if (n_pos++)
		{
			add_str(&fds->str, fds->buffer, n_pos - fds->buffer);
			ft_strlcpy(fds->buffer, n_pos, ft_strlen(n_pos) + 1);
		}
		else
		{
			add_str(&fds->str, fds->buffer, ft_strlen(fds->buffer));
			b_read = read(fd, fds->buffer, BUFFER_SIZE);
			if (b_read < 0)
				return (NULL);
			fds->buffer[b_read] = '\0';
		}
	}
	return (fds->str);
}
