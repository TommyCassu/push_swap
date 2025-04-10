/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassu <tcassu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:44:51 by tcassu            #+#    #+#             */
/*   Updated: 2025/04/10 13:49:50 by tcassu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack_node **source, t_stack_node **destination)
{
	t_stack_node	*temp;

	if (*source == NULL)
		return ;
	temp = *source;
	*source = (*source)->next;
	temp->next = *destination;
	*destination = temp;
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	if (*b == NULL)
		return ;
	push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	if (*a == NULL)
		return ;
	push(a, b);
	ft_putstr_fd("pb\n", 1);
}
