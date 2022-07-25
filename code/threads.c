/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:33:04 by midfath           #+#    #+#             */
/*   Updated: 2022/07/25 08:09:54 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_dining_philos(t_parma *p)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (i < p->n_philo)
	{
		p->philo[i].id = i;
		p->philo[i].t_life = 1;
		p->philo[i].n_toeat = 0;
		p->philo[i].t_death = p->t_spawn;
	}
	if (ft_startserving(p))
		return (0);
	ft_spawn_philos(p);
	return (1);
}

int	ft_spawn_philos(t_parma *p)
{
	int			i;
	t_philo		*ph;
	pthread_t	output;
	
	i = 0;
	p->t_spawn = ft_time(NULL);
	while (i < p->n_philo)
	{
		ph = &p->philo[i];
		if(pthread_create(&(p->philo[i].t_id), NULL, ft_start, ph))
			return (printf(" \033[1;31m Couldent creat the philos\n" DEFAULT));
		pthread_create(&output, NULL, ft_routin, p);
		
		i++;
	}
	return (1);
}