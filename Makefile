NAME_P = push_swap
NAME_C = checker

_SRCS_PS				=	main.c arguments.c arguments_utils.c push_swap.c mini_push_swap.c \
							sort.c sort_utils.c list_op_and_inst.c list_instruction.c list_instruction_improve.c \
							free.c file_aux.c do_operations.c
_SRCS_CHECKER			=	main.c arguments_checker.c arguments_utils.c checker.c ft_aux.c
_SRCS_STACK				=	init.c push.c swap.c rotate.c reverse.c free_stack.c
_SRCS_UTILS				=	ft_calloc.c ft_bzero.c ft_strlen_int.c \
							ft_strchr.c ft_atoi.c ft_split.c \
							ft_printf.c ft_print_unsigned.c ft_print_ptr.c ft_simple_utils.c \
							ft_strjoin_secure.c ft_strcmp.c get_next_line.c

SRCS_CHECKER_DIR 		= ./checker_bonus
SRCS_PS_DIR				= ./ps
SRCS_STACK_DIR			= ./stack
SRCS_UTILS_DIR			= ./utils

SRCS_PS 				= 	$(addprefix $(SRCS_PS_DIR)/, $(_SRCS_PS))
SRCS_CHECKER 			=	$(addprefix $(SRCS_CHECKER_DIR)/, $(_SRCS_CHECKER))
SRCS_STACK				=	$(addprefix $(SRCS_STACK_DIR)/, $(_SRCS_STACK))
SRCS_UTILS				=	$(addprefix $(SRCS_UTILS_DIR)/, $(_SRCS_UTILS))


SRCO_PS					=	$(SRCS_PS:.c=.o)
SRCO_CHECKER			=	$(SRCS_CHECKER:.c=.o)
SRCO_STACK				=	$(SRCS_STACK:.c=.o)
SRCO_UTILS				=	$(SRCS_UTILS:.c=.o)

FLAG = -Wall -Wextra -Werror
INC = -I includes/

all	:	$(NAME_P) $(NAME_C)

$(NAME_P) : $(SRCO_PS) $(SRCO_STACK) $(SRCO_UTILS)
	cc -o $(NAME_P) $(SRCO_PS) $(SRCO_STACK) $(SRCO_UTILS)

$(NAME_C) : $(SRCO_CHECKER) $(SRCO_STACK) $(SRCO_UTILS)
	cc -o $(NAME_C) $(SRCO_CHECKER) $(SRCO_STACK) $(SRCO_UTILS)

%.o : %.c
	cc $(FLAG) -c $< -o $@ $(INC)

clean :
	/bin/rm -f $(SRCO_PS)
	/bin/rm -f $(SRCO_CHECKER)
	/bin/rm -f $(SRCO_STACK)
	/bin/rm -f $(SRCO_UTILS)

fclean : clean
	/bin/rm -f $(NAME_P)
	/bin/rm -f $(NAME_C)

re :
	make fclean
	make