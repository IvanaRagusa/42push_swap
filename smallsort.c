/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:19:59 by iragusa           #+#    #+#             */
/*   Updated: 2023/04/06 21:20:03 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_swapped_index(t_list *stack)
{
	int	prec;

	prec = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		if (prec > stack->index)
			return (0);
		prec = stack->index;
		stack = stack->next;
	}
	return (1);
}

void	ft_five_help(t_list **stack_a, t_list **stack_b, int index)
{
	t_list		*ptr;
	static int	i;

	ptr = *stack_a;
	while (ptr->index != index)
	{
		ptr = ptr->next;
		i++;
	}
	if (i > 2)
	{
		while ((*stack_a)->index != index)
			ft_rev_rotate(stack_a, 'a');
		ft_push(stack_a, stack_b, 'b');
	}
	else
	{
		while ((*stack_a)->index != index)
			ft_rotate(stack_a, 'a');
		ft_push(stack_a, stack_b, 'b');
	}
}

void	ft_three_help(t_list **stack_a)
{
	t_list	*ptr;

	ptr = *stack_a;
	ptr = ptr->next;
	if ((ptr->index == 1))
	{
		ft_swap(*stack_a, 'a');
		ft_rev_rotate(stack_a, 'a');
	}
	else if (((ptr->index == 0)))
		ft_rotate(stack_a, 'a');
}

void	ft_three_sort(t_list **stack_a)
{
	t_list	*ptr;

	ft_index(stack_a);
	if (is_swapped_index(*stack_a))
		return ;
	ptr = *stack_a;
	if (ptr->index == 0)
	{
		ft_swap(*stack_a, 'a');
		ft_rotate(stack_a, 'a');
	}
	else if (ptr->index == 1)
	{
		ptr = ptr->next;
		if ((ptr->index == 0))
			ft_swap(*stack_a, 'a');
		else if ((((*stack_a)->next->index == 2)))
			ft_rev_rotate(stack_a, 'a');
	}
	else if (ptr->index == 2)
		ft_three_help(stack_a);
}

void	ft_smallsort(t_list **stack_a, t_list **stack_b, int ac, int ac_2)
{
	if (ac_2 == 2)
		ac++;
	if (ac == 3)
		ft_swap(*stack_a, 'a');
	if (ac == 4)
		ft_three_sort(stack_a);
	if (ac == 6 || ac == 5)
	{
		ft_five_help(stack_a, stack_b, 0);
		if (ac == 6)
			ft_five_help(stack_a, stack_b, 1);
		ft_three_sort(stack_a);
		ft_push(stack_b, stack_a, 'a');
		ft_push(stack_b, stack_a, 'a');
	}
}
