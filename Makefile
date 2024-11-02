CFLAGS := -Wall -Wextra -g3 -fsanitize=undefined,address -MMD

NAME := push_swap

SRCS := ps_main.c \
        ps_push_ops.c ps_rotate_ops.c \
        ps_state.c ps_state_push.c ps_state_pop.c \
        ps_chunk.c ps_chunk_push.c ps_chunk_pop.c ps_sort.c \
        s_stack.c s_stack_push.c s_stack_pop.c s_stack_peek.c \
        ft_quicksort.c \
        dbg_main.c

INCS := ps_main.h s_stack.h

OBJS := $(SRCS:.c=.o)
DEPS := $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

norm:
	-norminette $(SRCS) $(INCS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all norm clean fclean re
