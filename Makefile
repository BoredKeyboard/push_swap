# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mforstho <mforstho@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/09/14 13:15:52 by mforstho      #+#    #+#                  #
#    Updated: 2022/09/21 16:54:09 by mforstho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


NAME := push_swap
CC := gcc
CFLAGS ?= -Wextra -Wall -Werror

SOURCES :=									\
	src/lst/ps_stack_secondlast.c			\
	src/lst/ps_stackadd_back.c				\
	src/lst/ps_stackadd_front.c				\
	src/lst/ps_stackclear.c					\
	src/lst/ps_stacklast.c					\
	src/lst/ps_stacknew_back.c				\
	src/lst/ps_stacknew.c					\
	src/lst/ps_stacksize.c					\
	src/operations/op_push.c				\
	src/operations/op_reverse_rotate.c		\
	src/operations/op_rotate.c				\
	src/operations/op_swap.c				\
	src/push_swap.c							\
	src/init_arr_sort_stack.c				\
	src/radix_sort.c						\
	src/exec_op.c							\
	src/choose_sort.c						\
	src/hardcoded.c

HEADERS := src/push_swap.h libft/libft.h
OBJDIR := obj
OBJECTS := $(addprefix $(OBJDIR)/, $(SOURCES:c=o))

LIBFLAGS := -L libft -l ft -l glfw3 -framework Cocoa -framework OpenGL -framework IOKit

LIBFT := libft/libft.a

INCLUDES := $(addprefix -I, $(sort $(dir $(HEADERS))))
CFLAGS += $(INCLUDES)

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFLAGS) $(OBJECTS) -o $(NAME)

$(OBJDIR)/%.o : %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	$(MAKE) -C $(dir $(LIBFT))

clean :
	rm -rf $(OBJDIR)
	$(MAKE) -C $(dir $(LIBFT)) clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(dir $(LIBFT)) fclean

re : fclean all

.PHONY : all clean fclean re
