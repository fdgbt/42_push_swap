/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_inst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 20:12:20 by fdagbert          #+#    #+#             */
/*   Updated: 2019/03/20 00:02:32 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_add_inst(int inst, char *line, t_conf *conf)
{
	t_inst		*temp;
	t_inst		*new;
	int			i;

	i = 4;
	temp = conf->first_inst;
	if (!(new = (t_inst *)malloc(sizeof(*new))))
		return (-2);
	new->inst = inst;
	while (i--)
		new->line[i - 1] = 0;
	ft_strcpy(new->line, line);
	new->next = NULL;
	if (!temp)
		conf->first_inst = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	if (ft_apply_inst(inst, conf) < 0)
		return (-4);
	return (0);
}
