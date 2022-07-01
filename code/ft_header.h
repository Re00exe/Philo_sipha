/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:32:22 by midfath           #+#    #+#             */
/*   Updated: 2022/06/30 16:47:09 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

# define DEFAULT "\033[0;39m"

# define PHILO_T_FORK " \033[1;32m  has taken a fork\n \033[0;39m"
# define PHILO_EATING " \033[1;36m  is eating\n \033[0;39m"
# define PHILO_SLEEP " \033[1;35m  is sleeping\n \033[0;39m"
# define PHILO_THINK " \033[1;36m  is thinking\n  \033[0;39m"
# define PHILO_DIE  " \033[1;30m died\n \033[0;39m"

/*utils*/
int	ft_atoi(const char *str);

/*philospher*/

typedef struct s_parma 
{
	int	n_philo;
	int t_die;
	int	t_eat;
	int t_sleep;
	int	t_neat;
	int	p_end;
	

} t_parma;

/*initiale */
int	ft_initphil(char **av, t_parma *p);

/*convert the char number to an intger */
long	ft_up_atoi(char	*str);
int	ft_isdigit(int c);
/*creart philos and star them*/
void	ft_dining_philos(t_parma *p);

#endif
