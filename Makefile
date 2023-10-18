CC = cc
CFLAGS =  #-fsanitize=address -g3
RM = rm -f
FILES = lunchmap.c cub3d.c parsing/parsing.c parsing/texters.c parsing/more_files.c parsing/libft/ft_bzero.c \
		parsing/libft/ft_strjoin.c parsing/libft/ft_atoi.c parsing/libft/ft_strlen.c parsing/libft/ft_calloc.c \
		parsing/libft/ft_split.c parsing/libft/ft_strdup.c   parsing/libft/ft_strnstr.c parsing/libft/ft_strchr.c \
		parsing/file.c parsing/get_line/get_next_line.c
OBJ = $(FILES:.c=.o)
NAME = cub3d

all: $(NAME)

UNAME = $(shell uname)
ifeq ($(UNAME),Linux)
    MLX_FLAGS = -lmlx -lXext -lX11 -lm
endif
ifeq ($(UNAME),Darwin)
    MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
endif


$(NAME): $(FILES)
	$(CC) $(CFLAGS) $(FILES) $(MLX_FLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
