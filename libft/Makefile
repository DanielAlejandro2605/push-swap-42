NAME				= 	libft.a

SOURCE_DIR			=	./src/

_SOURCES_LIBFT		=	ft_isalnum.c \
						ft_isprint.c \
						ft_memcmp.c \
						ft_putchar_fd.c \
						ft_split.c \
						ft_strlcat.c \
						ft_strncmp.c \
						ft_atoi.c \
						ft_isalpha.c \
						ft_substr.c \
						ft_itoa.c \
						ft_memcpy.c \
						ft_putendl_fd.c \
						ft_strchr.c \
						ft_strlcpy.c \
						ft_strnstr.c \
						ft_tolower.c \
						ft_bzero.c \
						ft_isascii.c \
						ft_memcpy.c \
						ft_memmove.c \
						ft_putnbr_fd.c \
						ft_strdup.c \
						ft_strlen.c \
						ft_strrchr.c \
						ft_toupper.c \
						ft_calloc.c \
						ft_isdigit.c \
						ft_memchr.c \
						ft_memset.c  \
						ft_putstr_fd.c \
						ft_strjoin.c \
						ft_strmapi.c \
						ft_strtrim.c \
						ft_striteri.c \
						ft_lstdelone.c \
						ft_lstnew.c \
						ft_lstadd_front.c \
						ft_lstsize.c \
						ft_lstlast.c \
						ft_lstadd_back.c \
						ft_lstclear.c \
						ft_lstiter.c \
						ft_lstmap.c

_SOURCES_MY_FUNCTIONS	=	ft_printf.c \
							ft_print_ptr.c \
							ft_print_unsigned.c \
							ft_simple_utils.c \
							get_next_line.c \
							get_next_line_utils.c \
							ft_strlen_int.c

_SRCS					=	$(_SOURCES_LIBFT) $(_SOURCES_MY_FUNCTIONS)

SRCS					=	$(addprefix $(SOURCE_DIR), $(_SRCS))

SRCS_OBJS				=	$(SRCS:.c=.o)

CC						= 	gcc

RM						= 	rm -f

CFLAGS					= 	-Wall -Wextra -Werror -I.

INC						=	-I includes/

all:			$(NAME)

$(NAME):		$(SRCS_OBJS)
				ar rcs $(NAME) $(SRCS_OBJS)

%.o : %.c
	$(CC) $(FLAG) -c $< -o $@ $(INC)

clean:
				$(RM) $(SRCS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re