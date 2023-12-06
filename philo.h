#if !defined(PHILO_H)            
#define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_philo
{
    int pnbr;
    int ttdie;
    int tteat;
    int ttsleep;
    int notepme;
    int error_state;
} t_philo;

void intitilize_philos(t_philo *philos_struct,int argc,char **argv);
int	ft_atoi(const char *str, t_philo *philo_struct);
#endif
