/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:32:22 by midfath           #+#    #+#             */
/*   Updated: 2022/08/11 17:21:08 by midfath          ###   ########.fr       */
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

# define PHILO_T_FORK "\033[1;32mhas taken a fork\n\033[0;39m"
# define PHILO_EATING "\033[1;36mis eating\n\033[0;39m"
# define PHILO_SLEEP "\033[1;35mis sleeping\n\033[0;39m"
# define PHILO_THINK "\033[1;36mis thinking\n\033[0;39m"
# define PHILO_DIE  "\033[1;30mdied\n \033[0;39m"

typedef struct timeval	t_tempo;

struct					s_parma;

/*philospher*/
typedef struct s_philo
{
	int				id;
	int				t_life;
	int				n_toeat;
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
	int					p_full;
	size_t				t_spawn;
	t_philo				*philo;
	pthread_mutex_t		*key;
	pthread_mutex_t		output_key;
	pthread_mutex_t		l;

}		t_parma;

/*convert the char number to an intger */
int		ft_atoi(const char *str);
long	ft_up_atoi(char	*str);
int		ft_isdigit(int c);

/*initiale */
int		ft_initparma(char **av, t_parma *p);

/*intilais the rest of the struct and start creating mutexs and threads*/
int		ft_dining_philos(t_parma *p);

/*init forks mutex*/
int		ft_start_serving(t_parma *parm);

/*creat threads (phlasipha)*/
int		ft_spawn_philos(t_parma *p);

/*get the time in micro secondes*/
size_t	ft_time(t_philo *ph);

/*start pholo routin */
void	*ft_start(void *ph);

/*lock the output while writing and unlocking it again*/
void	ft_thread_print(char *str, t_philo *ph);

/*joining threads and free them all */
int		ft_endthreads(t_parma *p);
/* check the death of a philo and end the program */
void	*to_the_death(void *p);

/*check if the philos ate all their  meals and end the program*/
void	ft_track(t_parma *p);

int		f_race(t_parma *p);

void	ft_exact(size_t waist);

void	ft_dead(t_parma *p);

void	lock_forks(t_philo *p, int i);

void	unlock_forks(t_philo *p, int i);

#endif
