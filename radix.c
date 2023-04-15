/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:01:13 by iragusa           #+#    #+#             */
/*   Updated: 2023/03/27 19:01:16 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_maxbit(int ac)
{
	int	i;

	i = 0;
	while (ac != 0)
	{
		ac /= 2;
		i++;
	}
	return (i);
}

t_list	*ft_tostack_a(t_list *stack_a, t_list *stack_b, int tob)
{
	int	i;

	i = -1;
	while (i < tob)
	{
		ft_push(&stack_b, &stack_a, 'a');
		i++;
	}
	return (stack_a);
}

int	st_min(t_list *stack)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (min > stack->content)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	st_max(t_list *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (max < stack->content)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

void	ft_sortlst(t_list **stack_a, t_list **stack_b, int ac)
{
	static int		i;
	static int		bit;
	int				tob;
	int				max;

	max = ft_maxbit(ac);
	while (bit < max)
	{
		i = ac;
		tob = 0;
		while (i > 1)
		{
			if (!(((*stack_a)->index >> bit) & 1))
			{
				ft_push (stack_a, stack_b, 'b');
				tob ++;
			}
			else
				ft_rotate(stack_a, 'a');
			i--;
		}
		*stack_a = ft_tostack_a(*stack_a, *stack_b, tob);
		*stack_b = NULL;
		bit++;
	}
}
