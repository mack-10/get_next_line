CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	get_next_line
SRCS		=	get_next_line.c			\
			get_next_line_utils.c		\
			main.c
OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $@ $^ 

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
