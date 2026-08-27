# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: criredon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/08 18:38:38 by criredon          #+#    #+#              #
#    Updated: 2026/07/08 18:38:41 by criredon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:=	libftprintf.a
OBJ_DIR		:=	objects
LIBFT_DIR	:=	../libft
LIBFT_NAME	:=	libft.a
LIBFT		:=	$(LIBFT_DIR)/$(LIBFT_NAME)

SOURCES 	:= 	ft_printf.c \
				ft_printf_nbr.c

OBJECTS 	:=  $(SOURCES:%.c=$(OBJ_DIR)/%.o)

CC 			:= 	cc
CFLAGS 		:= 	-Wall -Wextra -Werror
AR 			:= 	ar
ARFLAGS		:= 	rcs
RM 			:= 	rm -rf

all: 		$(NAME)

$(LIBFT):
			@make -C $(LIBFT_DIR)

$(NAME):	$(LIBFT) $(OBJECTS)
			cp $(LIBFT) $(NAME)
			$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

$(OBJ_DIR):
			@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@

clean:
			$(RM) $(OBJ_DIR)
			@make -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			@make -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re

# **************************************************************************** #
# 1. PROJECT CONFIGURATION
# NAME      Name of the target static library.
# SRC_DIR   Directory containing source (.c) files.
# OBJ_DIR   Directory for generated object (.o) files.
# INC_DIR   Directory for header (.h) files.
#
# 2. FILE MANAGEMENT
# SOURCES   List of all source files to be compiled.
# OBJECTS   Dynamic mapping: converts .c source paths to .o objects in OBJ_DIR.
#
# 3. COMPILATION SETTINGS
# CC        Compiler used (cc is the standard in 42).
# CFLAGS    Flags for strict compilation.
# AR        Archiver tool for creating static libraries.
# ARFLAGS   Flags for r (insert/replace), c (create archive), s (create index).
# RM        Command to remove files/directories recursively and forcefully.
#
# 4. DETAILED RULES EXPLANATION
# 4.1. all:       	It triggers the creation of the library '$(NAME)'.
# 4.2. $(NAME):   	This rule links all object files into the final archive.
# 4.3. $(OBJ_DIR): 	This rule creates the object directory.
# 4.4. %.o:       	Defines how to create any '.o' file from a '.c' file. 
# 4.5. clean:     	Removes the entire object directory.
# 4.6. fclean:    	Calls 'clean' first, then removes the final static library.
# 4.7. re:        	Guarantees a clean recompilation from scratch.
# 4.8. .PHONY:    	Declares rules as internal commands.
# **************************************************************************** #
