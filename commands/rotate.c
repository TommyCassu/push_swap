/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassu <tcassu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:36:25 by tcassu            #+#    #+#             */
/*   Updated: 2025/01/14 15:42:28 by tcassu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate()
{
	
}

void	ra(t_list **a)
{
	rotate(a);
	printf("ra\n");
}

void	rb(t_list **b)
{
	rotate(b);
	printf("rb\n");
}

void	ss(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}