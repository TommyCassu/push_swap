/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassu <tcassu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:34 by tcassu            #+#    #+#             */
/*   Updated: 2025/04/10 14:42:53 by tcassu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	lstclear(t_stack_node **lst)
{
	t_stack_node	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	lst = NULL;
}

void	initialise_lst(char *av[], t_stack_node **a)
{
	t_stack_node	*new;
	int				i;

	i = 1;
	while (av[i])
	{
		new = malloc(sizeof(t_stack_node));
		if (!new)
			return ;
		new->value = ft_atoi(av[i]);
		new->next = NULL;
		lstadd_back(a, new);
		i++;
	}
}

int	ft_list_is_valid(int nbwords, char **list)
{
	int	i;
	int	j;
	int	actual_number;
	int	k;

	i = 1;
	while (i <= nbwords)
	{
		j = -1;
		while (list[i][++j])
		{
			if (list[i][j] < '0' || list[i][j] > '9')
				if (list[i][j] == '-' && j != 0)
					return (1);
		}
		actual_number = ft_atoi(list[i]);
		k = i + 1;
		while (k <= nbwords)
		{
			if (ft_atoi(list[k++]) == actual_number)
				return (1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_stack_node	*a;

	a = NULL;
	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	if (ft_list_is_valid(ac - 1, av) == 1)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	initialise_lst(av, &a);
	sort(&a);
	lstclear(&a);
	return (1);
}
