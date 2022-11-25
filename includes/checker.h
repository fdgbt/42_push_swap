/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 20:48:51 by fdagbert          #+#    #+#             */
/*   Updated: 2019/03/20 19:44:26 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define D_OPTMAX 10
# define D_MAN_PATH "./man/man_ps"

# include "libft.h"
# include "ft_printf.h"
# include <limits.h>

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_conf
{
	const char		*opt_key;
	int				opt[D_OPTMAX];
	int				opt_set;
	int				fd;
	int				total_inst;
	char			*inst_file;
	char			*init_file;
	char			*line;
	char			buff_step[2];
	t_stack			*first_stack_a;
	t_stack			*first_stack_b;
}					t_conf;

typedef struct		s_keys
{
	char			*key;
	void			(*ft_select_inst)(int inst, t_stack *temp, t_conf *conf);
}					t_keys;

int					ft_check_list(int argc, char **argv, t_conf *conf);
int					ft_init_file(t_conf *conf);
int					ft_check_inst(t_conf *conf);
int					ft_end(int error, t_conf *conf);
int					ft_apply_inst(int inst, t_conf *conf);
void				ft_check_sort(t_conf *conf);
void				ft_print_verbose(t_conf *conf);

#endif
