/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_sort_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 21:50:55 by fdagbert          #+#    #+#             */
/*   Updated: 2019/04/01 17:39:01 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_imax(t_conf *conf)
{
	t_stack		*temp;
	int			i;
	int			max;

	temp = conf->first_stack_b;
	i = 1;
	if (temp)
	{
		max = temp->value;
		temp = temp->next;
	}
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	temp = conf->first_stack_b;
	while (temp && temp->value != max)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int			ft_side_opti(int index_max, t_conf *conf)
{
	if (index_max <= (conf->size_b / 2 + conf->size_b % 2))
	{
		while (index_max > 1)
		{
			if (ft_add_inst(7, "rb", conf) < 0)
				return (-2);
			index_max--;
		}
	}
	else
	{
		while (index_max <= conf->size_b)
		{
			if (ft_add_inst(10, "rrb", conf) < 0)
				return (-2);
			index_max++;
		}
	}
	return (0);
}

int			ft_insert_sort_b(t_conf *conf)
{
	int		index_max;

	while (conf->first_stack_b)
	{
		index_max = ft_get_imax(conf);
		if (ft_side_opti(index_max, conf) < 0)
			return (-2);
		if (ft_add_inst(4, "pa", conf) < 0)
			return (-2);
	}
	return (0);
}
