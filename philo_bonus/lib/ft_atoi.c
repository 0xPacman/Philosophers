/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:31:35 by ahjadani          #+#    #+#             */
/*   Updated: 2022/05/23 11:46:26 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void ft_is_valid(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            ft_error_handler();
        i++;
    }
}

int ft_num_check(long nb)
{
	if (nb < 1 || nb > 2147483647)
		return (0);
	return (1);
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
	if (ft_num_check(sum * sign) == 0)
		ft_error_handler();
	return (sum * sign);
}