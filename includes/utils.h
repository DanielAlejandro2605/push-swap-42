/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:19:21 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/18 15:19:21 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <fcntl.h>
# define BUFFER_SIZE 10

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *str, char c);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin_secure(char *s1, char *s2);
int		ft_strlen_int(char *s);
/*
All prototypes functions of ft_printf project.
Directory : ft_printf
*/
int		ft_printf(const char *str, ...);
int		ft_get_format(va_list args, const char format);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int nbr);
int		ft_puthex(unsigned int hex, char format);
int		ft_len_unsigned(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		ft_put_unsigned(unsigned int n);
int		ft_len_ptr(unsigned long long int_pointer);
void	ft_put_ptr(unsigned long long int_pointer);
int		ft_print_ptr(unsigned long long int_pointer);

/*
All prototypes functions of get_next_line project.
Directory : gnl
*/
char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *response);
char	*ft_get_line(char *buffer);
char	*ft_concatenation(char *res_buff_static, char *buff_file);
char	*ft_advance_buffer(char *buff);
#endif