/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:30:36 by midfath           #+#    #+#             */
/*   Updated: 2022/08/13 13:03:43 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_check_digit(char **av)
{
	int	j;

	j = 1;
	while (av[j])
	{
		if (ft_up_atoi(av[j]) > INT_MAX || ft_up_atoi(av[j]) < INT_MIN)
			return (-1);
		j++;
	}
	return (1);
}

int	ft_initparma(char **av, t_parma *p)
{
	if (ft_check_digit(av) == -1)
	{
		printf("Invalid arguments !!! \n");
		free(p);
		return (0);
	}	
	p->n_philo = ft_atoi(av[1]);
	p->t_die = ft_atoi(av[2]);
	p->t_eat = ft_atoi(av[3]);
	p->t_sleep = ft_atoi(av[4]);
	p->p_end = 0;
	p->p_full = 0;
	if (av[5])
		p->n_eat = ft_atoi(av[5]);
	else
		p->n_eat = -1;
	return (1);
}

int	main(int ac, char **av)
{
	int			i;
	t_parma		*p;

	i = 1;
	p = NULL;
	if (!(ac == 5 || ac == 6))
		return (printf("Arguments !!!\n"));
	while (i < ac)
	{
		if (ft_atoi(av[i]) <= 0 && i == 1)
			return (printf(" \033[1;31m NO PhiLosoPhers\n" DEFAULT));
		p = malloc(sizeof(t_parma));
		if (!p)
			return (printf(" \033[1;31m NO MeMory\n" DEFAULT));
		if (!ft_initparma(av, p))
			return (printf(" \033[1;31m Parsing error\n" DEFAULT));
		i++;
	}
	if (ft_philos(p))
		printf("Error {init_phase}\n");
	ft_track(p);
	ft_endthreads(p);
	return (0);
}
