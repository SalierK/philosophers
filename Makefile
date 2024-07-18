SRCS			= check_arg.c main.c ft_atoi.c time_and_check.c init.c philo_routine.c
OBJS			= $(SRCS:.c=.o)


CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror 
LIB_NAME			= philo.a
NAME				= philo

all:			$(NAME) 

$(NAME):		$(LIB_NAME)
				$(CC) $(CFLAGS) -o $(NAME) $(LIB_NAME)

$(LIB_NAME):		$(OBJS)
				ar rcs $(LIB_NAME) $(OBJS)

clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME) $(LIB_NAME)

re:				fclean $(NAME)


.PHONY:			all clean fclean re