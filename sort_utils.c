/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassu <tcassu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:57:20 by tcassu            #+#    #+#             */
/*   Updated: 2025/04/10 14:27:35 by tcassu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_rotation(t_stack_node *stack_a,
		t_stack_node *stack_b, int *a, int *b)
{
	int			i;
	int			j;
	int			num;
	int			x;
	const int	size_b = lstsize(stack_b);

	x = 0;
	while (stack_b)
	{
		num = stack_b->value;
		if (num < value_min_lst(stack_a) || num > value_max_lst(stack_a))
			i = value_outside_lst(stack_a, num);
		else
			i = value_inside_lst(stack_a, num);
		j = x;
		if (x >= (size_b + 1) / 2)
			j = -1 * (size_b - x);
		if (x == 0 || count_rotate(*a, *b) > count_rotate(i, j))
		{
			*a = i;
			*b = j;
		}
		stack_b = stack_b->next;
		x++;
	}
}

void	rotate_up(t_stack_node **stack_a, t_stack_node **stack_b, int a, int b)
{
	int	min_rot;
	int	remaining_a;
	int	remaining_b;

	min_rot = min(ft_abs(a), ft_abs(b));
	while (min_rot--)
		rr(stack_a, stack_b);
	if (ft_abs(a) <= ft_abs(b))
	{
		remaining_b = ft_abs(b) - ft_abs(a);
		while (remaining_b--)
			rb(stack_b);
	}
	else
	{
		remaining_a = ft_abs(a) - ft_abs(b);
		while (remaining_a--)
			ra(stack_a);
	}
}

void	rotate_down(t_stack_node **stack_a,
	t_stack_node **stack_b, int a, int b)
{
	int	min_rot;
	int	remaining_a;
	int	remaining_b;

	min_rot = min(ft_abs(a), ft_abs(b));
	while (min_rot--)
		rrr(stack_a, stack_b);
	if (ft_abs(a) <= ft_abs(b))
	{
		remaining_b = ft_abs(b) - ft_abs(a);
		while (remaining_b--)
			rrb(stack_b);
	}
	else
	{
		remaining_a = ft_abs(a) - ft_abs(b);
		while (remaining_a--)
			rra(stack_a);
	}
}

void	rotation_same_way(t_stack_node **stack_a,
	t_stack_node **stack_b, int a, int b)
{
	if (a >= 0 && b >= 0)
		rotate_up(stack_a, stack_b, a, b);
	else
		rotate_down(stack_a, stack_b, a, b);
}

void	rotation_different_way(t_stack_node **stack_a,
		t_stack_node **stack_b, int a, int b)
{
	if (a > 0 && b < 0)
	{
		while (a--)
			ra(stack_a);
		while (b++)
			rrb(stack_b);
	}
	else
	{
		while (a++)
			rra(stack_a);
		while (b--)
			rb(stack_b);
	}
}
