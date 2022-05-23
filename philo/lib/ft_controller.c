/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:37:15 by ahjadani          #+#    #+#             */
/*   Updated: 2022/05/23 17:41:00 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	ft_get_time(void)
{
	struct timeval	ct;

	gettimeofday(&ct, NULL);
	return (ct.tv_sec * 1000LL + ct.tv_usec / 1000);
}

void	*philo_routine(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	while (ph->data->not_dead)
	{
		philo_eating(ph);
		philo_sleeping(ph);
		philo_thinking(ph);
		usleep(190);
	}
	return (NULL);
}

void	*monitor(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	while (ph->data->not_dead)
	{
		if (ph->data->nb == 1)
		{
			usleep(ph->data->t_die * 1000);
			ft_print(ph->data, ph->id, "died", 1);
			ph->data->not_dead = 0;
			return (NULL);
		}
		if (ft_get_time() - ph->last_meal > ph->data->t_die)
		{
			ft_print(ph->data, ph->id, "died", 1);
			ph->data->not_dead = 0;
		}
		if (ph->data->eat_time == (ph->data->nb_me * ph->data->nb))
		{
			ft_print(ph->data, ph->id, "died", 1);
			ph->data->not_dead = 0;
		}
		usleep(190);
	}
	return (NULL);
}
