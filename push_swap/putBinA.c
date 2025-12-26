/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putBinA.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:56:19 by boummi            #+#    #+#             */
/*   Updated: 2025/12/12 18:57:05 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putb_ina_two(t_stack **a, t_stack **b, t_stack *fix)
{
	int	index;
	int	*three;

	three = malloc(stack_lenght(*a) * sizeof(int));
	index = 0;
	while (fix)
	{
		three[index] = fix->data;
		index++;
		fix = fix->next;
	}
	while (*b)
	{
		while (index > 0 && three[index - 1] > (*b)->data)
		{
			rra(a);
			index--;
		}
		pa(a, b);
	}
	while (index-- > 0)
		rra(a);
	free(three);
}

void	putbina(t_stack **a, t_stack **b)
{
	t_stack	*fix;
	int		i;
	int		max;
	int		index;

	i = 0;
	max = -2147483648;
	fix = *b;
	while (fix)
	{
		if (fix->data >= max)
		{
			max = fix->data;
			index = i;
		}
		fix = fix->next;
		i++;
	}
	while (index <= i && index > 0)
	{
		rb(b);
		index--;
	}
	fix = *a;
	putb_ina_two(a, b, fix);
}
