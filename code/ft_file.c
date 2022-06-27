/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:56:01 by midfath           #+#    #+#             */
/*   Updated: 2022/06/21 12:08:33 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_check(unsigned long long num, int sign)
{
	if (num > LLONG_MAX)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return ((int)num * sign);
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	nb;
	int					sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb = (nb * 10) + str[i] - '0';
		i++;
	}
	return (ft_check(nb, sign));
}

long	ft_up_atoi(char *str)
{
	int				i;
	unsigned long	nb;
	int				sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb = (nb * 10) + str[i] - '0';
		if (nb > INT_MAX)
			return (nb * sign);
		i++;
	}
	if (str[i] || i == 0 || (i && !ft_isdigit(str[i - 1])))
		return ((long)INT_MAX + 1);
	return (nb * sign);
}