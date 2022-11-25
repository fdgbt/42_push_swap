/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 22:06:26 by stin              #+#    #+#             */
/*   Updated: 2019/04/01 17:41:42 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void		ft_dupli_opti(t_conf *conf)
{
	t_inst		*temp;
	t_inst		*last;

	temp = conf->first_inst;
	last = conf->first_inst;
	while (temp)
	{
		if ((temp->next && temp->inst == 4 && temp->next->inst == 5) ||
			(temp->next && temp->inst == 5 && temp->next->inst == 4) ||
			(temp->next && temp->inst == 6 && temp->next->inst == 9) ||
			(temp->next && temp->inst == 9 && temp->next->inst == 6) ||
			(temp->next && temp->inst == 7 && temp->next->inst == 10) ||
			(temp->next && temp->inst == 10 && temp->next->inst == 7))
		{
			last->next = temp->next->next;
			free(temp->next);
			free(temp);
			temp = conf->first_inst;
		}
		else
		{
			last = temp;
			temp = temp->next;
		}
	}
}

static void		ft_print_inst(t_conf *conf)
{
	t_inst		*temp;
	t_inst		*last;

	temp = conf->first_inst;
	last = conf->first_inst;
	ft_dupli_opti(conf);
	while (temp)
	{
		last = temp;
		ft_printf("%@%s\n", conf->fd, temp->line);
		temp = temp->next;
		free(last);
	}
	ft_printf("%@\0", conf->fd);
}

static int		ft_sort_a(t_conf *conf)
{
	if (conf->size_a < 7)
	{
		if (ft_unit_sort(conf->size_a, conf) < 0)
			return (-2);
		while (conf->first_stack_b)
		{
			if (ft_add_inst(4, "pa", conf) < 0)
				return (-2);
		}
	}
	else
	{
		if (ft_qsort_a(conf->size_a, conf) < 0)
			return (-2);
		while (conf->first_stack_a)
		{
			if (ft_add_inst(5, "pb", conf) < 0)
				return (-2);
		}
		if (ft_insert_sort_b(conf) < 0)
			return (-2);
	}
	ft_print_inst(conf);
	return (0);
}

int				ft_sort_list(t_conf *conf)
{
	conf->fd = 1;
	if (conf->opt[2] || conf->opt[7])
	{
		if ((conf->fd = open(conf->inst_file, O_WRONLY | O_TRUNC | O_CREAT,
				S_IRWXU)) < 0)
			return (-7);
	}
	if (!ft_check_sort(conf->size_a, conf))
	{
		if (ft_sort_a(conf) < 0)
			return (-2);
	}
	if (conf->opt[2] || conf->opt[7])
	{
		if (close(conf->fd) < 0)
			return (-7);
	}
	return (0);
}
