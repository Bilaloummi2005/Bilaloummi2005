/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:11:51 by boummi            #+#    #+#             */
/*   Updated: 2025/11/26 17:41:43 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

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

// int	rb(stack **b)
// {
// 	printf("rb\n");
// 	return (ft_rotat(b));
// }

// int	rr(stack **a, stack **b)
// {
// 	printf("rr\n");
// 	return (ft_rotat(a) + ft_rotat(b));
// }

// int	rra(stack **a)
// {
// 	printf("rra\n");
// 	return (rev_rotate(a));
// }

// int	rrb(stack **b)
// {
// 	printf("rrb\n");
// 	return (rev_rotate(b));
// }

// int	rrr(stack **a, stack **b)
// {
// 	printf("rrr\n");
// 	return (rev_rotate(a) + rev_rotate(b));
// }

// int	look_for_smallest_two(int *index_max, int *index_min, int *index)
// {
// 	if (*index_min <= *index_max + 1 || *index_max < 0)
// 		return (*index_min);
// 	else
// 		return (*index_max + 1);
// }

// int	look_for_smallest(int *index, int *index_max, int *index_min)
// {
// 	if (*index_max > *index / 2 && *index_min < *index / 2)
// 	{
// 		if (*index_min < *index - *index_max - 1 && *index_max > 0)
// 			return (*index_min);
// 		else
// 			return (-(*index - *index_max - 1));
// 	}
// 	else if (*index_min > *index / 2 && *index_max < *index / 2)
// 	{
// 		if ((*index_max + 1 > *index - *index_min || *index_max == -2147483648)
// 			&& *index - *index_min > 0)
// 			return (-(*index - *index_min));
// 		else
// 			return (*index_max + 1);
// 	}
// 	else if (*index_min > *index / 2 && *index_max > *index / 2)
// 	{
// 		if (*index - *index_max - 1 > *index - *index_min
// 			&& *index_min != 2147483647)
// 			return (-(*index - *index_min));
// 		else
// 			return (-(*index - *index_max - 1));
// 	}
// 	else
// 		return (look_for_smallest_two(index_max, index_min, index));
// }

// int	lowest_r(stack *x, int n)
// {
// 	int		indexs[5];
// 	stack	*fix;

// 	fix = x;
// 	indexs[3] = 2147483647;
// 	indexs[4] = -2147483648;
// 	indexs[1] = 2147483647;
// 	indexs[2] = -2147483648;
// 	indexs[0] = 0;
// 	while (x)
// 	{
// 		if (n - x->data <= indexs[3] && n - x->data >= 0)
// 		{
// 			indexs[1] = indexs[0];
// 			indexs[3] = n - x->data;
// 		}
// 		if (n - x->data >= indexs[4] && n - x->data <= 0)
// 		{
// 			indexs[2] = indexs[0];
// 			indexs[4] = n - x->data;
// 		}
// 		indexs[0]++;
// 		x = x->next;
// 	}
// 	return (look_for_smallest(indexs, indexs + 2, indexs + 1));
// }

// int	stack_lenght(stack *a)
// {
// 	stack	*fix;
// 	int		i;

// 	fix = a;
// 	i = 0;
// 	while (a)
// 	{
// 		i++;
// 		a = a->next;
// 	}
// 	a = fix;
// 	return (i);
// }

// void	low_operation_two(int *h_low_j_min, int index, int *data)
// {
// 	if (h_low_j_min[0] <= index / 2)
// 	{
// 		if (data[h_low_j_min[0]] < 0 && h_low_j_min[0]
// 			- data[h_low_j_min[0]] < h_low_j_min[1])
// 		{
// 			h_low_j_min[3] = data[h_low_j_min[0]];
// 			h_low_j_min[2] = h_low_j_min[0];
// 			h_low_j_min[1] = h_low_j_min[0] - data[h_low_j_min[0]];
// 		}
// 		if (data[h_low_j_min[0]] >= 0)
// 		{
// 			if (h_low_j_min[0] > data[h_low_j_min[0]]
// 				&& h_low_j_min[0] < h_low_j_min[1])
// 			{
// 				h_low_j_min[1] = h_low_j_min[0];
// 				h_low_j_min[3] = data[h_low_j_min[0]];
// 				h_low_j_min[2] = h_low_j_min[0];
// 			}
// 			else if (h_low_j_min[0] <= data[h_low_j_min[0]]
// 				&& data[h_low_j_min[0]] < h_low_j_min[1])
// 			{
// 				h_low_j_min[1] = data[h_low_j_min[0]];
// 				h_low_j_min[3] = data[h_low_j_min[0]];
// 				h_low_j_min[2] = h_low_j_min[0];
// 			}
// 		}
// 	}
// }

// void	low_operation_three(int *h_low_j_min, int index, int *data)
// {
// 	if (h_low_j_min[0] > index / 2)
// 	{
// 		if (data[h_low_j_min[0]] < 0)
// 		{
// 			if (index - h_low_j_min[0] > -data[h_low_j_min[0]] && index
// 				- h_low_j_min[0] <= h_low_j_min[1])
// 			{
// 				h_low_j_min[3] = data[h_low_j_min[0]];
// 				h_low_j_min[2] = h_low_j_min[0];
// 				h_low_j_min[1] = index - h_low_j_min[0];
// 			}
// 			if (-data[h_low_j_min[0]] > index - h_low_j_min[0] &&
// 				-data[h_low_j_min[0]] <= h_low_j_min[1])
// 			{
// 				h_low_j_min[3] = data[h_low_j_min[0]];
// 				h_low_j_min[2] = h_low_j_min[0];
// 				h_low_j_min[1] = -data[h_low_j_min[0]];
// 			}
// 		}
// 		if (data[h_low_j_min[0]] >= 0 && index - h_low_j_min[0]
// 			+ data[h_low_j_min[0]] <= h_low_j_min[1])
// 		{
// 			h_low_j_min[3] = data[h_low_j_min[0]];
// 			h_low_j_min[2] = h_low_j_min[0];
// 			h_low_j_min[1] = index - h_low_j_min[0] + data[h_low_j_min[0]];
// 		}
// 	}
// }

// int	*low_operation(int *data, int index)
// {
// 	int	h_low_j_min[4];
// 	int	*min_o;

// 	min_o = malloc(2 * sizeof(int));
// 	h_low_j_min[0] = 0;
// 	h_low_j_min[1] = 2147483647;
// 	h_low_j_min[2] = 0;
// 	h_low_j_min[3] = 2147483647;
// 	while (h_low_j_min[0] < index)
// 	{
// 		low_operation_two(h_low_j_min, index, data);
// 		low_operation_three(h_low_j_min, index, data);
// 		h_low_j_min[0]++;
// 	}
// 	if (h_low_j_min[2] > h_low_j_min[0] / 2)
// 	{
// 		min_o[0] = h_low_j_min[2] - h_low_j_min[0];
// 		min_o[1] = h_low_j_min[3];
// 		free(data);
// 		return (min_o);
// 	}
// 	min_o[0] = h_low_j_min[2];
// 	min_o[1] = h_low_j_min[3];
// 	free(data);
// 	return (min_o);
// }

// int	*change_places(stack **a, stack **b)
// {
// 	int		index;
// 	int		lowest;
// 	int		*data;
// 	stack	*fix;
// 	int		k;

// 	lowest = 2147483647;
// 	index = 0;
// 	fix = *a;
// 	data = malloc((sizeof(int)) * stack_lenght(fix));
// 	while (fix)
// 	{
// 		data[index] = lowest_r(*b, fix->data);
// 		k = data[index];
// 		index++;
// 		fix = fix->next;
// 	}
// 	return (low_operation(data, index));
// }

// void	putb_ina_two(stack **a, stack **b, stack *fix)
// {
// 	int	index;
// 	int	*three;

// 	three = malloc(stack_lenght(*a) * sizeof(int));
// 	index = 0;
// 	while (fix)
// 	{
// 		three[index] = fix->data;
// 		index++;
// 		fix = fix->next;
// 	}
// 	while (*b)
// 	{
// 		while (index > 0 && three[index - 1] > (*b)->data)
// 		{
// 			rra(a);
// 			index--;
// 		}
// 		pa(a, b);
// 	}
// 	while (index > 0)
// 	{
// 		rra(a);
// 		index--;
// 	}
// }
// void	putbina(stack **a, stack **b)
// {
// 	stack	*fix;
// 	int		i;
// 	int		max;
// 	int		index;

// 	i = 0;
// 	max = -2147483648;
// 	fix = *b;
// 	while (fix)
// 	{
// 		if (fix->data >= max)
// 		{
// 			max = fix->data;
// 			index = i;
// 		}
// 		fix = fix->next;
// 		i++;
// 	}
// 	while (index <= i && index > 0)
// 	{
// 		rb(b);
// 		index--;
// 	}
// 	fix = *a;
// 	putb_ina_two(a, b, fix);
// }

// int	max_index_ten(stack **a)
// {
// 	stack	*head;
// 	int		i;
// 	int		index;
// 	int		max;

// 	i = 0;
// 	head = *a;
// 	max = head->data;
// 	index = 0;
// 	while (head)
// 	{
// 		if (max < head->data)
// 		{
// 			max = head->data;
// 			index = i;
// 		}
// 		head = head->next;
// 		i++;
// 	}
// 	if (index > i / 2)
// 		return (index - i);
// 	return (index);
// }

// void	sort_three(stack **a)
// {
// 	if ((*a)->data > (*a)->next->next->data
// 		&& (*a)->next->data < (*a)->next->next->data)
// 		ra(a);
// 	if ((*a)->data > (*a)->next->next->data && (*a)->data < (*a)->next->data)
// 		rra(a);
// 	if ((*a)->data < (*a)->next->data
// 		&& (*a)->next->data > (*a)->next->next->data)
// 	{
// 		sa(*a);
// 		ra(a);
// 	}
// 	if ((*a)->data > (*a)->next->data
// 		&& (*a)->next->data > (*a)->next->next->data)
// 	{
// 		sa(*a);
// 		rra(a);
// 	}
// 	if ((*a)->data > (*a)->next->data && (*a)->data < (*a)->next->next->data)
// 		sa(*a);
// }

// int	chiker(int ac, char **av)
// {
// 	int		i;
// 	int		j;
// 	char	**args;

// 	i = 1;
// 	args = av;
// 	if (ac == 2)
// 	{
// 		args = ft_split(av[1], " 	");
// 		i = 0;
// 	}
// 	while (args[i])
// 	{
// 		j = 0;
// 		if (args[i][j] == '-' && args[i][j + 1])
// 			j++;
// 		while (args[i][j])
// 		{
// 			if (!(args[i][j] >= '0' && args[i][j] <= '9'))
// 				return (0);
// 			j++; // ghanerja3 kanwa3dek
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// int	split_fille(stack **a, char **av)
// {
// 	stack	*fixa;
// 	char	**args;
// 	int		j;

// 	fixa = *a;
// 	j = 1;
// 	if (!av[1][0])
// 		return (1);
// 	args = ft_split(av[1], " 	");
// 	if (ft_atoi(args[0]) > 2147483647 || (ft_atoi(args[0]) < -2147483648))
// 		return (0);
// 	*a = ft_newstack(ft_atoi(args[0]));
// 	while (args[j] != NULL)
// 	{
// 		if (ft_atoi(args[j]) > 2147483647 || (ft_atoi(args[j]) < -2147483648))
// 			return (0);
// 		add_front(*a, ft_atoi(args[j]));
// 		j++;
// 	}
// 	return (1);
// }

// int	direct_fille(stack **a, char **av, int ac)
// {
// 	int	i;

// 	i = 2;
// 	if (ft_atoi(av[1]) > 2147483647 || (ft_atoi(av[1]) < -2147483648))
// 		return (0);
// 	*a = ft_newstack(ft_atoi(av[1]));
// 	while (i < ac)
// 	{
// 		if (ft_atoi(av[i]) > 2147483647 || (ft_atoi(av[i]) < -2147483648))
// 			return (0);
// 		add_front(*a, ft_atoi(av[i]));
// 		i++;
// 	}
// 	return (1);
// }

// void	op_for_x(stack **a, stack **b, int op)
// {
// 	while (op > 0)
// 	{
// 		ra(a);
// 		op--;
// 	}
// 	while (op < 0)
// 	{
// 		rra(a);
// 		op++;
// 	}
// }

// void	sort_x(stack **a, stack **b)
// {
// 	int		min;
// 	int		index;
// 	int		i;
// 	stack	*head;

// 	head = *a;
// 	i = 0;
// 	min = head->data;
// 	while (head)
// 	{
// 		if (min >= head->data)
// 		{
// 			min = head->data;
// 			index = i;
// 		}
// 		i++;
// 		head = head->next;
// 	}
// 	if (index > 2)
// 		op_for_x(a, b, index - i);
// 	else
// 		op_for_x(a, b, index);
// 	pb(a, b);
// }

// void	sort_mor_than_three(stack **a, stack **b, int len)
// {
// 	int	h;

// 	h = 0;
// 	while (len > 3)
// 	{
// 		sort_x(a, b);
// 		len--;
// 		h++;
// 	}
// 	sort_three(a);
// 	while (h > 0)
// 	{
// 		pa(a, b);
// 		h--;
// 	}
// }

// void	sort_less_x(stack **a, stack **b)
// {
// 	int	len;
// 	int	h;

// 	h = 0;
// 	len = stack_lenght(*a);
// 	if (!(*a) || !(*a)->next)
// 		return ;
// 	if (len == 2)
// 	{
// 		if ((*a)->data > (*a)->next->data)
// 			rra(a);
// 		return ;
// 	}
// 	if (len == 3)
// 	{
// 		sort_three(a);
// 		return ;
// 	}
// 	sort_mor_than_three(a, b, len);
// }

// int	is_sorted(stack *a)
// {
// 	stack	*head;

// 	head = a;
// 	if (!head)
// 		return (1);
// 	while (head->next)
// 	{
// 		if (head->next->data > head->data)
// 			head = head->next;
// 		else
// 			return (0);
// 	}
// 	return (1);
// }

// int	check_duplicate(stack *a)
// {
// 	stack	*head;
// 	stack	*fix;
// 	int		x;

// 	fix = a;
// 	while (fix)
// 	{
// 		head = fix->next;
// 		x = fix->data;
// 		while (head)
// 		{
// 			if (head->data != x)
// 				head = head->next;
// 			else
// 				return (1);
// 		}
// 		fix = fix->next;
// 	}
// 	return (0);
// }

// int	check_cases(stack **a, stack **b, int ac, char **av)
// {
// 	if (ac <= 1)
// 	{
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	if (!chiker(ac, av))
// 	{
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	if (ac == 2 && !split_fille(a, av))
// 	{
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	if (ac > 2 && !direct_fille(a, av, ac))
// 	{
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	return (1);
// }

// void	half_operatons(int *operat, stack **a, stack **b)
// {
// 	while (operat[0] < 0 && operat[1] < 0)
// 	{
// 		rrr(a, b);
// 		operat[0]++;
// 		operat[1]++;
// 	}
// 	while (operat[0] > 0 && operat[1] > 0)
// 	{
// 		rr(a, b);
// 		operat[0]--;
// 		operat[1]--;
// 	}
// 	while (operat[0] < 0)
// 	{
// 		rra(a);
// 		operat[0]++;
// 	}
// }

// void	other_half_operatons(int *operat, stack **a, stack **b)
// {
// 	while (operat[0] > 0)
// 	{
// 		ra(a);
// 		operat[0]--;
// 	}
// 	while (operat[1] < 0)
// 	{
// 		rrb(b);
// 		operat[1]++;
// 	}
// 	while (operat[1] > 0)
// 	{
// 		rb(b);
// 		operat[1]--;
// 	}
// }

// void	opperations(stack **a, stack **b, int check)
// {
// 	int	*operat;

// 	while (*a)
// 	{
// 		if (check && stack_lenght(*a) == 41)
// 			break ;
// 		else if (!check && stack_lenght(*a) == 3)
// 			break ;
// 		operat = change_places(a, b);
// 		half_operatons(operat, a, b);
// 		other_half_operatons(operat, a, b);
// 		pb(a, b);
// 	}
// }

// int	sort_all(stack **a, stack **b)
// {
// 	int	length;

// 	length = stack_lenght(*a);
// 	if (length > 300)
// 	{
// 		pb(a, b);
// 		pb(a, b);
// 		opperations(a, b, 1);
// 		return (1);
// 	}
// 	else
// 	{
// 		if (length <= 5)
// 		{
// 			sort_less_x(a, b);
// 			return (0);
// 		}
// 		pb(a, b);
// 		pb(a, b);
// 		opperations(a, b, 0);
// 		return (1);
// 	}
// }

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = NULL;
	if (!check_cases(&a, ac, av))
		return (del_stack(&a), del_stack(&b), 0);
	if (check_duplicate(a))
	{
		write(2, "Error\n", 6);
		return (del_stack(&a), del_stack(&b), 0);
	}
	if (is_sorted(a))
		return (del_stack(&a), del_stack(&b), 0);
	if (!sort_all(&a, &b))
	{
		return (del_stack(&a), del_stack(&b), 0);
	}
	sort_less_x(&a, &b);
	putbina(&a, &b);
	return (del_stack(&a), del_stack(&b), 0);
}
