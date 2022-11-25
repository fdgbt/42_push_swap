/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:12:03 by fdagbert          #+#    #+#             */
/*   Updated: 2019/02/28 21:59:07 by stin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <time.h>

typedef unsigned char	t_byte;

void					ft_bzero(void *s, size_t n);
void					*ft_memset(void *s, int c, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
size_t					ft_strlen(const char *s);
size_t					ft_wcslen(const wchar_t *s);
int						ft_islower(int c);
int						ft_isdigit(int c);
int						ft_toupper(int c);
int						ft_atoi(const char *str);
char					*ft_strupcase(char *str);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strncat(char *dest, const char *src, size_t n);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strnew(size_t size);
char					*ft_strchr(const char *s, int c);
char					*ft_strjoin(const char *s1, char const *s2);
int						ft_get_next_line(const int fd, char **line);
int						ft_delay(time_t seconds);
intmax_t				ft_atoim(const char *str);

#endif
