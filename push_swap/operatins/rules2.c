/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:19:59 by boummi            #+#    #+#             */
/*   Updated: 2025/12/12 19:20:23 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sa(t_stack *a)
{
	write(1, "sa\n", 3);
	return (ft_swap(a));
}

int	sb(t_stack *b)
{
	write(1, "sb\n", 3);
	return (ft_swap(b));
}

int	ss(t_stack *a, t_stack *b)
{
	write(1, "ss\n", 3);
	return (ft_swap(a) + ft_swap(b));
}

int	pa(t_stack **a, t_stack **b)
{
	write(1, "pa\n", 3);
	return (ft_push(a, b));
}

int	pb(t_stack **a, t_stack **b)
{
	write(1, "pb\n", 3);
	return (ft_push(b, a));
}
