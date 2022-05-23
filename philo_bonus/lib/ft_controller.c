/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:37:15 by ahjadani          #+#    #+#             */
/*   Updated: 2022/05/23 17:51:37 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_actions(t_philo *ph)
{
	philo_eating(ph);
	philo_sleeping(ph);
	philo_thinking(ph);
	usleep(100);
}

void	*philo_routine(void *data)
{
	t_philo	*ph;
	int		i;

	ph = (t_philo *)data;
	i = ph->data->nb_me;
	if (i > 0)
	{
		while (ph->data->nb_me + 1 >= (int)ph->data->eat_time)
			ft_actions(ph);
	}
	else
	{
		while (1)
			ft_actions(ph);
	}
	return (exit(1), NULL);
}

void	*monitor(void *data)
{
	t_philo	*ph;
	int		i;

	i = 0;
	ph = (t_philo *)data;
	while (1)
	{
		sem_wait(ph->eating);
		if ((int)ph->data->eat_time >= ph->data->nb_me + 1
			&& ph->data->nb_me != -42)
		{
			ft_print(ph->data, ph->id, "died", 1);
		}
		if (ft_get_time() - ph->last_meal >= ph->data->t_die)
			ft_print(ph->data, ph->id, "died", 1);
		sem_post(ph->eating);
		usleep(100);
	}
	return (exit(0), NULL);
}
