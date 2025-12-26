/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:13:54 by boummi            #+#    #+#             */
/*   Updated: 2025/12/12 19:13:57 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_lenght(t_stack *a)
{
	t_stack	*fix;
	int		i;

	fix = a;
	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	a = fix;
	return (i);
}

void	low_operation_two(int *h_low_j_min, int index, int *data)
{
	if (h_low_j_min[0] <= index / 2)
	{
		if (data[h_low_j_min[0]] < 0 && h_low_j_min[0]
			- data[h_low_j_min[0]] < h_low_j_min[1])
		{
			h_low_j_min[3] = data[h_low_j_min[0]];
			h_low_j_min[2] = h_low_j_min[0];
			h_low_j_min[1] = h_low_j_min[0] - data[h_low_j_min[0]];
		}
		if (data[h_low_j_min[0]] >= 0)
			partition1(h_low_j_min, data);
	}
}

void	low_operation_three(int *h_low_j_min, int index, int *data)
{
	if (h_low_j_min[0] > index / 2)
	{
		if (data[h_low_j_min[0]] < 0)
		{
			partition2(index, h_low_j_min, data);
		}
		if (data[h_low_j_min[0]] >= 0 && index - h_low_j_min[0]
			+ data[h_low_j_min[0]] <= h_low_j_min[1])
		{
			h_low_j_min[3] = data[h_low_j_min[0]];
			h_low_j_min[2] = h_low_j_min[0];
			h_low_j_min[1] = index - h_low_j_min[0] + data[h_low_j_min[0]];
		}
	}
}

void	low_operation(int *data, int index, int *min_o)
{
	int	h_low_j_min[4];

	h_low_j_min[0] = 0;
	h_low_j_min[1] = 2147483647;
	h_low_j_min[2] = 0;
	h_low_j_min[3] = 2147483647;
	while (h_low_j_min[0] < index)
	{
		low_operation_two(h_low_j_min, index, data);
		low_operation_three(h_low_j_min, index, data);
		h_low_j_min[0]++;
	}
	if (h_low_j_min[2] > h_low_j_min[0] / 2)
	{
		min_o[0] = h_low_j_min[2] - h_low_j_min[0];
		min_o[1] = h_low_j_min[3];
		free(data);
		return ;
	}
	min_o[0] = h_low_j_min[2];
	min_o[1] = h_low_j_min[3];
	free(data);
}

void	change_places(t_stack **a, t_stack **b, int *min_op)
{
	int		index;
	int		*data;
	t_stack	*fix;
	

	index = 0;
	fix = *a;
	data = malloc((sizeof(int)) * stack_lenght(fix));
	while (fix)
	{
		data[index] = lowest_r(*b, fix->data);
		
		index++;
		fix = fix->next;
	}
	low_operation(data, index, min_op);
}
