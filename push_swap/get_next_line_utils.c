/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:10:16 by boummi            #+#    #+#             */
/*   Updated: 2025/12/12 19:13:01 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strndup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	if (s[i])
		i++;
	while (s[i] && s[i - 1] != '\n')
		i++;
	dest = malloc(i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	if (s[i++])
		dest[i - 1] = s[i - 1];
	while (s[i] && s[i - 1] != '\n')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strnjoin(char *s1, char *s2)
{
	char	*dest;

	int (i), (j);
	i = 0;
	j = 0;
	if (!s1)
		return (ft_strndup(s2));
	if (!s2)
		return (ft_strndup(s1));
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	free(s1);
	s1 = NULL;
	if (s2[j])
		dest[i++] = s2[j++];
	while (s2[j] && s2[j - 1] != '\n')
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}
