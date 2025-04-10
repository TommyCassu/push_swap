/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassu <tcassu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:51:47 by tcassu            #+#    #+#             */
/*   Updated: 2025/04/10 14:26:53 by tcassu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_rotate(int a, int b)
{
	if ((a >= 0 && b >= 0) || (a <= 0 && b <= 0))
		return (min(ft_abs(a), ft_abs(b)) + ft_abs(a - b));
	return (ft_abs(a) + ft_abs(b));
}

int	value_min_lst(t_stack_node *stack)
{
	int	min;
	int	num;

	min = stack->value;
	while (stack)
	{
		num = stack->value;
		if (min > num)
			min = num;
		stack = stack->next;
	}
	return (min);
}

int	value_max_lst(t_stack_node *stack)
{
	int	max;
	int	num;

	max = stack->value;
	while (stack)
	{
		num = stack->value;
		if (max < num)
			max = num;
		stack = stack->next;
	}
	return (max);
}

int	value_inside_lst(t_stack_node *stack, int num)
{
	int			current;
	int			next;
	int			ret;
	const int	size = lstsize(stack);

	ret = 1;
	while (stack->next)
	{
		current = stack->value;
		next = stack->next->value;
		if (num > current && num < next)
			break ;
		++ret;
		stack = stack->next;
	}
	if (ret >= (size + 1) / 2)
		ret = -1 * (size - ret);
	return (ret);
}

int	value_outside_lst(t_stack_node *stack, int num)
{
	int			ret;
	int			x;
	const int	size = lstsize(stack);

	ret = 0;
	x = value_max_lst(stack);
	if (num <= value_min_lst(stack))
		x = value_min_lst(stack);
	else
		++ret;
	while (stack)
	{
		if (stack->value == x)
			break ;
		++ret;
		stack = stack->next;
	}
	if (ret >= (size + 1) / 2)
		ret = -1 * (size - ret);
	return (ret);
}
