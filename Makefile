# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpollini <lpollini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 20:15:20 by lpollini          #+#    #+#              #
#    Updated: 2023/07/11 15:45:31 by lpollini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


###################################################
#         		   NAME here                      #
###################################################
NAME		= push_swap.a
PROGNAME	= push_swap
BONUSNAME	= checker.a
BONUSPROGNAME	= checker
SRCSDIR		= .
OBJSDIR		= objs
BOBJSDIR	= objs/bonus
BONUSDIR	= .
ALLDIR		= .
AOBJSDIR	= objs
INCLUDES	= .

###################################################
#         		   Sources here	                  #
###################################################

SRCS		= second_utils.c \
second_b_solve_four.c \
second_part.c \
second_a_solve_four.c \
first_part.c \
operations_2_utils.c \
initialize.c \
smem.c \
operations_1.c \
operations.c \
get_next_line.c \
other_utils.c

OBJS		= $(SRCS:.c=.o)
BOBJS		= $(BONUS:.c=.o)

###################################################
#            		 Bonus here	                  #
###################################################

BONUS		=	


# Compiler options
CC			= gcc
CFLAGS		= -Wall -Wextra -g3

###################################################
# The rest is done by the MakeFile automatically, #
# you should not have to modify it				  #
###################################################

OBJS		= $(SRCS:%.c=$(OBJSDIR)/%.o)
BOBJS		= $(BONUS:%.c=$(BOBJSDIR)/%.o)
AOBJS		= $(ALLSTUFF:%.c=$(AOBJSDIR)/%.o)


all: $(NAME)

bonus: $(BONUSNAME)

$(BONUSNAME): $(OBJS)
	@echo "Linking $@"
	@ar rc $(NAME) $(OBJS)
	@echo "Done!"
	@echo "Now building checker..."
	@$(CC) $(CFLAGS) checker.c $(NAME) -o "$(BONUSPROGNAME)"
	@echo "Done!"

$(NAME): $(OBJS)
	@echo "Linking $@"
	@ar rc $(NAME) $(OBJS)
	@echo "Done!"
	@echo "Now building program..."
	@$(CC) $(CFLAGS) main.c $(NAME) -o "$(PROGNAME)"
	@echo "Done!"

$(OBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@




coffee: bonus $(AOBJS)
	@echo "Linking $@"
	@ar rcs $(NAME) $(AOBJS)
	@echo "Done!"

$(AOBJS): $(AOBJSDIR)/%.o: $(ALLDIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(PROGNAME)
	rm -rf $(BONUSNAME)
	rm -rf $(BONUSPROGNAME)
	
aclean:
	rm -rf $(NAME)

re: fclean all



test: all
	./$(NAME)

.PHONY: all clean fclean re test
