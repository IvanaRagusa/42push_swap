/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:31:16 by iragusa           #+#    #+#             */
/*   Updated: 2023/03/12 18:31:38 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	write_list_index(t_list *stack_a)
{
	t_list	*ptr;

	if (!stack_a)
		return ;
	ptr = stack_a;
	while (ptr)
	{
		printf("%d\n", ptr->index);
		ptr = ptr->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	char	**arg;
	t_list	*stack_b;
	int		ac_2;

	if (ac == 1)
		exit (0);
	ac_2 = ac;
	ac = check_av(ac, av);
	stack_a = NULL;
	stack_b = NULL;
	arg = stack_checker(ac_2, av);
	stack_create (arg, &stack_a, ac, ac_2);
	ft_index(&stack_a);
	if (ac < 7)
		ft_smallsort(&stack_a, &stack_b, ac, ac_2);
	else
		ft_sortlst(&stack_a, &stack_b, ac);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_a, free);
}
