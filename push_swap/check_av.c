/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:57:46 by boummi            #+#    #+#             */
/*   Updated: 2025/12/12 18:58:08 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	direct_fille(t_stack **a, char **av, int ac)
{
	int	i;

	i = 2;
	if (ft_atoi(av[1]) > 2147483647 || (ft_atoi(av[1]) < -2147483648))
		return (0);
	*a = ft_newstack(ft_atoi(av[1]));
	while (i < ac)
	{
		if (ft_atoi(av[i]) > 2147483647 || (ft_atoi(av[i]) < -2147483648))
			return (0);
		add_front(*a, ft_atoi(av[i]));
		i++;
	}
	return (1);
}

int	split_fille(t_stack **a, char **av)
{
	char	**args;
	int		j;


	j = 1;
	if (!av[1][0])
		return (1);
	args = ft_split(av[1], " 	");
	if (ft_atoi(args[0]) > 2147483647 || (ft_atoi(args[0]) < -2147483648))
		return (free_garbage(args), 0);
	*a = ft_newstack(ft_atoi(args[0]));
	while (args[j] != NULL)
	{
		if (ft_atoi(args[j]) > 2147483647 || (ft_atoi(args[j]) < -2147483648))
			return (free_garbage(args), 0);
		add_front(*a, ft_atoi(args[j]));
		j++;
	}
	free_garbage(args);
	return (1);
}

void	free_split(int ac, char **args)
{
	if (ac == 2)
		free_garbage(args);
}

int	chiker(int ac, char **av)
{
	int		i;
	int		j;
	char	**args;

	i = 1;
	args = av;
	if (ac == 2)
	{
		args = ft_split(av[1], " 	");
		i = 0;
	}
	while (args[i])
	{
		j = 0;
		if ((args[i][j] == '-' || args[i][j] == '+') && args[i][j + 1])
			j++;
		while (args[i][j])
		{
			if (!(args[i][j] >= '0' && args[i][j] <= '9'))
				return (free_split(ac, args), 0);
			j++;
		}
		i++;
	}
	return (free_split(ac, args), 1);
}

int	check_cases(t_stack **a, int ac, char **av)
{
	if (ac <= 1)
	{
		write(2, "Error\n", 6);
		return (del_stack(a), 0);
	}
	if (!chiker(ac, av))
	{
		write(2, "Error\n", 6);
		return (del_stack(a), 0);
	}
	if (ac == 2 && !split_fille(a, av))
	{
		write(2, "Error\n", 6);
		return (del_stack(a), 0);
	}
	if (ac > 2 && !direct_fille(a, av, ac))
	{
		write(2, "Error\n", 6);
		return (del_stack(a), 0);
	}
	return (1);
}
