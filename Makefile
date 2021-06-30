# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 16:26:22 by rotrojan          #+#    #+#              #
#    Updated: 2021/06/30 19:50:11 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_DIR = srcs
OBJS_DIR = .objs

NAME = push_swap
SRCS = main.c \
	parsing.c \
	operations.c \
	operations_utils.c \
	stack_utils.c \
	sort_utils.c \
	sort_stack.c
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
DEPENDENCIES = $(OBJS:%.o=%.c)

CHECKER_NAME = checker
CHECKER_SRCS = checker_main.c
CHECKER_OBJS = $(CHECKER_SRCS:%.c=$(OBJS_DIR)/%.o)
CHECKER_DEPENDENCIES = $(CHECKER_OBJS:%.o=%.c)

CC = clang
MKDIR = mkdir -p
RM = rm -f

LIBS = ft

CFLAGS = -MMD -Wall -Wextra -Werror -I includes/ -I libft/includes/
LDFLAGS = -L libft/ -lft

vpath %.c $(addprefix $(SRCS_DIR), /. /c)

all:
	$(foreach LIB, $(LIBS), $(MAKE) -C lib$(LIB) ;)
	$(MAKE) $(NAME)

$(NAME): $(OBJS) | $(LIBS:%=lib%.a)
	$(CC) $^ -o $@ $(LDFLAGS)

bonus :
	$(MAKE) $(CHECKER_NAME)

$(CHECKER_NAME): $(OBJS_BONUS) | $(LIBS:%=lib%.a)
	$(CC) $^ -o $@ $(LDFLAGS)

lib%.a:
	$(foreach LIB, $(LIBS), $(MAKE) -C lib$(LIB) ;)
	$(MAKE) -C $(@:%.a=%)

-include $(DEPENDENCIES) $(CHECKER_DEPENDENCIES)
$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $@

clean:
	$(RM) -r $(OBJS_DIR)
	$(foreach LIB, $(LIBS), $(MAKE) clean -C lib$(LIB) ;)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)
	$(foreach LIB, $(LIBS), $(MAKE) fclean -C lib$(LIB) ;)

re: fclean all

.PHONY: all clean fclean re bonus
