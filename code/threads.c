/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:33:04 by midfath           #+#    #+#             */
/*   Updated: 2022/08/07 14:26:08 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_endthreads(t_parma *p)
{
	int i;
	
	i = 0;
	while (i < p->n_philo)
	{
		if(pthread_join(p->philo[i].t_id, NULL))
				return(1);
		pthread_mutex_destroy(&p->key[i]);
		i++;
	}
	pthread_mutex_destroy(&p->output_key);
	free(p->key);
	free(p->philo);
	free(p);
	return (0);
}

int	ft_dining_philos(t_parma *p)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	p->philo = malloc(p->n_philo * sizeof(t_philo));
	p->key = malloc(p->n_philo * sizeof(pthread_mutex_t));
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

int	ft_spawn_philos(t_parma *p)
{
	int			i;
	t_philo		*ph;
	pthread_t	track;
	
	i = 0;
	p->t_spawn = ft_time(NULL);
	while (i < p->n_philo)
	{
		ph = &p->philo[i];
		ph->pram = p;
		if(pthread_create(&(p->philo[i].t_id), NULL, ft_start, ph))
			return (1);
		pthread_create(&track, NULL, to_the_death, ph);
		pthread_detach(track);
		i++;
		usleep(100);
	}
	if (p->n_eat >= 0)
	{
		pthread_create(&track, NULL, ft_track, p);
		pthread_detach(track);
	}
	return (0);
}

void	*to_the_death(void *p)
 {
 	t_philo *ph;
	
	ph = p;
	while (!ph->pram->p_end)
	{
		if (ph->t_death + ph->pram->t_die < ft_time(ph))
		{
			ft_thread_print(PHILO_DIE, ph);
			ph->t_death = 1;
			ph->pram->p_end = 1;
		}
		usleep(100);
	}
	return (NULL);
 }
 
 void  *ft_track(void *p)
 {
	t_parma	*pr;
	
	pr = p;
	while (!pr->p_end)
	{
		if (pr->p_full == pr->n_philo)
			pr->p_end = 1;
					printf("here\n");
	}
	return (NULL);
}