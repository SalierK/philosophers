SRCS			= create_philo.c death_checks.c philo_utils.c phlilo_init.c phliodeneme.c work_philo.c
OBJS			= $(SRCS:.c=.o)


CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=address
NAME			= philo

all:			$(NAME) 

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME)
				
re:				fclean $(NAME)

.PHONY:			all clean fclean re