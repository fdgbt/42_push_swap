/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 20:28:48 by fdagbert          #+#    #+#             */
/*   Updated: 2019/03/21 09:10:07 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_reverse_opti_b(int end, int j, t_conf *conf)
{
	if ((end / 2 + end % 2) != conf->size_b)
	{
		while (j--)
		{
			if (ft_add_inst(10, "rrb", conf) < 0)
				return (-2);
		}
	}
	return (0);
}

static int		ft_partition_b(int end, t_conf *conf)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i++ <= end)
	{
		if (conf->first_stack_b->value > conf->median->value)
		{
			if (ft_add_inst(4, "pa", conf) < 0)
				return (-2);
		}
		else
		{
			if (ft_add_inst(7, "rb", conf) < 0)
				return (-2);
			j++;
		}
	}
	if (ft_reverse_opti_b(end, j, conf) < 0)
		return (-2);
	return (0);
}

int				ft_qsort_b(int end, t_conf *conf)
{
	if (end > 16)
	{
		if ((ft_clone_tab(end, conf->first_stack_b, conf)) < 0)
			return (-2);
		ft_partition_b(end, conf);
		if (ft_qsort_b(end / 2 + end % 2, conf) < 0)
			return (-2);
		if (ft_qsort_a(end / 2, conf) < 0)
			return (-2);
	}
	return (0);
}
