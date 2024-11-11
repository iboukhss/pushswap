CFLAGS := -Wall -Wextra -Werror
#CFLAGS += -g3 -fsanitize=undefined,address -MMD

NAME := push_swap

SRCS := ps_main.c ps_parse.c ps_sort.c ps_sort_small.c \
        s_stack.c s_stack_push.c s_stack_pop.c s_stack_peek.c \
        ps_push_ops.c ps_rotate_ops.c \
        ps_chunk.c ps_chunk_push.c ps_chunk_pop.c \
        ps_state.c ps_state_push.c ps_state_pop.c \
        ft_printf.c ft_puts.c \
        ft_memcpy.c ft_memmove.c ft_realloc.c ft_strdup.c ft_strndup.c \
        ft_atoi.c strv_split.c strv_dup.c intv_parse.c \
        ft_quicksort.c

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
