/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:08:41 by fdagbert          #+#    #+#             */
/*   Updated: 2019/03/27 04:23:04 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		ft_init_config(t_conf *conf, const char *keys)
{
	int i;

	i = 0;
	conf->opt_key = keys;
	while (i < D_OPTMAX)
		conf->opt[i++] = 0;
	conf->opt_set = 0;
	conf->fd = 1;
	conf->total_inst = 0;
	conf->inst_file = NULL;
	conf->init_file = NULL;
	conf->line = NULL;
	conf->buff_step[0] = 0;
	conf->buff_step[1] = 0;
	conf->first_stack_a = NULL;
	conf->first_stack_b = NULL;
}

static int		ft_print_man(t_conf *conf)
{
	if ((conf->fd = open(D_MAN_PATH, O_RDONLY)) < 0)
		return (-5);
	if (conf->opt[1])
		ft_printf("{GRE}%~{OFF}\n", conf->fd);
	else
		ft_printf("%~\n", conf->fd);
	if (close(conf->fd) < 0)
		return (-5);
	return (0);
}

int				main(int argc, char **argv)
{
	static const char	keys[D_OPTMAX] = {'v', 'c', 'r', 'n', 'i', 'd', 'h',
											'w', 's', 0};
	t_conf				conf;
	int					err;

	err = 0;
	if (argc > 1)
	{
		ft_init_config(&conf, keys);
		if ((err = ft_check_list(argc, argv, &conf)) < 0)
			return (ft_end(err, &conf));
		if (conf.opt[4] && (err = ft_init_file(&conf)) < 0)
			return (ft_end(err, &conf));
		if (conf.opt[6] && (err = ft_print_man(&conf)) < 0)
			return (ft_end(err, &conf));
		if (conf.first_stack_a && (err = ft_check_inst(&conf)) < 0)
			return (ft_end(err, &conf));
		if (conf.first_stack_a || conf.first_stack_b)
			ft_check_sort(&conf);
		return (ft_end(err, &conf));
	}
	return (err);
}
