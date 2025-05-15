CC = cc
FLAG = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f
NAME = pushswap.a

SRCS = mane.c
OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
		$(AR) $@ $^

clean:
		$(RM) $(OBJS)

fclean:
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
