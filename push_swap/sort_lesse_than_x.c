/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lesse_than_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:57:27 by boummi            #+#    #+#             */
/*   Updated: 2025/12/12 18:57:29 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	if ((*a)->data > (*a)->next->next->data
		&& (*a)->next->data < (*a)->next->next->data)
		ra(a);
	if ((*a)->data > (*a)->next->next->data && (*a)->data < (*a)->next->data)
		rra(a);
	if ((*a)->data < (*a)->next->data
		&& (*a)->next->data > (*a)->next->next->data)
	{
		sa(*a);
		ra(a);
	}
	if ((*a)->data > (*a)->next->data
		&& (*a)->next->data > (*a)->next->next->data)
	{
		sa(*a);
		rra(a);
	}
	if ((*a)->data > (*a)->next->data && (*a)->data < (*a)->next->next->data)
		sa(*a);
}

void	op_for_x(t_stack **a, int op)
{
	while (op > 0)
	{
		ra(a);
		op--;
	}
	while (op < 0)
	{
		rra(a);
		op++;
	}
}

void	sort_x(t_stack **a, t_stack **b)
{
	int		min;
	int		index;
	int		i;
	t_stack	*head;

	head = *a;
	i = 0;
	min = head->data;
	while (head)
	{
		if (min >= head->data)
		{
			min = head->data;
			index = i;
		}
		i++;
		head = head->next;
	}
	if (index > 2)
		op_for_x(a, index - i);
	else
		op_for_x(a, index);
	pb(a, b);
}

void	sort_mor_than_three(t_stack **a, t_stack **b, int len)
{
	int	h;

	h = 0;
	while (len > 3)
	{
		sort_x(a, b);
		len--;
		h++;
	}
	sort_three(a);
	while (h > 0)
	{
		pa(a, b);
		h--;
	}
}

void	sort_less_x(t_stack **a, t_stack **b)
{
	int	len;
	
	len = stack_lenght(*a);
	if (!(*a) || !(*a)->next)
		return ;
	if (len == 2)
	{
		if ((*a)->data > (*a)->next->data)
			rra(a);
		return ;
	}
	if (len == 3)
	{
		sort_three(a);
		return ;
	}
	sort_mor_than_three(a, b, len);
}
