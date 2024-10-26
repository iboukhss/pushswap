CFLAGS := -Wall -Wextra -g3 -fsanitize=undefined,address

NAME := push_swap

SRCS := ps_main.c \
        s_stack.c s_stack_push.c s_stack_pop.c

OBJS := $(SRCS:.c=.o)
DEPS := $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
