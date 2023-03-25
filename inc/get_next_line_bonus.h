/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:23:05 by gasouza           #+#    #+#             */
/*   Updated: 2023/03/25 10:13:25 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef MAX_FDS
#  define MAX_FDS 1024
# endif

char		*get_next_line(int fd);
const char	*find_end_line_character(const char *str);
size_t		get_strlen(const char *str);
size_t		copy_str(char *dst, const char *src, size_t size);
void		concatenate_strs(char **dst, const char *src, size_t size);

#endif