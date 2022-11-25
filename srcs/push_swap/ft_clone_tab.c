/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clone_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:04:58 by fdagbert          #+#    #+#             */
/*   Updated: 2019/04/01 17:38:40 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_regular_partition(int *tab, int start, int end)
{
	int		i;
	int		j;
	int		temp;
	int		pivot;

	i = start;
	j = start;
	temp = 0;
	pivot = tab[end];
	while (j <= end - 1)
	{
		if (tab[j] <= pivot)
		{
			temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
			i++;
		}
		j++;
	}
	temp = tab[i];
	tab[i] = tab[end];
	tab[end] = temp;
	return (i);
}

static void		ft_regular_qsort(int *tab, int start, int end)
{
	int		index_pivot;

	index_pivot = 0;
	if (start < end)
	{
		index_pivot = ft_regular_partition(tab, start, end);
		ft_regular_qsort(tab, start, index_pivot - 1);
		ft_regular_qsort(tab, index_pivot + 1, end);
	}
}

static void		ft_median(int size, int *tab, t_stack *first, t_conf *conf)
{
	int			index_median;
	int			median;
	t_stack		*temp;

	index_median = (size / 2 + size % 2) - 1;
	median = tab[index_median];
	temp = first;
	while (temp && temp->value != median)
		temp = temp->next;
	conf->median = temp;
}

int				ft_clone_tab(int end, t_stack *first, t_conf *conf)
{
	int			i;
	int			*tab;
	t_stack		*temp;

	i = 0;
	tab = NULL;
	temp = first;
	if (!(tab = (int *)malloc(sizeof(tab) * end + 1)))
		return (-2);
	while (i < end + 1)
		tab[i++] = 0;
	i = 0;
	while (i < end)
	{
		tab[i++] = temp->value;
		temp = temp->next;
	}
	ft_regular_qsort(tab, 0, end - 1);
	ft_median(end, tab, first, conf);
	free(tab);
	return (0);
}
