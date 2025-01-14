/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassu <tcassu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:42:44 by tcassu            #+#    #+#             */
/*   Updated: 2025/01/14 15:44:12 by tcassu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate()
{
	
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	printf("ra\n");
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	printf("rb\n");
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	printf("rrr\n");
}