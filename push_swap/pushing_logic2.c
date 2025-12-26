/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_logic2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:14:19 by boummi            #+#    #+#             */
/*   Updated: 2025/12/12 19:14:24 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition1(int *h_low_j_min, int *data)
{
	if (h_low_j_min[0] > data[h_low_j_min[0]]
		&& h_low_j_min[0] < h_low_j_min[1])
	{
		h_low_j_min[1] = h_low_j_min[0];
		h_low_j_min[3] = data[h_low_j_min[0]];
		h_low_j_min[2] = h_low_j_min[0];
	}
	else if (h_low_j_min[0] <= data[h_low_j_min[0]]
		&& data[h_low_j_min[0]] < h_low_j_min[1])
	{
		h_low_j_min[1] = data[h_low_j_min[0]];
		h_low_j_min[3] = data[h_low_j_min[0]];
		h_low_j_min[2] = h_low_j_min[0];
	}
}

void	partition2(int index, int *h_low_j_min, int *data)
{
	if (index - h_low_j_min[0] > -data[h_low_j_min[0]] && index
		- h_low_j_min[0] <= h_low_j_min[1])
	{
		h_low_j_min[3] = data[h_low_j_min[0]];
		h_low_j_min[2] = h_low_j_min[0];
		h_low_j_min[1] = index - h_low_j_min[0];
	}
	if (-data[h_low_j_min[0]] > index - h_low_j_min[0]
		&& - data[h_low_j_min[0]] <= h_low_j_min[1])
	{
		h_low_j_min[3] = data[h_low_j_min[0]];
		h_low_j_min[2] = h_low_j_min[0];
		h_low_j_min[1] = -data[h_low_j_min[0]];
	}
}

int	look_for_smallest_two(int *index_max, int *index_min)
{
	if (*index_min <= *index_max + 1 || *index_max < 0)
		return (*index_min);
	else
		return (*index_max + 1);
}

int	look_for_smallest(int *index, int *index_max, int *index_min)
{
	if (*index_max > *index / 2 && *index_min < *index / 2)
	{
		if (*index_min < *index - *index_max - 1 && *index_max > 0)
			return (*index_min);
		else
			return (-(*index - *index_max - 1));
	}
	else if (*index_min > *index / 2 && *index_max < *index / 2)
	{
		if ((*index_max + 1 > *index - *index_min || *index_max == -2147483648)
			&& *index - *index_min > 0)
			return (-(*index - *index_min));
		else
			return (*index_max + 1);
	}
	else if (*index_min > *index / 2 && *index_max > *index / 2)
	{
		if (*index - *index_max - 1 > *index - *index_min
			&& *index_min != 2147483647)
			return (-(*index - *index_min));
		else
			return (-(*index - *index_max - 1));
	}
	else
		return (look_for_smallest_two(index_max, index_min));
}

int	lowest_r(t_stack *x, int n)
{
	int		indexs[5];

	indexs[3] = 2147483647;
	indexs[4] = -2147483648;
	indexs[1] = 2147483647;
	indexs[2] = -2147483648;
	indexs[0] = 0;
	while (x)
	{
		if (n - x->data <= indexs[3] && n - x->data >= 0)
		{
			indexs[1] = indexs[0];
			indexs[3] = n - x->data;
		}
		if (n - x->data >= indexs[4] && n - x->data <= 0)
		{
			indexs[2] = indexs[0];
			indexs[4] = n - x->data;
		}
		indexs[0]++;
		x = x->next;
	}
	return (look_for_smallest(indexs, indexs + 2, indexs + 1));
}
