/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:37:07 by fdagbert          #+#    #+#             */
/*   Updated: 2019/04/01 18:41:47 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		ft_check_line(char *line)
{
	static const char	*keys[12] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr", 0};
	int					i;
	int					j;

	i = 0;
	j = 0;
	if (!line)
		return (-1);
	if (!line[0])
		return (0);
	while (keys[i])
	{
		while (keys[i][j] && line[j] && keys[i][j] == line[j])
		{
			j++;
			if (!keys[i][j] && !line[j])
				return (i + 1);
		}
		i++;
		j = 0;
	}
	return (-1);
}

static void		ft_print_help(int status, t_conf *conf)
{
	if (conf->opt[6])
	{
		if ((conf->opt[0]) && status == 0)
		{
			if (conf->opt[1])
				ft_printf("{GRE}* Initial list *{OFF}\n");
			else
				ft_printf("* Initial state *\n");
		}
		else if (status == 1)
		{
			if (conf->opt[1])
				ft_printf("{GRE}* Waiting instructions *{OFF}\n");
			else
				ft_printf("* Waiting instructions *\n");
		}
		else if (status == 2)
		{
			if (conf->opt[1])
				ft_printf("{GRE}* Result *{OFF}\n");
			else
				ft_printf("* Result *\n");
		}
	}
}

static int		ft_free_line(int error, t_conf *conf)
{
	if (error)
		ft_get_next_line(conf->fd, NULL);
	if (conf->line)
		free(conf->line);
	conf->line = NULL;
	return (error);
}

static int		ft_get_next_inst(int ret, int inst, t_conf *conf)
{
	ft_print_help(0, conf);
	ft_print_verbose(conf);
	ft_print_help(1, conf);
	while (ret)
	{
		if ((ret = ft_get_next_line(conf->fd, &conf->line)) < 0)
			return (ft_free_line(-3, conf));
		if ((inst = ft_check_line(conf->line)) < 0)
			return (ft_free_line(-1, conf));
		if (inst && ft_apply_inst(inst, conf) < 0)
			return (ft_free_line(-4, conf));
		if (ret)
		{
			conf->total_inst++;
			ft_print_verbose(conf);
			if (conf->opt[0] && conf->opt[8])
			{
				if (read(1, conf->buff_step, 1) < 0)
					return (ft_free_line(-9, conf));
			}
		}
		ft_free_line(0, conf);
	}
	ft_print_help(2, conf);
	return (0);
}

int				ft_check_inst(t_conf *conf)
{
	int		err;

	err = 0;
	conf->fd = 0;
	if (conf->opt[2] || conf->opt[7])
	{
		if (ft_delay(1) < 0)
			return (-8);
		if ((conf->fd = open(conf->inst_file, O_RDONLY)) < 0)
			return (-7);
	}
	if ((err = ft_get_next_inst(1, 0, conf)) < 0)
		return (err);
	if (conf->opt[2] || conf->opt[7])
	{
		if (close(conf->fd) < 0)
			return (-7);
	}
	return (0);
}
