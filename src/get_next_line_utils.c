/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:30:10 by gasouza           #+#    #+#             */
/*   Updated: 2023/03/25 10:13:52 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

const char	*find_end_line_character(const char *str)
{
	if (str)
	{
		while (*str && *str != '\n')
			str++;
		if (*str == '\n')
			return (str);
	}
	return (NULL);
}

size_t	get_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str && *str++)
		len++;
	return (len);
}

void	concatenate_strs(char **dst, const char *src, size_t size)
{
	char	*tmp;
	size_t	old_len;

	tmp = NULL;
	if (src[0])
	{
		old_len = get_strlen(*dst);
		tmp = (char *) malloc((old_len + size + 1) * sizeof(char));
		if (tmp)
		{
			copy_str(tmp, *dst, old_len + 1);
			copy_str(tmp + old_len, src, size + 1);
		}
	}
	free(*dst);
	*dst = tmp;
}

size_t	copy_str(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = get_strlen(src);
	if (size--)
	{		
		while (size-- && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (len);
}
