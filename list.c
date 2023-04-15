/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:01:27 by iragusa           #+#    #+#             */
/*   Updated: 2023/03/12 21:01:45 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_error(char **arg, int ac)
{
	if (ac == 2)
		free_mat(arg);
	else
		arg = NULL;
	write(2, "Error\n", 6);
	exit (0);
}

void	stack_create(char **arg, t_list **stack_a, int ac, int ac_2)
{
	int		i;
	int		temp;

	if (ac_2 == 2)
		i = 1;
	else
		i = 2;
	*stack_a = ft_lstnew(ft_atoi(arg[i - 1]), 0);
	while (i < ac)
	{
		temp = ft_atoi(arg[i]);
		ft_lstadd_back(stack_a, ft_lstnew(temp, 0));
		i++;
	}
	if (ac_2 == 2)
		free_mat(arg);
	if (is_swapped(*stack_a))
	{
		ft_lstclear(stack_a, free);
		exit (0);
	}
}

void	write_list(t_list *stack_a)
{
	t_list	*ptr;

	if (!stack_a)
		return ;
	ptr = stack_a;
	while (ptr)
	{
		printf("%d\n", ptr->content);
		ptr = ptr->next;
	}
}

void	del_last(t_list **head)
{
	t_list	*ptr;

	if (*head == NULL)
		return ;
	if ((*head)->next == NULL)
	{
		*head = NULL;
	}
	ptr = *head;
	while (ptr->next->next != NULL)
		ptr = ptr->next;
	ptr->next = NULL;
}
