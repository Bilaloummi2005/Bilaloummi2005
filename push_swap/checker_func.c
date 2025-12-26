/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:58:30 by boummi            #+#    #+#             */
/*   Updated: 2025/12/12 18:58:32 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fille_ops(char **ops)
{
	char	*operations;
	int		i;
	int		j;

	i = 0;
	operations = "sa,sb,ss,pa,pb,ra,rb,rr,rra,rrb,rrr";
	if (!allocation(ops, operations))
		return (0);
	while (i < 11)
	{
		j = 0;
		while (*operations && *operations != ',')
		{
			ops[i][j] = *operations;
			j++;
			operations++;
		}
		ops[i][j] = '\0';
		operations++;
		i++;
	}
	return (1);
}

int	is_equal(char *op, char *ops)
{
	int	i;

	i = 0;
	while (op[i + 1] && ops[i])
	{
		if (ops[i] != op[i])
			return (0);
		i++;
	}
	if (op[i + 1] || ops[i])
		return (0);
	return (1);
}

int	rr_op_2(char *op, char **ops, t_stack **a, t_stack **b)
{
	int	i;

	i = 7;
	if (is_equal(op, ops[i++]))
		return (ft_rotat(a) + ft_rotat(b));
	if (is_equal(op, ops[i++]))
		return (rev_rotate(a));
	if (is_equal(op, ops[i++]))
		return (rev_rotate(b));
	if (is_equal(op, ops[i++]))
		return (rev_rotate(a) + rev_rotate(b));
	return (0);
}

int	do_op(char *op, char **ops, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (is_equal(op, ops[i++]))
		return (ft_swap(*a));
	if (is_equal(op, ops[i++]))
		return (ft_swap(*b));
	if (is_equal(op, ops[i++]))
		return (ft_swap(*a) + ft_swap(*b));
	if (is_equal(op, ops[i++]))
		return (ft_push(a, b));
	if (is_equal(op, ops[i++]))
		return (ft_push(b, a));
	if (is_equal(op, ops[i++]))
		return (ft_rotat(a));
	if (is_equal(op, ops[i++]))
		return (ft_rotat(b));
	return (rr_op_2(op, ops, a, b));
}

int	is_in_rules(char *op, t_stack **a, t_stack **b)
{
	char	**ops;
	int		i;

	ops = malloc(sizeof(char *) * 12);
	if (!ops)
		return (0);
	i = 0;
	while (i < 12)
	{
		ops[i] = NULL;
		i++;
	}
	if (!fille_ops(ops))
	{
		free_garbage(ops);
		return (0);
	}
	if (!do_op(op, ops, a, b))
	{
		free_garbage(ops);
		return (0);
	}
	free_garbage(ops);
	return (1);
}
