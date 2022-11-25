/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unit_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:04:58 by fdagbert          #+#    #+#             */
/*   Updated: 2019/03/19 20:42:54 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_print_three_a(int a, int b, int c, t_conf *conf)
{
	if ((b > a && a > c) || (b > c && c > a))
	{
		if (ft_add_inst(9, "rra", conf) < 0)
			return (-2);
	}
	if ((c > a && a > b) || (b > c && c > a))
	{
		if (ft_add_inst(1, "sa", conf) < 0)
			return (-2);
	}
	if ((a > c && c > b) || (a > b && b > c))
	{
		if (ft_add_inst(6, "ra", conf) < 0)
			return (-2);
	}
	if (a > b && b > c)
	{
		if (ft_add_inst(1, "sa", conf) < 0)
			return (-2);
	}
	return (0);
}

static int		ft_three_sort_a(t_conf *conf)
{
	int			a;
	int			b;
	int			c;
	t_stack		*temp;

	temp = conf->first_stack_a;
	a = temp->value;
	temp = temp->next;
	b = temp->value;
	temp = temp->next;
	if (conf->size_a > 2)
	{
		c = temp->value;
		ft_print_three_a(a, b, c, conf);
	}
	else if (a > b)
	{
		if (ft_add_inst(1, "sa", conf) < 0)
			return (-2);
	}
	return (0);
}

static int		ft_print_three_b(int a, int b, int c, t_conf *conf)
{
	if ((b > c && c > a) || (c > b && b > a))
	{
		if (ft_add_inst(7, "rb", conf) < 0)
			return (-2);
	}
	if ((b > a && a > c) || (c > b && b > a))
	{
		if (ft_add_inst(2, "sb", conf) < 0)
			return (-2);
	}
	if ((c > a && a > b) || (a > c && c > b))
	{
		if (ft_add_inst(10, "rrb", conf) < 0)
			return (-2);
	}
	if (a > c && c > b)
	{
		if (ft_add_inst(2, "sb", conf) < 0)
			return (-2);
	}
	return (0);
}

static int		ft_three_sort_b(t_conf *conf)
{
	int			a;
	int			b;
	int			c;
	t_stack		*temp;

	temp = conf->first_stack_b;
	a = temp->value;
	temp = temp->next;
	b = temp->value;
	temp = temp->next;
	if (conf->size_b > 2)
	{
		c = temp->value;
		ft_print_three_b(a, b, c, conf);
	}
	else if (a < b)
	{
		if (ft_add_inst(2, "sb", conf) < 0)
			return (-2);
	}
	return (0);
}

int				ft_unit_sort(int end, t_conf *conf)
{
	if (end <= 3)
		ft_three_sort_a(conf);
	else
	{
		if ((ft_clone_tab(end, conf->first_stack_a, conf)) < 0)
			return (-2);
		while (end--)
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
			}
		}
		ft_three_sort_a(conf);
		ft_three_sort_b(conf);
	}
	return (0);
}
