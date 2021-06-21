PUSH_SWAP_NAME=	push_swap
CHECKER_NAME=	checker

PUSH_SWAP_SRCS=	push_swap.c	ft_sorting.c	ft_sorting2.c
PUSH_SWAP_OBJS=	$(PUSH_SWAP_SRCS:%.c=%.o)

CHECKER_SRCS=	checker.c
CHECKER_OBJS=	$(CHECKER_SRCS:%.c=%.o)

GLOBAL_SRCS=	ft_parsing.c	sort_list.c	sort.c	sort2.c	sort3.c
GLOBAL_OBJS=	$(GLOBAL_SRCS:%.c=%.o)

DEP=	$(PUSH_SWAP_OBJS:%.o=%.d)	$(CHECKER_OBJS:%.o=%.d)	$(GLOBAL_OBJS:%.o=%.d)

CC=	clang

CFLAGS=	-MMD -Wall -Wextra -Werror
CXXFLAGS=	-I includes/ -I libft/includes/ -I libgc/includes/
LDFLAGS=	-L libft/ -lft -L libgc/ -lgc

vpath %.c	push_swap_file checker_file global_file

all: lib $(PUSH_SWAP_NAME) $(CHECKER_NAME)

lib:
	$(MAKE) -C libgc
	$(MAKE) -C libft

$(CHECKER_NAME): $(CHECKER_OBJS) $(GLOBAL_OBJS) | lib
	$(CC) $(CXXFLAGS) $^ -o $(CHECKER_NAME) $(LDFLAGS)

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJS) $(GLOBAL_OBJS) | lib
	$(CC) $(CXXFLAGS) $^ -o $(PUSH_SWAP_NAME) $(LDFLAGS)

-include $(DEP)
%.o: %.c
	$(CC) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(CHECKER_OBJS) $(GLOBAL_OBJS) $(PUSH_SWAP_OBJS) $(DEP)
	$(MAKE) clean -C libft
	$(MAKE) clean -C libgc

fclean: clean
	rm -f $(CHECKER_NAME) $(PUSH_SWAP_NAME)
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C libgc

re: fclean all