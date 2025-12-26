/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:00:10 by boummi            #+#    #+#             */
/*   Updated: 2025/12/12 19:00:12 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_garbage(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	is_sorted(t_stack *a)
{
	t_stack	*head;

	head = a;
	if (!head)
		return (1);
	while (head->next)
	{
		if (head->next->data > head->data)
			head = head->next;
		else
			return (0);
	}
	return (1);
}

int	check_duplicate(t_stack *a)
{
	t_stack	*head;
	t_stack	*fix;
	int		x;

	fix = a;
	while (fix)
	{
		head = fix->next;
		x = fix->data;
		while (head)
		{
			if (head->data != x)
				head = head->next;
			else
				return (1);
		}
		fix = fix->next;
	}
	return (0);
}
