NAME_P = push_swap
NAME_C = checker

_SRCS_PS				=	main.c arguments.c arguments_utils.c push_swap.c mini_push_swap.c \
							sort.c sort_utils.c list_op_and_inst.c list_instruction.c list_instruction_utils.c \
							free.c file_aux.c do_operations.c
_SRCS_CHECKER			=	main.c arguments_checker.c arguments_utils.c checker.c 
_SRCS_STACK				=	push.c swap.c rotate.c reverse.c free_stack.c develop_functions.c
_SRCS_USED_LIBFT		=	ft_strlen_int.c ft_atoi.c ft_printf.c ft_print_unsigned.c ft_print_ptr.c \
							ft_simple_utils.c

SRCS_CHECKER_DIR 		= ./checker
SRCS_PS_DIR				= ./ps
SRCS_STACK_DIR			= ./stack
SRC_LIBFT_DIR			= ./libft/src

SRCS_PS 				= 	$(addprefix $(SRCS_PS_DIR)/, $(_SRCS_PS))
SRCS_CHECKER 			=	$(addprefix $(SRCS_CHECKER_DIR)/, $(_SRCS_CHECKER))
SRCS_STACK				=	$(addprefix $(SRCS_STACK_DIR)/, $(_SRCS_STACK))
SRCS_USED_LIBFT			=	$(addprefix $(SRC_LIBFT_DIR)/, $(_SRCS_USED_LIBFT))
LIBFT_A					=	libft.a


SRCO_PS					=	$(SRCS_PS:.c=.o)
SRCO_CHECKER			=	$(SRCS_CHECKER:.c=.o)
SRCO_STACK				=	$(SRCS_STACK:.c=.o)
SRCO_USED_LIBFT			=	$(SRCS_USED_LIBFT:.c=.o)	
FLAG = -Wall -Wextra -Werror
INC = -I includes/

all	:	$(NAME_P) $(NAME_C)

$(NAME_P) : $(SRCO_PS) $(SRCO_STACK)
	make -C ./libft
	cp ./libft/libft.a .
	gcc -o $(NAME_P) -Llibft -lft $(LIBFT_A) $(SRCO_PS) $(SRCO_STACK) $(SRCO_USED_LIBFT)

$(NAME_C) : $(SRCO_CHECKER) $(SRCO_STACK)
	make -C ./libft
	cp ./libft/libft.a .
	gcc -o $(NAME_C) -Llibft -lft $(LIBFT_A) $(SRCO_CHECKER) $(SRCO_STACK) $(SRCO_USED_LIBFT)

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