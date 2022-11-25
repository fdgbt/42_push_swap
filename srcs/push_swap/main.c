/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:08:41 by fdagbert          #+#    #+#             */
/*   Updated: 2019/03/19 22:36:16 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_init_config(t_conf *conf, const char *keys)
{
	int i;

	i = 0;
	conf->opt_key = keys;
	while (i < D_OPTMAX)
		conf->opt[i++] = 0;
	conf->opt_set = 0;
	conf->fd = 1;
	conf->size_a = 0;
	conf->size_b = 0;
	conf->inst_file = NULL;
	conf->init_file = NULL;
	conf->line = NULL;
	conf->first_stack_a = NULL;
	conf->first_stack_b = NULL;
	conf->median = NULL;
	conf->first_inst = NULL;
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
		if (conf.first_stack_a && (err = ft_sort_list(&conf)) < 0)
			return (ft_end(err, &conf));
		return (ft_end(err, &conf));
	}
	return (err);
}
