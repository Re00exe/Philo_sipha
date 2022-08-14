/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:57:24 by midfath           #+#    #+#             */
/*   Updated: 2022/08/13 19:25:27 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	exact(size_t waist)
{
	size_t	time;

	time = ftbs_time(NULL);
	while (ftbs_time(NULL) - time < waist)
		usleep(300);
}

// void	ft_thread_print(char *str, t_philo *ph)
// {
// 	//TODO : sem
// 	if (!strcmp(str, PHILO_EATING))
// 	{	
// 		ph->t_death = ft_time(ph);
// 		ph->n_toeat++;
// 	}
// 	if (!ph->pram->p_end)
// 		printf("%zu :Philo_%d %s", ft_time(ph), ph->id + 1, str);
// //TODO : sem
// }

int	serving(t_parma *parm)
{
	sem_unlink("sem_output");
	if (sem_open("sem_output", O_CREAT, O_RDWR))
		return (1);
	sem_unlink("sem_key");
	parm->sem = sem_open("sem_key", O_CREAT, O_RDWR, parm->n_philo);
	if (!parm->sem)
		return (1);
	return (0);
}

