CFLAGS += -Wall -Wextra -g3 -fsanitize=undefined,address

all: push_swap

push_swap: ps_main.o s_stack.o s_stack_push.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) push_swap *.o
