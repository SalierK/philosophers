#if !defined(PHILO_H)            
#define PHILO_H

#include <pthread.h>
#include <unistd.h>

typedef struct s_philo
{
    int pnbr;
    int ttdie;
    int tteat;
    int ttsleep;
    int notepme;
} t_philo;

char	*ft_itoa(int n);
int	ft_numlen(int n, int base);
void intitilize_philos(philos_struct, argc, argv);
#endif
