# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 16:26:22 by rotrojan          #+#    #+#              #
#    Updated: 2021/07/05 00:00:50 by bigo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = srcs
OBJS_DIR = .objs

NAME = push_swap
SRCS = main.c \
	radix_sort.c \
	insertion_sort.c \
	sort_stack.c
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
DEPENDENCIES = $(OBJS:%.o=%.d)

CHECKER_NAME = checker
CHECKER_SRCS = checker_main.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c
CHECKER_OBJS = $(CHECKER_SRCS:%.c=$(OBJS_DIR)/%.o)
CHECKER_DEPENDENCIES = $(CHECKER_OBJS:%.o=%.d)

COMMON_SRCS = parsing.c \
	operations_utils.c \
	sort_checks.c \
	operations.c \
	sort_utils.c \
	stack_utils.c
COMMON_OBJS = $(COMMON_SRCS:%.c=$(OBJS_DIR)/%.o)
COMMON_DEPENDENCIES = $(COMMON_OBJS:%.o=%.d)

CC = clang
MKDIR = mkdir -p
RM = rm -f

LIBS = ft

CFLAGS = -MMD -Wall -Wextra -Werror -I includes/ -I libft/includes/
LDFLAGS = -L libft/ -lft

vpath %.c $(addprefix $(SRCS_DIR), /. /checker)

all:
	$(foreach LIB, $(LIBS), $(MAKE) -C lib$(LIB) ;)
	$(MAKE) $(NAME)
	$(MAKE) $(CHECKER_NAME)

$(NAME): $(OBJS) $(COMMON_OBJS)| $(LIBS:%=lib%.a)
	$(CC) $^ -o $@ $(LDFLAGS)

bonus :
	$(MAKE) $(CHECKER_NAME)

$(CHECKER_NAME): $(CHECKER_OBJS) $(COMMON_OBJS) | $(LIBS:%=lib%.a)
	$(CC) $^ -o $@ $(LDFLAGS)

lib%.a:
	$(foreach LIB, $(LIBS), $(MAKE) -C lib$(LIB) ;)
	$(MAKE) -C $(@:%.a=%)

-include $(DEPENDENCIES) $(CHECKER_DEPENDENCIES) $(COMMON_DEPENDENCIES)
$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $@

clean:
	$(RM) -r $(OBJS_DIR)
	$(foreach LIB, $(LIBS), $(MAKE) clean -C lib$(LIB) ;)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(CHECKER_NAME)
	$(foreach LIB, $(LIBS), $(MAKE) fclean -C lib$(LIB) ;)

re: fclean all

.PHONY: all clean fclean re bonus
