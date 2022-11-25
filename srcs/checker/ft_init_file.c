/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:16:55 by fdagbert          #+#    #+#             */
/*   Updated: 2019/04/01 17:43:44 by fdagbert         ###   ########.fr       */
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

static int		ft_init_stack(t_conf *conf)
{
	t_stack		*temp;
	intmax_t	value;

	temp = conf->first_stack_a;
	value = ft_atoim(conf->line);
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

static int		ft_check_nb(char *line, int i)
{
	int		digit;

	digit = 1;
	if (line[0] == '-' || line[0] == '+')
		i++;
	while (digit && line[i] && line[i] != '\n')
	{
		if (!ft_isdigit(line[i]))
			digit = 0;
		i++;
	}
	if (!digit)
		return (-1);
	else
		return (0);
}

static int		ft_free_line(int error, t_conf *conf)
{
	if (error)
		ft_get_next_line(conf->fd, NULL);
	free(conf->line);
	conf->line = NULL;
	return (error);
}

int				ft_init_file(t_conf *conf)
{
	int		ret;
	int		err;

	ret = 1;
	err = 0;
	if ((conf->fd = open(conf->init_file, O_RDONLY)) < 0)
		return (-6);
	ft_end(0, conf);
	while (ret)
	{
		if ((ret = ft_get_next_line(conf->fd, &conf->line)) < 0)
			return (ft_free_line(-3, conf));
		if (ret && ft_check_nb(conf->line, 0) < 0)
			return (ft_free_line(-1, conf));
		if (ret && (err = ft_init_stack(conf)) < 0)
			return (ft_free_line(err, conf));
		ft_free_line(0, conf);
	}
	if (close(conf->fd) < 0)
		return (-6);
	return (0);
}
