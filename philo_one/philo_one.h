/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:15:30 by pcatrina          #+#    #+#             */
/*   Updated: 2020/12/15 11:15:32 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

//DELETE
# include <stdio.h>
//MAIN
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>

//STATUS
# define PH_TAKE_FORK 0
# define PH_PUT_FORK 1
# define PH_EAT	3
# define PH_SLEEPING 4
# define PH_THINKING 5
# define PH_DEAD 6
# define PH_BUFF 50
# define PH_MON_DEL 500

//ERRORS
# define PH_ERROR_INIT "error: "
# define PH_FATAL_ER "FATAL ERROR"
# define PH_ER_NUM_ARG "wrong numbers of arguments"
# define PH_ER_ARG_NOT_DIG "argumets not a digit"
# define PH_ER_FEW_PHIL "need more philosophers"
# define PH_ER_EAT_NUM "philosophers must eat"

typedef struct		s_philo
{
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	pthread_mutex_t eat_time_mutex;
	pthread_t		philo_tread;
	pthread_t 		monitoring_thread;
	int				i;
	int				num_of_eat;
	int				last_time_eat;
}					t_philo;

typedef struct		s_data
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_to_eat;
	t_philo 		*philo;
	pthread_mutex_t out_mutex;
	int				if_some_philo_die;
	long			start_time;
}					t_data;

extern t_data		g_data;

//MAIN
int					read_instructions(int ac, char **av);
int					ph_error(char *msg);
int					philo_init(void);
int 				ph_time(void);
void				destroy_phil(void);
void				ph_treads(void);
void				ph_threads_join(void);
void				*ph_life(void *philo);
void				*ph_monitor(void *philo);
void				swap_status(int status, t_philo *philo);
void				ph_write_status(int time, int status, t_philo *philo);


//UTILS
size_t				ft_strlen(const char *s);
int					ft_isdigit(int c);
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t len);
void				ft_putsrt_to_buf(char *str, char *buf);
char				*ft_itoa(int n);
void				ft_free_str(char *str);


# endif //PHILO_ONE_H