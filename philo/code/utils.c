/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:57:24 by midfath           #+#    #+#             */
/*   Updated: 2022/08/18 11:16:56 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_exact(size_t waist)
{
	size_t	time;

	time = ft_time(NULL);
	while (ft_time(NULL) - time < waist)
		usleep(10);
}

void	ft_thread_print(char *str, t_philo *ph)
{
	pthread_mutex_lock(&(ph->pram->output_key));
	pthread_mutex_lock(&ph->pram->l);
	if (!strcmp(str, PHILO_EATING))
	{	
		ph->t_death = ft_time(ph);
		ph->n_toeat++;
	}
	if (!ph->pram->p_end)
		printf("%zu :Philo_%d %s", ft_time(ph), ph->id + 1, str);
	pthread_mutex_unlock(&ph->pram->l);
	pthread_mutex_unlock(&(ph->pram->output_key));
}

int	ft_start_serving(t_parma *parm)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(parm->output_key), NULL))
		return (1);
	pthread_mutex_init(&parm->l, NULL);
	while (i < parm->n_philo)
	{
		if (pthread_mutex_init(&(parm->key[i]), NULL))
			return (1);
		i++;
	}
	return (0);
}

void	lock_forks(t_philo *p, int i)
{
	pthread_mutex_lock(&(p->pram->key[i]));
	ft_thread_print(PHILO_T_FORK, p);
	if (p->pram->n_philo == 1)
	{	
		pthread_mutex_lock(&p->pram->l);
		p->t_death = ft_time(p);
		pthread_mutex_unlock(&p->pram->l);
		return ;
	}
	pthread_mutex_lock(&(p->pram->key[(i + 1) \
	% p->pram->n_philo]));
	ft_thread_print(PHILO_T_FORK, p);
}

void	unlock_forks(t_philo *p, int i)
{
	pthread_mutex_unlock(&(p->pram->key[i]));
	pthread_mutex_unlock(&(p->pram->key[(i + 1) \
	% p->pram->n_philo]));
}
