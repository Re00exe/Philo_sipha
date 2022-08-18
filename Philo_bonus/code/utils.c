/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:57:24 by midfath           #+#    #+#             */
/*   Updated: 2022/08/18 12:16:12 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	*death_track(void *p)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)p;
	i = 0;
	while (!philo->pram->p_end)
	{
		if (philo->pram->t_die + philo->t_death < ft_bs_time(philo))
		{
			philo->pram->p_end = 1;
			sem_wait(philo->pram->sem_out);
			printf("\033[0;39m%zu :Philo_%d %s", \
			ft_bs_time(p), philo->id + 1, PHILO_DIE);
			exit (1);
		}
		i++;
	}
	return (NULL);
}

void	ft_bs_thread_print(char *str, t_philo *ph)
{
	sem_wait(ph->pram->l);
	sem_wait(ph->pram->sem_out);
	if (!ph->pram->p_end)
		printf("\033[0;39m%zu :Philo_%d %s", ft_bs_time(ph), ph->id + 1, str);
	sem_post(ph->pram->sem_out);
	sem_post(ph->pram->l);
}

int	serving(t_parma *parm)
{
	sem_unlink("pro_per");
	sem_unlink("fork_key");
	sem_unlink("data");
	parm->l = sem_open("data", O_CREAT, 0644, 1);
	parm->sem_out = sem_open("pro_per", O_CREAT, 0644, 1);
	if (parm->sem_out == SEM_FAILED)
		return (1);
	parm->sem = sem_open("fork_key", O_CREAT, 0664, parm->n_philo);
	if (parm->sem == SEM_FAILED)
		return (1);
	return (0);
}

void	ft_bs_lforks(t_philo *p)
{
	sem_wait(p->pram->sem);
	ft_bs_thread_print(PHILO_T_FORK, p);
	if (p->pram->n_philo == 1)
		return ;
	sem_wait(p->pram->sem);
	ft_bs_thread_print(PHILO_T_FORK, p);
}

void	ft_bs_uforks(t_philo *p)
{
	sem_post(p->pram->sem);
	sem_post(p->pram->sem);
}
