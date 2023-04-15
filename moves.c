/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:17:03 by iragusa           #+#    #+#             */
/*   Updated: 2023/03/25 17:17:06 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_swap(t_list *stack, char swap)
{
	int	temp;

	if (stack != NULL && stack->next != NULL)
	{
		temp = stack->index;
		stack->index = stack->next->index;
		stack->next->index = temp;
		if (swap == 'a')
			write(1, "sa\n", 3);
		else if (swap == 'b')
			write(1, "sb\n", 3);
	}
}

void	ft_push(t_list **stack, t_list **dest, char push)
{
	t_list	*ptr;

	if (*stack != NULL)
	{
		ptr = *stack;
		*stack = (*stack)->next;
		ptr->next = *dest;
		*dest = ptr;
		if (push == 'a')
			write(1, "pa\n", 3);
		else if (push == 'b')
			write(1, "pb\n", 3);
	}
}

void	ft_rotate(t_list **stack, char rot)
{
	t_list	*head;
	t_list	*back;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	head = *stack;
	back = *stack;
	while (back->next != NULL)
		back = back->next;
	*stack = head->next;
	head->next = NULL;
	back->next = (*stack);
	back->next = head;
	if (rot == 'a')
		write(1, "ra\n", 3);
	else if (rot == 'b')
		write(1, "rb\n", 3);
	return ;
}

void	ft_rev_rotate(t_list **stack, char rot)
{
	t_list					*temp;

	if (stack != NULL && *stack != NULL)
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		del_last(stack);
		temp->next = *stack;
		*stack = temp;
		if (rot == 'a')
			write(1, "rra\n", 4);
		else if (rot == 'b')
			write(1, "rrb\n", 4);
	}
}
