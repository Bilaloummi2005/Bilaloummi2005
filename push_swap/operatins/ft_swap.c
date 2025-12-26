/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:18:30 by boummi            #+#    #+#             */
/*   Updated: 2025/12/12 19:18:32 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_swap(t_stack *a)
{
	int		swap;
	t_stack	*fix;

	fix = a;
	if (!a || !a->next)
		return (1);
	if (a->next)
		a = a->next;
	else
		return (0);
	swap = fix->data;
	fix->data = a->data;
	a->data = swap;
	return (1);
}

int	ra(t_stack **a)
{
	write(1, "ra\n", 3);
	return (ft_rotat(a));
}

void	ft_lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}
