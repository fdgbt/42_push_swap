/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:39:50 by fdagbert          #+#    #+#             */
/*   Updated: 2019/01/18 01:07:02 by stin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		ft_is_sort(t_stack *temp, int max, int sorted)
{
	while (temp && sorted)
	{
		if (temp->value >= max)
			max = temp->value;
		else
			sorted = 0;
		temp = temp->next;
	}
	return (sorted);
}

static void		ft_total_inst(t_conf *conf)
{
	if (conf->opt[1])
		ft_printf("{WHI}Total instructions: %d{OFF}\n", conf->total_inst);
	else
		ft_printf("Total instructions: %d\n", conf->total_inst);
}

static void		ft_print_sort(int sorted, t_conf *conf)
{
	if (sorted)
	{
		if (conf->opt[1])
			ft_printf("{BOLD}{GRE}OK{OFF}\n");
		else
			ft_printf("OK\n");
	}
	else
	{
		if (conf->opt[1])
			ft_printf("{BOLD}{RED}KO{OFF}\n");
		else
			ft_printf("KO\n");
	}
}

void			ft_check_sort(t_conf *conf)
{
	t_stack		*temp;
	int			sorted;
	int			max;

	temp = conf->first_stack_a;
	sorted = 1;
	max = INT_MIN;
	if (conf->first_stack_b != NULL)
		sorted = 0;
	else
		sorted = ft_is_sort(temp, max, sorted);
	if (conf->opt[3])
		ft_total_inst(conf);
	ft_print_sort(sorted, conf);
}
