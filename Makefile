NAME 		:=	push_swap
OBJ_DIR		:=	objects

LIBFT_DIR	:=	libft
LIBFT		:=	$(LIBFT_DIR)/libft.a

PRINTF_DIR	:=	ft_printf
PRINTF		:=	$(PRINTF_DIR)/libftprintf.a

SOURCES 	:= 	0_main.c \
				1_detect_flags.c \
				2_parse_numbers.c \
				3_prepare_stack.c \
				4_calculate_disorder.c \
				5_1_execute_strategy.c \
				5_2_sort_simple.c \
				5_3_sort_medium.c \
				5_4_sort_complex.c \
				5_5_sort_adaptive.c \
				6_1_operations_push.c \
				6_2_operations_swap.c \
				6_3_operations_rotate.c \
				6_4_operations_revrotate.c

OBJECTS 	:=  $(SOURCES:%.c=$(OBJ_DIR)/%.o)

CC 			:= 	cc
CFLAGS 		:= 	-Wall -Wextra -Werror
RM 			:= 	rm -rf

all: 		$(NAME)

$(LIBFT):
			@make -C $(LIBFT_DIR)

$(PRINTF):
			@make -C $(PRINTF_DIR)

$(NAME):	$(LIBFT) $(PRINTF) $(OBJECTS)
			$(CC) $(CFLAGS) $(OBJECTS) $(PRINTF) $(LIBFT) -o $(NAME)

$(OBJ_DIR):
			@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -c $< -o $@

clean:
			$(RM) $(OBJ_DIR)
			@make -C $(LIBFT_DIR) clean
			@make -C $(PRINTF_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			@make -C $(LIBFT_DIR) fclean
			@make -C $(PRINTF_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
