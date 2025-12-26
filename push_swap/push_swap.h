/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boummi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:55:55 by boummi            #+#    #+#             */
/*   Updated: 2025/12/12 18:55:58 by boummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "unistd.h"
# include <stdlib.h>

typedef struct t_stack
{
	int				data;
	struct t_stack	*next;
}					t_stack;

t_stack				*ft_newstack(int data);

int					add_front(t_stack *a, int data);

void				del_first(t_stack **a);

int					add_first(t_stack **x, int data);

int					ft_swap(t_stack *a);

char				**ft_split(char const *str, char *c);

char				*ft_itoa(int n);

long				ft_atoi(const char *nptr);

int					ft_push(t_stack **x, t_stack **y);

int					rev_rotate(t_stack **x);

int					ft_rotat(t_stack **x);

void				del_stack(t_stack **x);

void				del_last(t_stack **x);

int					sort_all(t_stack **a, t_stack **b);

void				change_places(t_stack **a, t_stack **b, int *operat);

int					stack_lenght(t_stack *a);

int					lowest_r(t_stack *x, int n);

int					sa(t_stack *a);

int					sb(t_stack *b);

int					ss(t_stack *a, t_stack *b);

int					pa(t_stack **a, t_stack **b);

int					pb(t_stack **a, t_stack **b);

int					ra(t_stack **a);

int					rb(t_stack **b);

int					rr(t_stack **a, t_stack **b);

int					rra(t_stack **a);

int					rrb(t_stack **b);

int					rrr(t_stack **a, t_stack **b);

void				sort_less_x(t_stack **a, t_stack **b);

int					check_cases(t_stack **a, int ac, char **av);

void				putbina(t_stack **a, t_stack **b);

int					check_duplicate(t_stack *a);

int					is_sorted(t_stack *a);

void				free_garbage(char **str);

int					is_in_rules(char *op, t_stack **a, t_stack **b);

void				partition1(int *h_low_j_min, int *data);

void				partition2(int index, int *h_low_j_min, int *data);

int					allocation(char **ops, char *operations);
void				ft_lstdelone(t_stack *lst);
char				*get_next_line(int fd);
char				*ft_strnjoin(char *s1, char *s2);
int					ft_strlen(char const *s);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
#endif
