/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassu <tcassu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:32 by tcassu            #+#    #+#             */
/*   Updated: 2025/04/10 13:59:56 by tcassu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
}				t_stack_node;

/* Sort */
void			sort(t_stack_node **stack);
void			calculate_rotation(t_stack_node *stack_a,
					t_stack_node *stack_b, int *a, int *b);
void			rotation_same_way(t_stack_node **stack_a,
					t_stack_node **stack_b, int a, int b);
void			rotation_different_way(t_stack_node **stack_a,
					t_stack_node **stack_b, int a, int b);
void			sort_3(t_stack_node **stack);
int				value_outside_lst(t_stack_node *stack, int num);
int				count_rotate(int a, int b);
/* Sort utils */
int				value_inside_lst(t_stack_node *stack, int num);
int				value_outside_lst(t_stack_node *stack, int num);
int				value_min_lst(t_stack_node *stack);
int				value_max_lst(t_stack_node *stack);
int				ft_abs(int c);
int				min(int a, int b);
/* Utils*/
void			lstadd_back(t_stack_node **lst, t_stack_node *new);
t_stack_node	*lstlast(t_stack_node *lst);
int				lstsize(t_stack_node *lst);

/* commands */
void			pb(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
#endif