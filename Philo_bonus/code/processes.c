/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:20:24 by midfath           #+#    #+#             */
/*   Updated: 2022/08/14 11:09:36 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int init_philos(t_parma *p)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	p->philo = (t_philo *)malloc(p->n_philo * sizeof(t_philo));
    if (!p->philo)
        return (1);
	while (i < p->n_philo)
	{
		p->philo[i].id = i;
		p->philo[i].t_life = 1;
		p->philo[i].n_toeat = 0;
		p->philo[i].t_death = p->t_spawn;
		i++;
	}
	if (serving(p))
		return (1);
	else if (spawn_philos(p))
		return (1);
	return (0);
}

int	spawn_philos(t_parma *p)
{
	int	i;
	
	i = 0;
	while (i < p->n_philo)
	{
		p->philo[i].pro = fork();
		
	}
	
}