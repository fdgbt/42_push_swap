/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 20:48:51 by fdagbert          #+#    #+#             */
/*   Updated: 2019/03/20 00:06:48 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define D_OPTMAX 10

# include "libft.h"
# include "ft_printf.h"
# include <limits.h>

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_inst
{
	int				inst;
	char			line[4];
	struct s_inst	*next;
}					t_inst;

typedef struct		s_conf
{
	const char		*opt_key;
	int				opt[D_OPTMAX];
	int				opt_set;
	int				fd;
	int				size_a;
	int				size_b;
	char			*inst_file;
	char			*init_file;
	char			*line;
	t_stack			*first_stack_a;
	t_stack			*first_stack_b;
	t_stack			*median;
	t_inst			*first_inst;
}					t_conf;

typedef struct		s_keys
{
	char			*key;
	void			(*ft_select_inst)(int inst, t_stack *temp, t_conf *conf);
}					t_keys;

int					ft_check_list(int argc, char **argv, t_conf *conf);
int					ft_init_file(t_conf *conf);
int					ft_add_inst(int inst, char *line, t_conf *conf);
int					ft_end(int error, t_conf *conf);
int					ft_apply_inst(int inst, t_conf *conf);
int					ft_check_sort(int end, t_conf *conf);
int					ft_sort_list(t_conf *conf);
int					ft_unit_sort(int end, t_conf *conf);
int					ft_qsort_a(int end, t_conf *conf);
int					ft_qsort_b(int end, t_conf *conf);
int					ft_insert_sort_b(t_conf *conf);
int					ft_clone_tab(int end, t_stack *first, t_conf *conf);

#endif
