/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:20:24 by midfath           #+#    #+#             */
/*   Updated: 2022/08/13 13:13:35 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int ft_philos(t_parma *p)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	p->philo = malloc(p->n_philo * sizeof(t_philo));
	while (i < p->n_philo)
	{
		p->philo[i].id = i;
		p->philo[i].t_life = 1;
		p->philo[i].n_toeat = 0;
		p->philo[i].t_death = p->t_spawn;
		i++;
	}
	if (ft_start_serving(p))
		return (1);
	else if (ft_spawn_philos(p))
		return (1);
	return (0);
}