/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:44:39 by shoudek           #+#    #+#             */
/*   Updated: 2024/01/23 14:25:23 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

int			ft_printf(const char *format, ...);
void		ft_putstr(char *s, int *ptr_sum);
void		ft_putnbr(int n, int *ptr_sum);
void		ft_putchar(char c, int *ptr_sum);
void		ft_puthex(uintptr_t num, const char *format, int *ptr_sum);
const char	*ft_format(const char *format, int *ptr_sum, va_list args);
void		ft_putunsnbr(unsigned int n, int *ptr_sum);
void		ft_handleptr(uintptr_t num, const char *format, int *ptr_sum);

#endif
