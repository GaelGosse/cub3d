NAME = libft.a

CC = gcc -Wall -Wextra -Werror -g3 -MMD -MP

_SRCS = ft_atoi.c \
    ft_bzero.c \
    ft_calloc.c \
    ft_gnl.c \
    ft_isalnum.c \
    ft_isalpha.c \
    ft_isascii.c \
    ft_isdigit.c \
    ft_isprint.c \
    ft_itoa.c \
    ft_memchr.c \
    ft_memcmp.c \
    ft_memcpy.c \
    ft_memmove.c \
    ft_memset.c \
    ft_putchar_fd.c \
    ft_putendl_fd.c \
    ft_putnbr_fd.c \
    ft_putstr_fd.c \
    ft_split.c \
    ft_strchr.c \
    ft_strdup.c \
    ft_striteri.c \
    ft_strjoin.c \
    ft_strlcat.c \
    ft_strlcpy.c \
    ft_strlen.c \
    ft_strmapi.c \
    ft_strncmp.c \
    ft_strnstr.c \
    ft_strrchr.c \
    ft_strtrim.c \
    ft_substr.c \
    ft_tolower.c \
    ft_toupper.c \
    ft_lstnew_bonus.c \
    ft_lstadd_front_bonus.c \
    ft_lstsize_bonus.c \
    ft_lstlast_bonus.c \
    ft_lstadd_back_bonus.c\
    ft_lstdelone_bonus.c \
    ft_lstclear_bonus.c \
    ft_lstiter_bonus.c \
    ft_lstmap_bonus.c \
    ft_printf.c \
    ft_tools.c \
    ft_putnbr_base_low.c \
    ft_putnbr_base_up.c \
    ft_putunbr.c

OBJ = *.o

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $^

$(OBJ) : $(_SRCS)
	$(CC) -c $(_SRCS)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
-include ${DEPS}
