NAME = lib
CC = cc 
CFLAGS =  -Wall -Wextra -Werror 
SRC = cub.c parsing.c texters.c more_files.c libft/ft_bzero.c \
        libft/ft_strjoin.c libft/ft_atoi.c libft/ft_strlen.c libft/ft_calloc.c \
        libft/ft_split.c libft/ft_strdup.c   libft/ft_strnstr.c libft/ft_strchr.c \
         file.c get_line/get_next_line.c
OBJ = $(SRC:.c=.o)
all:$(NAME)

$(NAME):$(OBJ)
	ar r $(NAME) $(OBJ)
	$(CC) $(CFLCAGS)  -fsanitize=address -g3 -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(NAME) -o CUB3D
clean:
	rm -f $(OBJ)
fclean:
	rm -f $(OBJ)
	rm -f $(NAME)
	rm -f philo
re: fclean all