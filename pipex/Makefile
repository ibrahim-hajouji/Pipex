NAME = pipex

NAMEB = pipex_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ./mandatory/pipex.c \
	  ./mandatory/ft_split.c \
	  ./mandatory/pipex_utils.c \
	  ./mandatory/ft_exit.c \
	  ./mandatory/utils.c

SRCB = ./bonus/pipex_bonus.c \
	   ./bonus/ft_split_bonus.c \
	   ./bonus/pipex_utils_bonus.c \
	   ./bonus/pipex_utils2_bonus.c \
	   ./bonus/ft_exit_bonus.c \
	   ./bonus/utils_bonus.c \
	   ./bonus/gnl_bonus.c \
	   ./bonus/gnl_utils_bonus.c \

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ./mandatory/pipex.h
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAMEB): $(OBJB) ./bonus/pipex_bonus.h ./bonus/gnl_bonus.h 
	$(CC) $(CFLAGS) $(OBJB) -o $(NAMEB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAMEB)

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME) $(NAMEB)

re: fclean all

.PHONY: all clean fclean re bonus 