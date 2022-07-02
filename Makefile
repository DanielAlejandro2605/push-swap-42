NAME_C = checker
NAME_P = push_swap


# _SRCS_CHECKER = main.c \
# 		ft_list.c \
# 		ft_op_pile.c \
# 		ft_build_pile_str.c \
# 		ft_aux.c \
# 		ft_move.c

_SRCS_PS				=	main.c arguments.c arguments_utils.c push_swap.c mini_push_swap.c \
							sort.c sort_utils.c list_op_and_inst.c list_instruction.c list_instruction_utils.c \
							free.c file_aux.c do_operations.c
_SRCS_STACK				=	push.c swap.c rotate.c reverse.c free_stack.c develop_functions.c
# SRCS_CHECKER_DIR 		= ./checker
SRCS_PS_DIR				= ./ps
SRCS_STACK_DIR			= ./stack
LIBFT_DIR				= ./libft

# SRCS_CHECKER 			= $(addprefix $(SRCS_C_DIR)/, $(_SRCS_C))
SRCS_PS 				= 	$(addprefix $(SRCS_PS_DIR)/, $(_SRCS_PS))
SRCS_STACK				=	$(addprefix $(SRCS_STACK_DIR)/, $(_SRCS_STACK))
LIBFT_A					=	libft.a
# SRCO_C = $(SRCS_C:.c=.o)

SRCO_PS = $(SRCS_PS:.c=.o)
SRCO_STACK	= $(SRCS_STACK:.c=.o)
FLAG = -Wall -Wextra -Werror
INC = -I includes/

all	:	$(NAME_P)

$(NAME_P) : do_libft $(SRCO_PS) $(SRCO_STACK) $(LIBFT_A)
	gcc -o $(NAME_P) $(LIBFT_A) $(SRCO_PS) $(SRCO_STACK)

%.o : %.c
	gcc $(FLAG) -c $< -o $@ $(INC)

do_libft:
		@make -C $(LIBFT_DIR)
		@cp $(LIBFT_DIR)/$(LIBFT_A) .

clean :
	/bin/rm -f $(SRCO_PS)
	/bin/rm -f $(SRCO_STACK)
	make clean -C libft

fclean : clean
	/bin/rm -f $(NAME_P)
	/bin/rm -f $(LIBFT_A)
	/bin/rm -f libft/libft.a

re :
	make fclean
	make