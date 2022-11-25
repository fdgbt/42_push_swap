/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:39:50 by fdagbert          #+#    #+#             */
/*   Updated: 2019/02/19 19:19:00 by stin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_is_sort(t_stack *temp, int max, int end, int sorted)
{
	int		i;

	i = 1;
	while (temp && sorted && i <= end)
	{
		if (temp->value >= max)
			max = temp->value;
		else
			sorted = 0;
		temp = temp->next;
		i++;
	}
	return (sorted);
}

int				ft_check_sort(int end, t_conf *conf)
{
	t_stack		*temp;
	int			sorted;
	int			max;

	temp = conf->first_stack_a;
	sorted = 1;
	max = INT_MIN;
	if (conf->first_stack_b != NULL && end == conf->size_a)
		sorted = 0;
	else
		sorted = ft_is_sort(temp, max, end, sorted);
	return (sorted);
}
