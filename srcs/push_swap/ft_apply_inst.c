/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_inst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 01:08:19 by fdagbert          #+#    #+#             */
/*   Updated: 2019/04/01 17:37:15 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_swap(int inst, t_stack *temp, t_conf *conf)
{
	if (inst == '1' || inst == '3')
	{
		if (conf->first_stack_a && conf->first_stack_a->next)
		{
			temp = conf->first_stack_a->next;
			conf->first_stack_a->next = temp->next;
			temp->next = conf->first_stack_a;
			conf->first_stack_a = temp;
		}
	}
	if (inst == '2' || inst == '3')
	{
		if (conf->first_stack_b && conf->first_stack_b->next)
		{
			temp = conf->first_stack_b->next;
			conf->first_stack_b->next = temp->next;
			temp->next = conf->first_stack_b;
			conf->first_stack_b = temp;
		}
	}
}

static void		ft_push(int inst, t_stack *temp, t_conf *conf)
{
	if (inst == '4')
	{
		if (conf->first_stack_b)
		{
			temp = conf->first_stack_b->next;
			conf->first_stack_b->next = conf->first_stack_a;
			conf->first_stack_a = conf->first_stack_b;
			conf->first_stack_b = temp;
			conf->size_a++;
			conf->size_b--;
		}
	}
	if (inst == '5')
	{
		if (conf->first_stack_a)
		{
			temp = conf->first_stack_a->next;
			conf->first_stack_a->next = conf->first_stack_b;
			conf->first_stack_b = conf->first_stack_a;
			conf->first_stack_a = temp;
			conf->size_a--;
			conf->size_b++;
		}
	}
}

static void		ft_rotate(int inst, t_stack *temp, t_conf *conf)
{
	if (inst == '6' || inst == '8')
	{
		if (conf->first_stack_a && conf->first_stack_a->next)
		{
			temp = conf->first_stack_a;
			while (temp->next)
				temp = temp->next;
			temp->next = conf->first_stack_a;
			conf->first_stack_a = conf->first_stack_a->next;
			temp->next->next = NULL;
		}
	}
	if (inst == '7' || inst == '8')
	{
		if (conf->first_stack_b && conf->first_stack_b->next)
		{
			temp = conf->first_stack_b;
			while (temp->next)
				temp = temp->next;
			temp->next = conf->first_stack_b;
			conf->first_stack_b = conf->first_stack_b->next;
			temp->next->next = NULL;
		}
	}
}

static void		ft_reverse(int inst, t_stack *temp, t_conf *conf)
{
	if (inst == '9' || inst == ';')
	{
		if (conf->first_stack_a && conf->first_stack_a->next)
		{
			temp = conf->first_stack_a;
			while (temp->next->next)
				temp = temp->next;
			temp->next->next = conf->first_stack_a;
			conf->first_stack_a = temp->next;
			temp->next = NULL;
		}
	}
	if (inst == ':' || inst == ';')
	{
		if (conf->first_stack_b && conf->first_stack_b->next)
		{
			temp = conf->first_stack_b;
			while (temp->next->next)
				temp = temp->next;
			temp->next->next = conf->first_stack_b;
			conf->first_stack_b = temp->next;
			temp->next = NULL;
		}
	}
}

int				ft_apply_inst(int inst, t_conf *conf)
{
	int						i;
	static const t_keys		instructions[5] = {
		{"123", &ft_swap},
		{"45", &ft_push},
		{"678", &ft_rotate},
		{"9:;", &ft_reverse},
		{NULL, NULL}
	};

	i = 0;
	inst += 48;
	while (instructions[i].key && !ft_strchr(instructions[i].key, inst))
		i++;
	if (instructions[i].key)
		instructions[i].ft_select_inst(inst, NULL, conf);
	else
		return (-1);
	return (0);
}
