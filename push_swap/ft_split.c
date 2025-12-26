/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:50:25 by boummi            #+#    #+#             */
/*   Updated: 2025/09/02 02:07:31 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//#include <stdio.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (is_charset(str[0], charset) && str[i])
		count--;
	while (str[i])
	{
		if (is_charset(str[i], charset) == 1 && is_charset(str[i + 1],
				charset) == 0 && str[i + 1])
			count++;
		i++;
	}
	count++;
	return (count);
}

char	*ft_strdup(char *src, int size)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = malloc(size + 1);
	if (!new_str)
		return (NULL);
	while (i < size)
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**strs;

	strs = malloc((count_word(str, charset) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	k = 0;
	while (is_charset(str[i], charset) && str[i])
		i++;
	while (str[i])
	{
		j = i;
		while (!(is_charset(str[j], charset)) && str[j])
			j++;
		strs[k] = ft_strdup(&str[i], j - i);
		k++;
		i = j;
		while ((is_charset(str[i], charset)) && str[i])
			i++;
	}
	strs[k] = NULL;
	return (strs);
}
/*
int	main(int ac, char **av)
{
	(void)ac;
	char	**strs = ft_split(av[1],av[2]);
	int	i = 0;

	while (strs[i] != NULL)
	{
		printf("|%s| \n",strs[i]);
		i++;
	}
	printf("%s \n",strs[i]);
	return (0);
}*/
