/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 20:19:23 by fdagbert          #+#    #+#             */
/*   Updated: 2019/04/01 17:41:02 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_reverse_opti_a(int end, int j, t_conf *conf)
{
	if (end / 2 != conf->size_a)
	{
		while (j--)
		{
			if (ft_add_inst(9, "rra", conf) < 0)
				return (-2);
		}
	}
	return (0);
}

static int	ft_partition_a(int end, t_conf *conf)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i++ <= end)
	{
		if (conf->first_stack_a->value <= conf->median->value)
		{
			if (ft_add_inst(5, "pb", conf) < 0)
				return (-2);
		}
		else
		{
			if (ft_add_inst(6, "ra", conf) < 0)
				return (-2);
			j++;
		}
	}
	if (ft_reverse_opti_a(end, j, conf) < 0)
		return (-2);
	return (0);
}

int			ft_qsort_a(int end, t_conf *conf)
{
	if (end > 4)
	{
		if ((ft_clone_tab(end, conf->first_stack_a, conf)) < 0)
			return (-2);
		ft_partition_a(end, conf);
		if (ft_qsort_b(end / 2 + end % 2, conf) < 0)
			return (-2);
		if (ft_qsort_a(end / 2, conf) < 0)
			return (-2);
	}
	else
	{
		while (end--)
		{
			if (ft_add_inst(5, "pb", conf) < 0)
				return (-2);
		}
	}
	return (0);
}
