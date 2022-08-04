/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:57:24 by midfath           #+#    #+#             */
/*   Updated: 2022/08/04 12:54:51 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_thread_print(char *str, t_philo *ph)
{
	pthread_mutex_lock(&(ph->pram->output_key));
	if (!ph->pram->p_end)
		printf("%zu :Philo_%d %s", ft_time(ph), ph->id + 1, str);
	pthread_mutex_unlock(&(ph->pram->output_key));
}

int 	ft_start_serving(t_parma *parm)
{
	int i;
		i = 0;
	if (pthread_mutex_init(&(parm->output_key) ,NULL))
		return(1);
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
	pthread_mutex_lock(&(p->pram->key[(i + 1)
	% p->pram->n_philo]));
	ft_thread_print(PHILO_T_FORK, p);
}

void	unlock_forks(t_philo *p, int i)
{
	pthread_mutex_unlock(&(p->pram->key[i]));
	pthread_mutex_unlock(&(p->pram->key[(i + 1) 
	% p->pram->n_philo]));
}

void	*ft_start(void *ph)
{
	t_philo *rp;
	
	rp = (t_philo *)ph;
	while (!rp->pram->p_end)
	{		
	 	lock_forks(rp, rp->id);
	 	rp->t_death = ft_time(rp);
	 	rp->n_toeat++;
	 	if (rp->n_toeat == rp->pram->n_eat)
			rp->pram->p_full++;
		ft_thread_print(PHILO_EATING, rp);
	 	usleep(rp->pram->t_eat * 1000);
		unlock_forks(rp, rp->id);
		ft_thread_print(PHILO_SLEEP, rp);
		usleep(rp->pram->t_sleep * 1000);
		ft_thread_print(PHILO_THINK, rp);
	}
return (NULL);
}

void	*ft_refresh(void *p)
 {
 	
 	ft_thread_print( , )
 }