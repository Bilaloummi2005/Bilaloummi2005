/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:00:31 by boummi            #+#    #+#             */
/*   Updated: 2025/12/12 19:00:52 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	allocation(char **ops, char *operations)
{
	int	i;
	int	j;

	i = 0;
	while (i < 11)
	{
		j = 0;
		while (*operations && *operations != ',')
		{
			j++;
			operations++;
		}
		ops[i] = malloc((1 + j) * sizeof(char));
		if (!ops[i])
		{
			free_garbage(ops);
			return (0);
		}
		operations++;
		i++;
	}
	return (1);
}

int	gnl_func(t_stack **a, t_stack **b)
{
	char	*op;

	while (0 == 0)
	{
		op = get_next_line(0);
		if (op == NULL)
			break ;
		if (!is_in_rules(op, a, b))
		{
			write(2, "Error\n", 6);
			free(op);
			return (del_stack(a), del_stack(b), 0);
		}
		free(op);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = NULL;
	if (!check_cases(&a, ac, av))
		return (del_stack(&a), del_stack(&b), 0);
	if (check_duplicate(a))
	{
		write(2, "Error\n", 6);
		return (del_stack(&a), del_stack(&b), 0);
	}
	if (!gnl_func(&a, &b))
		return (0);
	if (is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (del_stack(&a), del_stack(&b), 0);
}
