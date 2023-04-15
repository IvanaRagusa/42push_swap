/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:20:45 by iragusa           #+#    #+#             */
/*   Updated: 2023/03/12 20:59:39 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "ctype.h"

int	checknum(int temp, char **arg, int i)
{
	int	j;

	j = 0;
	if (arg[i][j] == '-')
	{
		if (!ft_isdigit(arg[i][1]))
			return (0);
		j++;
	}
	while (arg[i][j] != 0)
	{
		if (!ft_isdigit((arg[i][j])))
			return (0);
		j++;
	}
	while (--i > 0)
	{
		if (temp == ft_atoi(arg[i]))
			return (0);
	}
	return (1);
}

void	ft_checkav_help(int i, int ac, char **arg, int ac_2)
{
	long int	temp;

	if (ac_2 == 2)
		i -= 1;
	while (i < ac)
	{
		temp = ft_atoi(arg[i]);
		if (!checknum(temp, arg, i))
			ft_error(arg, ac_2);
		if (temp > 2147483647 || temp < -2147483648)
			ft_error(arg, ac_2);
		i++;
	}
}

int	check_av(int ac, char **av)
{
	int		j;
	char	**arg;
	int		i;
	int		ac_2;

	i = 1;
	j = 0;
	ac_2 = ac;
	if (ac == 2)
	{
		arg = ft_split(av[i], ' ');
		while (arg[j] != NULL)
			j++;
		ac = j;
	}
	else if (ac > 2)
		arg = av;
	ft_checkav_help(i, ac, arg, ac_2);
	if (ac_2 == 2)
		free_mat(arg);
	return (ac);
}

int	is_swapped(t_list *stack)
{
	int	prec;

	prec = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		if (prec > stack->content)
			return (0);
		prec = stack->content;
		stack = stack->next;
	}
	return (1);
}

char	**stack_checker(int ac, char **av)
{
	char	**arg;

	arg = NULL;
	if (ac == 2)
		arg = ft_split(av[1], ' ');
	else if (ac > 2)
		arg = av;
	else
		ft_error(arg, ac);
	if (!arg)
		ft_error(arg, ac);
	return (arg);
}
