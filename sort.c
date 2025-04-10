/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassu <tcassu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:45:40 by tcassu            #+#    #+#             */
/*   Updated: 2025/04/10 14:10:56 by tcassu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_final(t_stack_node **stack)
{
	int	rotation_sens;
	int	rotations;

	rotation_sens = value_outside_lst(*stack, value_min_lst(*stack));
	if (rotation_sens < 0)
	{
		rotations = -rotation_sens;
		while (rotations--)
			rra(stack);
	}
	else
	{
		rotations = rotation_sens;
		while (rotations--)
			ra(stack);
	}
}

int	verif_list_sort(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_big(t_stack_node **a)
{
	int				nb_rotation_a;
	int				nb_rotation_b;
	t_stack_node	*b;

	b = NULL;
	while (lstsize(*a) > 3)
		pb(a, &b);
	if (!verif_list_sort(*a))
		sort_3(a);
	while (lstsize(b))
	{
		nb_rotation_a = 0;
		nb_rotation_b = 0;
		calculate_rotation(*a, b, &nb_rotation_a, &nb_rotation_b);
		if ((nb_rotation_a >= 0 && nb_rotation_b >= 0)
			|| (nb_rotation_a <= 0 && nb_rotation_b <= 0))
			rotation_same_way(a, &b, nb_rotation_a, nb_rotation_b);
		else
			rotation_different_way(a, &b, nb_rotation_a, nb_rotation_b);
		pa(a, &b);
	}
}

void	sort(t_stack_node **stack)
{
	if (lstsize(*stack) == 2)
		sa(stack);
	else if (lstsize(*stack) == 3)
		sort_3(stack);
	else
		sort_big(stack);
	sort_final(stack);
}
