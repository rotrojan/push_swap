# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 16:26:22 by rotrojan          #+#    #+#              #
#    Updated: 2021/06/24 20:35:03 by bigo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c \
	parsing.c \
	operations.c \
	operations_utils.c \
	sort_utils.c \
	sort_stack.c

SRCS_DIR = srcs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_DIR = .objs

DEPENDENCIES = $(OBJS:%.o=%.c)

CC = clang
MKDIR = mkdir -p
RM = rm -f

LIBS = ft

CFLAGS = -MMD -Wall -Wextra -Werror -I includes/ -I libft/includes/
LDFLAGS = -L libft/ -lft

vpath %.c $(addprefix $(SRCS_DIR), /. )

all:
	$(foreach LIB, $(LIBS), $(MAKE) -C lib$(LIB) ;)
	$(MAKE) $(NAME)

$(NAME): $(OBJS) | $(LIBS:%=lib%.a)
	$(CC) $^ -o $@ $(LDFLAGS)

lib%.a:
	$(MAKE) -C $(@:%.a=%)

-include $(DEPENDENCIES)
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
