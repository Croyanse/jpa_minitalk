NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -c

SRC = ft_atoi.c	\
	  ft_putstr.c \
	  ft_calloc.c \
	  ft_putstr_fd.c \
	  ft_isalnum.c \
	  ft_split.c \
	  ft_isalpha.c \
	  ft_strchr.c \
	  ft_isascii.c \
	  ft_strdup.c \
	  ft_isdigit.c \
	  ft_striteri.c \
	  ft_isprint.c \
	  ft_strjoin.c \
	  ft_itoa.c \
	  ft_strlcat.c \
	  ft_lstadd_back.c \
	  ft_strlcpy.c \
	  ft_lstadd_front.c \
	  ft_strlen.c \
	  ft_lstclear.c \
	  ft_strmapi.c \
	  ft_lstdelone.c \
	  ft_strncmp.c \
	  ft_lstiter.c \
	  ft_strnstr.c \
	  ft_lstlast.c \
	  ft_strrchr.c \
	  ft_lstmap.c \
	  ft_strtrim.c \
	  ft_lstnew.c \
	  ft_substr.c \
	  ft_lstsize.c \
	  ft_tolower.c \
	  ft_memchr.c \
	  ft_toupper.c \
	  ft_memcmp.c \
	  ft_wchar.c \
	  ft_memcpy.c \
	  ft_whex.c \
	  ft_memmove.c \
	  ft_wint.c \
	  ft_memset.c \
	  ft_wptr.c \
	  ft_printf.c \
	  ft_wstr.c \
	  ft_putchar_fd.c \
	  ft_wuint.c \
	  ft_putendl_fd.c \
	  get_next_line_bonus.c \
	  ft_putnbr_fd.c \
	  get_next_line_utils_bonus.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)



$(NAME): $(OBJ)
	gcc -Wall -Werror -Wextra -c $(SRC)	
	ar rc $(NAME) $(OBJ)

.o :.c 
	gcc -c $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) *.o

re: fclean all

.PHONY: clean fclean all re
