/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:31:35 by ahjadani          #+#    #+#             */
/*   Updated: 2022/05/23 18:14:05 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error_handler();
		i++;
	}
}

int	ft_atoi(const char *str)
{
	long		sum;
	long		sign;
	long		i;

	sum = 0;
	sign = 1;
	i = 0;
	ft_is_valid((char *)str);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		sum = sum * 10 + str[i] - 48;
		i++;
	}
	if ((sum * sign) > 2147483647 || ((sum * sign) < -2147483648))
		ft_error_handler();
	return (sum * sign);
}
