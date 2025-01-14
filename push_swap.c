/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassu <tcassu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:34 by tcassu            #+#    #+#             */
/*   Updated: 2025/01/14 15:29:14 by tcassu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void afficher_liste(t_list *liste)
{
    t_list *temp = liste;
    while (temp != NULL)
    {
        printf("%d ", *(int *)temp->content);
        temp = temp->next;
    }
    printf("\n");
}

void	initialise_lst(char *av[], t_list **a)
{
	int	*content;	
	int	i;
	
	i = 0;
	while(av[i])
	{
		if (!ft_atoi(av[i]))
			return ; // error + free
		content = malloc(sizeof(int));
		if (!content)
			return ;
		*content = ft_atoi(av[i]);
		ft_lstadd_back(a, ft_lstnew(content));
		afficher_liste(*a);
		i++;
	}
	
}



int	main(int ac,char *av[])
{
	t_list	*a;
	
	a = NULL;
	if(ac == 1 || (ac == 2 && av[1][0] == '\0'))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	initialise_lst(av, &a);
}