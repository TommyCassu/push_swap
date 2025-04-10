/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassu <tcassu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:26:36 by tcassu            #+#    #+#             */
/*   Updated: 2025/04/10 13:42:51 by tcassu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack_node **stack)
{
	int	val_0;
	int	val_1;
	int	val_3;

	val_0 = (*stack)->value;
	val_1 = (*stack)->next->value;
	val_3 = (*stack)->next->next->value;
	if (val_0 == value_min_lst(*stack) && val_1 == value_max_lst(*stack))
	{
		sa(stack);
		ra(stack);
	}
	else if (val_1 == value_min_lst(*stack) && val_3 == value_max_lst(*stack))
		sa(stack);
	else if (val_3 == value_min_lst(*stack) && val_1 == value_max_lst(*stack))
		rra(stack);
	else if (val_1 == value_min_lst(*stack) && val_0 == value_max_lst(*stack))
		ra(stack);
	else
	{
		sa(stack);
		rra(stack);
	}
}
