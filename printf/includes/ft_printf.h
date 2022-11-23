/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:13:02 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/18 15:49:27 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
void	ft_putnbr_fd(int n, int fd);
int		size_put_argid(int n);
int		size_put_str(char *s);
int		size_put_adr(unsigned long long adr);
int		size_put_unsi(unsigned int n);
int		ft_printf(const char *str, ...);

#endif