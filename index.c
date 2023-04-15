/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appoggio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:26:38 by iragusa           #+#    #+#             */
/*   Updated: 2023/04/02 19:26:42 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_list	*ft_copystack(t_list *stack)
{
	t_list	*new;

	new = NULL;
	while (stack != NULL)
	{
		ft_lstadd_back(&new, ft_lstnew(stack->content, 0));
		stack = stack->next;
	}
	return (new);
}

void	ft_add_index(t_list *stack, int min, int i)
{
	while (stack != NULL)
	{
		if (stack->content == min)
		{
			stack->index = i;
			break ;
		}
		stack = stack->next;
	}
}

void	ft_maximize(t_list *new, int min)
{
	while (new != NULL)
	{
		if (new->content == min)
		{
			new->content = 2147483647;
			break ;
		}
		new = new->next;
	}
}

void	ft_index(t_list **stack)
{
	t_list	*new;
	int		i;
	int		len;
	int		min;

	len = ft_lstsize(*stack);
	i = 0;
	new = ft_copystack(*stack);
	while (i < len)
	{
		min = st_min(new);
		ft_add_index(*stack, min, i);
		ft_maximize(new, st_min(new));
		i++;
	}
	ft_lstclear(&new, free);
}
