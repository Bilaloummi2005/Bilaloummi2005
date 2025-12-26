/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:19:34 by boummi            #+#    #+#             */
/*   Updated: 2025/12/12 19:20:29 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int	sa(stack *a)
// {
// 	printf("sa\n");
// 	return (ft_swap(a));
// }

// int	sb(stack *b)
// {
// 	return (ft_swap(b));
// }

// int	ss(stack *a, stack *b)
// {
// 	return (ft_swap(a) + ft_swap(b));
// }

// int	pa(stack **a, stack **b)
// {
// 	printf("pa\n");
// 	return (ft_push(a, b));
// }

// int	pb(stack **a, stack **b)
// {
// 	printf("pb\n");
// 	return (ft_push(b, a));
// }

// int	ra(stack **a)
// {
// 	printf("ra\n");
// 	return (ft_rotat(a));
// }

int	rb(t_stack **b)
{
	write(1, "rb\n", 3);
	return (ft_rotat(b));
}

int	rr(t_stack **a, t_stack **b)
{
	write(1, "rr\n", 3);
	return (ft_rotat(a) + ft_rotat(b));
}

int	rra(t_stack **a)
{
	write(1, "rra\n", 4);
	return (rev_rotate(a));
}

int	rrb(t_stack **b)
{
	write(1, "rrb\n", 4);
	return (rev_rotate(b));
}

int	rrr(t_stack **a, t_stack **b)
{
	write(1, "rrr\n", 4);
	return (rev_rotate(a) + rev_rotate(b));
}
