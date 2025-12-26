/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:13:26 by boummi            #+#    #+#             */
/*   Updated: 2025/12/12 19:13:27 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	half_operatons(int *operat, t_stack **a, t_stack **b)
{
	while (operat[0] < 0 && operat[1] < 0)
	{
		rrr(a, b);
		operat[0]++;
		operat[1]++;
	}
	while (operat[0] > 0 && operat[1] > 0)
	{
		rr(a, b);
		operat[0]--;
		operat[1]--;
	}
	while (operat[0] < 0)
	{
		rra(a);
		operat[0]++;
	}
}

void	other_half_operatons(int *operat, t_stack **a, t_stack **b)
{
	while (operat[0] > 0)
	{
		ra(a);
		operat[0]--;
	}
	while (operat[1] < 0)
	{
		rrb(b);
		operat[1]++;
	}
	while (operat[1] > 0)
	{
		rb(b);
		operat[1]--;
	}
}

void	opperations(t_stack **a, t_stack **b, int check)
{
	int	operat[2];

	while (*a)
	{
		if (check && stack_lenght(*a) == 41)
			break ;
		else if (!check && stack_lenght(*a) == 3)
			break ;
		change_places(a, b, operat);
		half_operatons(operat, a, b);
		other_half_operatons(operat, a, b);
		pb(a, b);
	}
}

int	sort_all(t_stack **a, t_stack **b)
{
	int	length;

	length = stack_lenght(*a);
	if (length > 300)
	{
		pb(a, b);
		pb(a, b);
		opperations(a, b, 1);
		return (1);
	}
	else
	{
		if (length <= 5)
		{
			sort_less_x(a, b);
			return (0);
		}
		pb(a, b);
		pb(a, b);
		opperations(a, b, 0);
		return (1);
	}
}
