/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 16:37:37 by pcatrina          #+#    #+#             */
/*   Updated: 2021/01/10 16:37:40 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <semaphore.h>

# define PH_TAKE_FORK 0
# define PH_EAT	3
# define PH_SLEEPING 4
# define PH_THINKING 5
# define PH_DEAD 6
# define PH_BUFF 100
# define PH_SEM_BUFF 50
# define PH_MON_DEL 5

# define PH_LINE_TAKE "has taken a fork"
# define PH_LINE_EAT "is eating"
# define PH_LINE_SLEEP "is sleeping"
# define PH_LINE_THINKING "is thinking"
# define PH_LINE_DEAD "died"

# define PH_ERROR_INIT "error: "
# define PH_FATAL_ER "FATAL ERROR"
# define PH_ER_NUM_ARG "wrong numbers of arguments"
# define PH_ER_ARG_NOT_DIG "argumets not a digit"
# define PH_ER_FEW_PHIL "need more philosophers"
# define PH_ER_EAT_NUM "philosophers must eat"

typedef struct		s_philo
{
	sem_t			*eat_time_sem;
	pthread_t		philo_tread;
	pthread_t		monitoring_thread;
	int				i;
	int				num_of_eat;
	long			last_time_eat;
}					t_philo;

typedef struct		s_data
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_to_eat;
	t_philo			*philo;
	sem_t			*forks;
	sem_t			*steward;
	sem_t			*out_sem;
	int				if_some_philo_die;
	long			start_time;
}					t_data;

extern t_data		g_data;

int					read_instructions(int ac, char **av);
int					ph_error(char *str);
int					philo_init(void);
long				ph_time(void);
void				destroy_phil(void);
void				ph_treads(void);
void				ph_threads_join(void);
void				*ph_life(void *philo);
void				*ph_monitor(void *philo);
void				ph_swap_status(int status, t_philo *philo);
void				ph_write_status(int time, int status, t_philo *philo);
void				ph_usleep(int msec);
int					*ph_open_sem(char *name, int i);
int					ph_open_main_sem(void);

size_t				ft_strlen(const char *s);
int					ft_isdigit(int c);
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t len);
void				ft_putsrt_to_buf(char *str, char *buf);
void				ft_putnbr_to_buf(int n, char *buf);

#endif
