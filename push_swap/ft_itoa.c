/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:47:26 by boummi            #+#    #+#             */
/*   Updated: 2025/10/20 19:20:05 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	size_n(long int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_reverce(long int nbr, char *s, int a)
{
	char	*str;
	int		n;
	int		m;

	str = malloc(12);
	n = 0;
	while (nbr > 0)
	{
		str[n] = nbr % 10 + '0';
		nbr /= 10;
		n++;
	}
	m = a + n;
	while (a < m)
	{
		n--;
		s[a] = str[n];
		a++;
	}
	free(str);
	s[a] = '\0';
}

int	check_zero_sign(char *str, int n)
{
	if (n == 0)
	{
		str[0] = '0';
		return (1);
	}
	if (n < 0)
	{
		str[0] = '-';
		return (1);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	int			size;
	char		*str;

	size = 0;
	nbr = n;
	if (nbr <= 0)
	{
		size++;
		nbr = -nbr;
	}
	size += size_n(nbr);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	size = check_zero_sign(str, n);
	ft_reverce(nbr, str, size);
	return (str);
}
