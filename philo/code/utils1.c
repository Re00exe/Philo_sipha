/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:09:11 by midfath           #+#    #+#             */
/*   Updated: 2022/08/11 17:17:52 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header.h"

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
	t_philo	*rp;

	rp = (t_philo *)ph;
	while (f_race(rp->pram))
	{
		lock_forks(rp, rp->id);
		if (rp->pram->n_philo == 1)
			break ;
		ft_thread_print(PHILO_EATING, rp);
		ft_exact(rp->pram->t_eat);
		unlock_forks(rp, rp->id);
		ft_thread_print(PHILO_SLEEP, rp);
		ft_exact(rp->pram->t_sleep);
		ft_thread_print(PHILO_THINK, rp);
	}
	return (NULL);
}

void	ft_dead(t_parma *p)
{
	int	i;

	i = 0;
	while (f_race(p) && i < p->n_philo)
	{
		pthread_mutex_lock(&p->l);
		if (ft_time(&p->philo[i]) >= p->t_die + p->philo[i].t_death)
		{
			pthread_mutex_lock(&(p->output_key));
			p->p_end = 1;
			printf("%zu :Philo_%d %s", ft_time(&p->philo[i]) \
			, i + 1, PHILO_DIE);
			pthread_mutex_unlock(&(p->output_key));
		}
		pthread_mutex_unlock(&p->l);
		i++;
	}
}
