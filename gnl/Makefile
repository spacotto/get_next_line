# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/21 14:56:20 by spacotto          #+#    #+#              #
#    Updated: 2025/11/23 17:36:46 by spacotto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= get_next_line 
CC		:= cc
FLAGS	:= -c -Wall -Wextra -Werror
BS		:= 1 #[1]

# ============================================================================
# COLORS
# ============================================================================

RESET	:= \033[0m
GRAY	:= \033[0;90m
RED		:= \033[0;91m
GREEN	:= \033[0;92m
YELLOW	:= \033[0;93m
BLUE	:= \033[0;94m
MAGENTA	:= \033[0;95m
CYAN	:= \033[0;96m
WHITE	:= \033[0;97m

# ============================================================================
# COMMANDS
# ============================================================================

AR		:= @/bin/ar rcs
ECHO	:= @echo
MKDIR	:= @/bin/mkdir
RM		:= @/bin/rm -rf

# ============================================================================
# INCLUDES
# ============================================================================

INC		:= -I .

# ============================================================================
# SOURCES
# ============================================================================

SRCS	:= get_next_line.c get_next_line_utils.c get_next_line_test.c

# ============================================================================
# OBJECTS
# ============================================================================

OBJS	:= $(SRCS:.c=.o)

# ============================================================================
# RULES
# ============================================================================

all:	 	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)
			$(ECHO) "$(GREEN)Program is ready :)$(RESET)"

%.o:		%.c
			$(ECHO) "$(YELLOW)Now compiling: $< $(RESET)"
			$(CC) $(FLAGS) $(INC) $< -o $@
			$(ECHO) "$(GREEN)$< created $(RESET)"

clean:
			$(RM) $(OBJS) 
			$(ECHO) "$(RED)Objects removed!$(RESET)"

fclean: 	clean
			$(RM) $(NAME)
			$(ECHO) "$(RED)Program removed!$(RESET)"

re: 		fclean all
			$(ECHO) "$(BLUE)Cleaned and rebuilt everything :)$(RESET)"

buffer:		fclean #[2]
			$(MAKE) FLAGS="$(FLAGS) -D BUFFER_SIZE=$(BS)" #[1]

.PHONY: all, clean, fclean, re

# NOTES
# [1]	$(BS) is the variable defining the BUFFER_SIZE. The flag
#		"-D BUFFER_SIZE=n" (where n is the BUFFER_SIZE otherwise
#		defined in the header file) is triggered by the "buffer" 
#		rule. However, the variable must be initialised. Thus,
#		"BS := 1" (note: 1 can be whatever number).
#		To define BUFFER_SIZE through the rule, you have to use
#		the command "make buffer BS=n" where n is the value you
#		want to set.
#
# [2]	The rule "buffer" (used to set up BUFFER_SIZE) fclean.
#		This is because if you change BUFFER_SIZE after already 
#		compiling, Make won't automatically recompile the object 
#		files because it only checks file timestamps, not flag 
#		changes. Thus, you need to fclean and make BUFFER_SIZE=n 
#		to force a full rebuild.
