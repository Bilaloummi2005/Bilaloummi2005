/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:12:47 by boummi            #+#    #+#             */
/*   Updated: 2025/10/30 13:20:19 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*copy_without_new_line(char *buff, int i, long int buffer_size)
{
	char	*ret;
	int		j;
	int		size;

	j = 0;
	size = ft_strlen(buff) - i;
	if (size > 0)
	{
		ret = malloc((size_t)buffer_size + 1);
		if (!ret)
			return (NULL);
		while (j < size)
		{
			ret[j] = buff[i + j];
			j++;
		}
		ret[j] = '\0';
		free(buff);
		buff = NULL;
		return (ret);
	}
	free(buff);
	buff = NULL;
	return (NULL);
}

int	check_buffer(int fd, char **buffer)
{
	long	readm;

	if (fd < 0 || BUFFER_SIZE < 0 || fd > 1024)
		return (0);
	if (!buffer[0])
	{
		buffer[0] = malloc((size_t)BUFFER_SIZE + 1);
		if (!buffer[0])
			return (0);
		readm = read(fd, buffer[0], BUFFER_SIZE);
		if (readm <= 0)
		{
			free(buffer[0]);
			buffer[0] = NULL;
			return (0);
		}
		buffer[0][readm] = '\0';
	}
	return (1);
}

int	put_buf_inline(int fd, char **buffer, char **line, int *i)
{
	long	readm;

	while (buffer[0][*i] != '\n')
	{
		if (buffer[0][*i] == '\0')
		{
			line[0] = ft_strnjoin(line[0], buffer[0]);
			readm = read(fd, buffer[0], BUFFER_SIZE);
			*i = 0;
			if (readm <= 0)
			{
				free(buffer[0]);
				buffer[0] = NULL;
				return (1);
			}
			buffer[0][readm] = '\0';
			if (buffer[0][*i] == '\n')
				break ;
		}
		(*i)++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int			i;
	static char	*buffer;
	char		*line;

	if (check_buffer(fd, &buffer) == 0)
		return (NULL);
	i = 0;
	line = NULL;
	if (buffer[i])
	{
		if (put_buf_inline(fd, &buffer, &line, &i))
			return (line);
		line = ft_strnjoin(line, buffer);
	}
	else
		return (NULL);
	buffer = copy_without_new_line(buffer, i + 1, BUFFER_SIZE);
	return (line);
}
