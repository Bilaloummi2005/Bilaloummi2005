/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:15:08 by boummi            #+#    #+#             */
/*   Updated: 2025/12/12 19:16:42 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

t_stack	*ft_newstack(int data)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->data = data;
	a->next = NULL;
	return (a);
}

int	add_front(t_stack *a, int data)
{
	t_stack	*cur;
	t_stack	*new;

	if (!a)
		return (0);
	cur = a;
	while (cur->next)
		cur = cur->next;
	new = ft_newstack(data);
	if (!new)
		return (0);
	cur->next = new;
	return (1);
}

void	del_first(t_stack **a)
{
	t_stack	*next;

	next = (*a);
	*a = (*a)->next;
	free(next);
}

int	add_first(t_stack **x, int data)
{
	t_stack	*first;

	if (!*x)
	{
		*x = ft_newstack(data);
		return (1);
	}
	first = ft_newstack(data);
	if (!first)
		return (0);
	first->next = *x;
	*x = first;
	return (1);
}

void	del_stack(t_stack **lst)
{
	t_stack	*temp;

	if (!*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
