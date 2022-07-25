/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:32:22 by midfath           #+#    #+#             */
/*   Updated: 2022/07/25 11:39:40 by midfath          ###   ########.fr       */
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

typedef struct timeval t_tempo;

struct s_parma ;

/*philospher*/
typedef	struct s_philo
{
	int				id;
	int				n_toeat;
	int				t_life;
	struct s_parma	*pram;
	size_t			t_death;
	pthread_t		t_id;
}	t_philo;

typedef struct s_parma 
{
	int					t_die;
	int					n_philo;
	int					t_eat;
	int					t_sleep;
	int					n_eat;
	int					p_end;
	size_t				t_spawn;
	t_philo				*philo;
	p_thread_mutex_t	*key;
	p_thread_mutex_t	output_key;
} t_parma;


/*initiale */
int	ft_initparma(char **av, t_parma *p);

/*convert the char number to an intger */
long	ft_up_atoi(char	*str);
int		ft_isdigit(int c);

/*intilais the rest of the struct and start creating mutexs and threads*/
int	ft_dining_philos(t_parma *p);

/*init forks mutex*/
int 	ft_startserving(t_parma *parm);

/*creat threads (phlasipha)*/
int		ft_spawn_philos(t_parma *p);

/*get the time in micro secondes*/
size_t	ft_time(t_philo *ph);

/*start pholo routin */
void *ft_start(void *ph);

/*routin to do by the philos*/
void *ft_routin(void *p);

/*lock the output while writing and unlocking it again*/
void	ft_thread_print(char *str, t_philo *ph);


#endif
