SRCS	= ft_printf.c ft_printf_utils.c flag_di.c
OBJS	= ${SRCS:.c=.o}
#BSRCS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
#BOBJS	= ${BSRCS:.c=.o}
NAME	= libftprintf.a
CC		= cc
RM		= rm -f
#CFLAGS	= -Wall -Werror -Wextra
.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			ar rc  ${NAME} ${OBJS}
			ranlib ${NAME}
# bonus:		${BOBJS} ${OBJS}
# 			ar rc ${NAME} ${OBJS} ${BOBJS}
# 			ranlib ${NAME}
all:		${NAME}
clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}
re:			fclean all