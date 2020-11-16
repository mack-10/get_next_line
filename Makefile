CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	get_next_line
SRCS		=	get_next_line.c				\
				get_next_line_utils.c
BONUS_SRCS	=	get_next_line_bonus.c		\
				get_next_line_utils_bonus.c
OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $@ $^ 

bonus : $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(NAME) $^ 

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all