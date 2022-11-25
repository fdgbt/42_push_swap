/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:43:01 by fdagbert          #+#    #+#             */
/*   Updated: 2018/04/11 02:46:05 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *ptr;

	if (!(ptr = (char *)malloc(sizeof(*ptr) * size + 1)))
		return (NULL);
	else
	{
		ft_bzero(ptr, size + 1);
		return (ptr);
	}
}
