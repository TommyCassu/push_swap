/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassu <tcassu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:44:51 by tcassu            #+#    #+#             */
/*   Updated: 2025/01/14 15:48:37 by tcassu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push()
{
	
}

void	pa(t_list **a, t_list **b)
{
	if (*b == NULL)
		return ;
	push(a);
	printf("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	if (*a == NULL)
		return ;
	push(b);
	printf("pb\n");
}

