/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:19:14 by boummi            #+#    #+#             */
/*   Updated: 2025/12/12 19:19:17 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rev_rotate(t_stack **stk)
{
	t_stack	*first;
	t_stack	*last;

	first = *stk;
	last = *stk;
	if (!stk || !(*stk) || !(*stk)->next)
		return (1);
	while (last->next->next)
		last = last->next;
	last->next->next = first;
	*stk = last->next;
	last->next = NULL;
	return (1);
}

int	ft_rotat(t_stack **x)
{
	t_stack	*first;
	t_stack	*tail;

	if (!x || !*x || !(*x)->next)
		return (1);
	first = *x;
	*x = first->next;
	first->next = NULL;
	tail = *x;
	while (tail->next)
		tail = tail->next;
	tail->next = first;
	return (1);
}

void	del_last(t_stack **x)
{
	t_stack	*cur;
	t_stack	*prev;

	if (!x || !*x)
		return ;
	if (!(*x)->next)
	{
		free(*x);
		*x = NULL;
		return ;
	}
	prev = NULL;
	cur = *x;
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = NULL;
	free(cur);
}
