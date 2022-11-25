/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:16:55 by fdagbert          #+#    #+#             */
/*   Updated: 2019/04/01 17:36:43 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_stack	*ft_check_dupli(intmax_t value, t_stack *temp)
{
	if (temp->value == value)
		return (NULL);
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->value == value)
			return (NULL);
	}
	return (temp);
}

static int		ft_init_stack(char *argv, t_conf *conf)
{
	t_stack		*temp;
	intmax_t	value;

	temp = conf->first_stack_a;
	value = ft_atoim(argv);
	if (value > INT_MAX || value < INT_MIN)
		return (-1);
	if (!temp)
	{
		if (!(temp = (t_stack *)malloc(sizeof(*temp))))
			return (-2);
		conf->first_stack_a = temp;
	}
	else
	{
		if (!(temp = ft_check_dupli(value, temp)))
			return (-1);
		if (!(temp->next = (t_stack *)malloc(sizeof(*temp))))
			return (-2);
		temp = temp->next;
	}
	temp->value = value;
	temp->next = NULL;
	return (0);
}

static int		ft_options(char *argv, t_conf *conf)
{
	int i;

	i = 0;
	while (conf->opt_key[i])
	{
		if (argv[1] && argv[1] == conf->opt_key[i])
		{
			if (!argv[2])
			{
				if (conf->opt[i] != 0)
					return (-1);
				conf->opt[i] = 1;
				return (i);
			}
			else
				return (-1);
		}
		i++;
	}
	return (-1);
}

static int		ft_check_nb(char **argv, int i, int j, t_conf *conf)
{
	int digit;
	int ret;

	ret = 0;
	digit = 1;
	while (digit && argv[i][j])
	{
		if (!ft_isdigit(argv[i][j]))
			digit = 0;
		j++;
	}
	if (!argv[i][0] || (!digit && argv[i][0] != '-') ||
			((argv[i][0] == '-' || argv[i][0] == '+') && !argv[i][1]))
		return (-1);
	else if (!digit)
	{
		if ((ret = ft_options(*(argv + i), conf)) < 0)
			return (-1);
		else if (ret == 2 || ret == 7)
			conf->inst_file = *(argv + ++i);
		else if (ret == 4)
			conf->init_file = *(argv + ++i);
		conf->opt_set = 1;
	}
	return (i);
}

int				ft_check_list(int argc, char **argv, t_conf *conf)
{
	int		i;
	int		err;

	i = 1;
	err = 0;
	while (i < argc)
	{
		if (argv[i][0] != '-' && argv[i][0] != '+')
			i = ft_check_nb(argv, i, 0, conf);
		else
			i = ft_check_nb(argv, i, 1, conf);
		if (i < 0)
			return (-1);
		if (conf->opt_set == 1)
			conf->opt_set = 0;
		else if ((err = ft_init_stack(*(argv + i), conf)) < 0)
			return (err);
		i++;
	}
	return (0);
}
