/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:47:23 by fdagbert          #+#    #+#             */
/*   Updated: 2019/03/27 04:37:30 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_del_stack(int stack, t_conf *conf)
{
	t_stack		*temp;
	t_stack		*next;

	temp = NULL;
	next = NULL;
	if (!stack)
		temp = conf->first_stack_a;
	else
		temp = conf->first_stack_b;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	if (!stack)
		conf->first_stack_a = NULL;
	else
		conf->first_stack_b = NULL;
}

static void		ft_error_color(int error)
{
	if (error == -1)
		ft_printf("%@{RED}Error{OFF}\n", 2);
	if (error == -2)
		ft_printf("%@{RED}Error\nUNEXPECTED FAIL: malloc{OFF}\n", 2);
	if (error == -3)
		ft_printf("%@{RED}Error\nUNEXPECTED FAIL: GNL{OFF}\n", 2);
	if (error == -4)
		ft_printf("%@{RED}Error\nUNEXPECTED FAIL: stack operation{OFF}\n", 2);
	if (error == -5)
		ft_printf("%@{RED}Error\nUNEXPECTED FAIL: open/close man_path (-h)\
					{OFF}\n", 2);
	if (error == -6)
		ft_printf("%@{RED}Error\nUNEXPECTED FAIL: open/close init_file (-i)\
					{OFF}\n", 2);
	if (error == -7)
		ft_printf("%@{RED}Error\nUNEXPECTED FAIL: open/close inst_file (-r/-w)\
					{OFF}\n", 2);
}

static void		ft_error(int error)
{
	if (error == -1)
		ft_printf("%@Error\n", 2);
	if (error == -2)
		ft_printf("%@Error\nUNEXPECTED FAIL: malloc\n", 2);
	if (error == -3)
		ft_printf("%@Error\nUNEXPECTED FAIL: GNL\n", 2);
	if (error == -4)
		ft_printf("%@Error\nUNEXPECTED FAIL: stack operation\n", 2);
	if (error == -5)
		ft_printf("%@Error\nUNEXPECTED FAIL: open/close man_path (-h)\n", 2);
	if (error == -6)
		ft_printf("%@Error\nUNEXPECTED FAIL: open/close init_file (-i)\n", 2);
	if (error == -7)
		ft_printf("%@Error\nUNEXPECTED FAIL: open/close inst_file (-r/-w)\
					\n", 2);
}

int				ft_end(int error, t_conf *conf)
{
	if (error)
	{
		if (conf->opt[1])
			ft_error_color(error);
		else
			ft_error(error);
	}
	ft_del_stack(0, conf);
	ft_del_stack(1, conf);
	return (error);
}
