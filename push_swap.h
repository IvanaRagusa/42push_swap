/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:31:51 by iragusa           #+#    #+#             */
/*   Updated: 2023/03/12 18:37:20 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void	write_list(t_list *stack_a);
int		check_av(int ac, char **av);
void	stack_create(char **av, t_list **stack_a, int ac, int ac_2);
void	ft_error(char **arg, int ac);
int		checknum(int temp, char **arg, int i);
char	**stack_checker(int ac, char **av);
void	del_last(t_list **head);
int		is_swapped(t_list *stack);
void	write_list_index(t_list *stack_a);

/*moves*/
void	ft_swap(t_list *stack_a, char swap);
void	ft_ss(t_list *stack_a, t_list *stack_b);
void	ft_push(t_list **stack, t_list **dest, char push);
void	ft_rotate(t_list **stack, char rot);
void	ft_rr(t_list *stack_a, t_list *stack_b);
void	ft_rev_rotate(t_list **stack, char rot);
void	ft_rrr(t_list *stack_a, t_list *stack_b);

/*sort*/
void	ft_sortlst(t_list **stack_a, t_list **stack_b, int ac);
t_list	*ft_tostack_a(t_list *stack_a, t_list *stack_b, int tob);
int		st_min(t_list *stack);
int		st_max(t_list *stack);
void	ft_index(t_list **stack_a);
void	ft_smallsort(t_list **stack_a, t_list **stack_b, int ac, int ac_2);
#endif  
