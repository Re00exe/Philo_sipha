/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:57:24 by midfath           #+#    #+#             */
/*   Updated: 2022/08/09 19:26:50 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

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

int 	ft_start_serving(t_parma *parm)
{
	int i;
		i = 0;
	if (pthread_mutex_init(&(parm->output_key) ,NULL))
		return(1);
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
		return;
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

int	f_race(t_parma *p)
{
	int	cmp;
	
	pthread_mutex_lock(&p->l);
	cmp = !p->p_end;
	pthread_mutex_unlock(&p->l);
	return (cmp);
}

void	*ft_start(void *ph)
{
	t_philo *rp;

	rp = (t_philo *)ph;
	while (f_race(rp->pram))
	{
	 	lock_forks(rp, rp->id);
		if (rp->pram->n_philo == 1)
			break;
		ft_thread_print(PHILO_EATING, rp);
	 	usleep(rp->pram->t_eat * 1000);
		unlock_forks(rp, rp->id);
		ft_thread_print(PHILO_SLEEP, rp);
		usleep(rp->pram->t_sleep * 1000);
		ft_thread_print(PHILO_THINK, rp);
	}
return (NULL);
}
