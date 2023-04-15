/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:13:56 by iragusa           #+#    #+#             */
/*   Updated: 2023/03/25 23:14:04 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_ss(t_list *stack_a, t_list *stack_b)
{
	ft_swap(stack_a, 'a');
	ft_swap(stack_b, 'b');
	write(1, "ss\n", 3);
}

void	ft_rr(t_list *stack_a, t_list *stack_b)
{
	ft_rotate(&stack_a, 'a');
	ft_rotate(&stack_b, 'b');
	write(1, "rr\n", 3);
}

void	ft_rrr(t_list *stack_a, t_list *stack_b)
{
	ft_rev_rotate(&stack_a, 'a');
	ft_rev_rotate(&stack_b, 'b');
	write(1, "rrr\n", 4);
}
