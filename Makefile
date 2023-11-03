NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/ft_print_char.c src/ft_print_integer.c src/ft_print_lower_hex.c src/ft_print_pointer.c\
		 src/ft_print_str.c src/ft_print_unsigned_int.c src/ft_print_upper_hex.c src/ft_printf.c src/ft_printf_utils.c\

OBJS = $(SRCS:.c=.o)
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)
$(NAME): $(OBJS)
	@cp $(LIBFT) $(NAME) 
	@ar rcs $(NAME) $(OBJS)
	@echo "Successfully compiled $(NAME)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
