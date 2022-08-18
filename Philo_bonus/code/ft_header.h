/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:32:22 by midfath           #+#    #+#             */
/*   Updated: 2022/08/18 11:40:44 by midfath          ###   ########.fr       */
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
# include <semaphore.h>
# include <signal.h>

# define DEFAULT "\033[0;39m"

# define PHILO_T_FORK "\033[1;32mhas taken a fork\n\033[0;39m"
# define PHILO_EATING "\033[1;36mis eating\n\033[0;39m"
# define PHILO_SLEEP "\033[1;35mis sleeping\n\033[0;39m"
# define PHILO_THINK "\033[1;36mis thinking\n\033[0;39m"
# define PHILO_DIE  "\033[1;30mdied\n\033[0;39m"

typedef struct timeval	t_tempo;

struct					s_parma;

/*philospher*/
typedef struct s_philo
{
	int				id;
	int				n_toeat;
	int				wasted;
	struct s_parma	*pram;
	size_t			t_death;
	pid_t			pro;
}	t_philo;

typedef struct s_parma
{
	int					t_die;
	int					n_philo;
	int					t_eat;
	int					p_end;
	int					t_sleep;
	int					n_eat;
	size_t				t_spawn;
	t_philo				*philo;
	sem_t				*sem;
	sem_t				*l;
	sem_t				*sem_out;

}		t_parma;

/*convert the char number to an intger */
int		ft_atoi(const char *str);
long	ft_up_atoi(char	*str);
int		ft_isdigit(int c);

/*initiale */
int		init_parma(char **av, t_parma *p);

/*init forks mutex*/
int		serving(t_parma *parm);

/*get the time in micro secondes*/
size_t	ft_bs_time(t_philo *ph);

/*start pholo routin */
void	ft_bs_start(t_philo *ph);

/*lock the output while writing and unlocking it again*/
void	ft_bs_thread_print(char *str, t_philo *ph);

/*end && free them all */
int		ft_bs_ends(t_parma *p);

/* check the death of a philo and end the program */
void	*death_track(void *p);

/*lock forks*/
void	ft_bs_lforks(t_philo *p);

/*init philos and creat the seam*/
int		init_philos(t_parma *p);

/*unlocck forks*/
void	ft_bs_uforks(t_philo *p);

/*creat philos and lunch routin	*/
int		spawn_philos(t_parma *p);

/*my attempt to make sleep fct more accuret*/
void	exact(size_t waist);
/*end */
void	ft_bs_dead(t_parma *p);

void	end_philo(t_parma *p);

#endif
