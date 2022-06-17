/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:30:36 by midfath           #+#    #+#             */
/*   Updated: 2022/06/17 12:36:23 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
	p->n_philo = ft_up_atoi(av[1]);
	p->t_die = ft_up_atoi(av[2]);
	p->t_eat = ft_up_atoi(av[3]);
	p->t_sleep = ft_up_atoi(av[4]);

int	ft_check(char *av[])
{
	int j;
	
	j = 0;
	while ((ft_isdigit(av[j])))
		j++;
	return (1);
}

void	ft_initphilo(char **av, t_parma *p)
{
	int	i;

	i = 0;
	if (ft_check(av[i]) == -1)
		return(printf("invalid type of arguments"));
	
	if (av[5])
		p->t_neat = ft_atoi(av[5]);
	else
		p->t_neat = -1;
}

int main(int ac, char **av)
{
	int 		i;
	t_parma		*p;

	i = 1;
	p = NULL;
	if (ac == 5 || ac == 6)
	{
		while (i < ac)
		{
			if (ft_atoi(av[i]) <= 0 && i == 1)
				return (printf(" \033[1;31m NO PhiLosoPhers\n" DEFAULT));
			p = malloc(sizeof(t_parma));
			memset(p, 0, sizeof(t_parma));
			ft_pars(av , p);
			i++;
		}
	printf("%d\n", p->n_philo);
	printf("%d\n", p->t_die);
	printf("%d\n", p->t_eat);
	printf("%d\n", p->t_sleep);
	printf("%d\n", p->t_neat);
	}
	else
		printf("Arguments !!!");
	return (0);
}