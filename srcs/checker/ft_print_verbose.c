/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_verbose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 23:56:11 by fdagbert          #+#    #+#             */
/*   Updated: 2019/03/20 21:02:30 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		ft_color_str(int color, char *str, t_conf *conf)
{
	if (conf->opt[1])
	{
		if (!color)
			ft_printf("{BLU}%s{OFF}", str);
		else if (color == 1)
			ft_printf("{WHI}%s{OFF}", str);
		else
			ft_printf("{MAG}%s{OFF}", str);
	}
	else
		ft_printf("%s", str);
}

static void		ft_color_nbr(int color, int nbr, t_conf *conf)
{
	if (!color)
	{
		if (conf->opt[1])
			ft_printf("{BLU}%12d {OFF}", nbr);
		else
			ft_printf("%12d ", nbr);
	}
	else
	{
		if (conf->opt[1])
			ft_printf("{MAG}%12d{OFF}\n", nbr);
		else
			ft_printf("%12d\n", nbr);
	}
}

static void		ft_print_line(int color, int empty, t_stack **tmp, t_conf *conf)
{
	if (*tmp)
	{
		ft_color_nbr(color, (*tmp)->value, conf);
		*tmp = (*tmp)->next;
	}
	else if (empty)
	{
		if (!color)
			ft_color_str(1, "    Empty    ", conf);
		else
			ft_color_str(1, "    Empty\n", conf);
	}
	else if (!color)
		ft_printf("%13c", ' ');
	else
		ft_printf("\n");
}

static void		ft_print_stack(t_stack *temp_a, t_stack *temp_b, t_conf *conf)
{
	int			empty_a;
	int			empty_b;

	if (!temp_a)
		empty_a = 1;
	else
		empty_a = 0;
	if (!temp_b)
		empty_b = 1;
	else
		empty_b = 0;
	ft_color_str(0, "   Stack A   ", conf);
	ft_color_str(1, "|", conf);
	ft_color_str(2, "   Stack B\n", conf);
	while (temp_a || temp_b)
	{
		ft_print_line(0, empty_a, &temp_a, conf);
		empty_a = 0;
		ft_color_str(1, "|", conf);
		ft_print_line(2, empty_b, &temp_b, conf);
		empty_b = 0;
	}
}

void			ft_print_verbose(t_conf *conf)
{
	if (conf->opt[0] && conf->opt[3])
	{
		if (conf->opt[1])
			ft_printf("{WHI}Instruction number: %d{OFF}\n", conf->total_inst);
		else
			ft_printf("Instruction number: %d\n", conf->total_inst);
	}
	if (conf->opt[5] && conf->line)
	{
		if (conf->opt[1])
			ft_printf("{CYA}%s{OFF}\n", conf->line);
		else
			ft_printf("%s\n", conf->line);
	}
	if (conf->opt[0])
		ft_print_stack(conf->first_stack_a, conf->first_stack_b, conf);
	if (conf->opt[0] && conf->opt[8] && conf->line)
	{
		if (conf->opt[1])
			ft_printf("{YEL}* Step by step mode *{OFF}\n");
		else
			ft_printf("* Step by step mode *\n");
	}
}
