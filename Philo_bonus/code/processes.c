/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:20:24 by midfath           #+#    #+#             */
/*   Updated: 2022/08/16 18:43:36 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	end_philo(t_parma *p)
{
	int	s;
	int	i;

	while (waitpid(-1, &s, 0) != -1)
	{
		i = 0;
		if (s != 0)
		{
			while (i < p->n_philo)
			{
				kill(p->philo[i].pro, SIGKILL);
				i++;
			}
		}
		sem_close(p->sem);
	}
	free(p->philo);
	free(p);
	p->philo = NULL;
	p = NULL;
}

int	init_philos(t_parma *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	p->philo = (t_philo *)malloc(p->n_philo * sizeof(t_philo));
	if (!p->philo)
		return (1);
	while (i < p->n_philo)
	{
		p->philo[i].id = i;
		p->philo[i].n_toeat = 0;
		p->philo[i].t_death = p->t_spawn;
		p->philo[i].wasted = 0;
		p->philo[i].pram = p;
		i++;
	}
	if (serving(p))
		return (1);
	if (spawn_philos(p))
		return (1);
	return (0);
}

int	spawn_philos(t_parma *p)
{
	int	i;

	i = 0;
	p->t_spawn = ft_bs_time(NULL);
	while (i < p->n_philo)
	{
		p->philo[i].pram = p;
		p->philo[i].pro = fork();
		if (p->philo[i].pro == 0)
		{
			ft_bs_start(&p->philo[i]);
			i++;
			usleep(100);
		}
		i++;
	}
	return (0);
}

void	ft_bs_start(t_philo *ph)
{
	pthread_t	track;

	pthread_create(&track, NULL, death_track, ph);
	while (1)
	{
		ft_bs_lforks(ph);
		if (ph->pram->n_philo == 1)
			break ;
		ft_bs_thread_print(PHILO_EATING, ph);
		ph->t_death = ft_bs_time(ph);
		ph->n_toeat++;
		usleep(ph->pram->t_eat * 1000);
		ft_bs_uforks(ph);
		if (ph->n_toeat == ph->pram->n_eat)
			exit(0);
		ft_bs_thread_print(PHILO_SLEEP, ph);
		usleep(ph->pram->t_sleep * 1000);
		ft_bs_thread_print(PHILO_THINK, ph);
	}
	pthread_join(track, NULL);
	if (ph->wasted)
		exit(1);
}
