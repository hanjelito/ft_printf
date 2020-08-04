SRCS	= ft_atoi.c ft_calloc.c ft_isalpha.c ft_isdigit.c ft_putchar_fd.c ft_putchar.c ft_putnbr_fd.c ft_strlen.c ft_intlen.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= cc
RM		= rm -f
# CFLAGS	= -Wall -Werror -Wextra

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc  ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean
	
.PHONY: all clean fclean re