NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = $(LIBFT) -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

LIB_DIR = lib/
LIBFT_DIR = $(LIB_DIR)libft/
GNL_DIR = $(LIB_DIR)get_next_line/
MLX_DIR = $(LIB_DIR)minilibx_opengl/

LIBFT_NAME = libft.a
MLX_NAME = libmlx.a

LIBFT = $(LIBFT_DIR)$(LIBFT_NAME)
MLX = $(MLX_DIR)$(MLX_NAME)

SRC_DIR = src/
SRC = main.c
GNL_SRC = get_next_line.c \
		get_next_line_utils.c
SRCS = $(addprefix $(SRC_DIR), $(SRC)) $(addprefix $(GNL_DIR), $(GNL_SRC))
OBJS = $(SRCS:.c=.o)

ifdef SANITIZE
	CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
endif

ifdef BONUS
	make BONUS=1 all
endif

all : $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

$(MLX):
	@$(MAKE) -C $(MLX_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIB_DIR) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(LDFLAGS) $(OBJS) -o $(NAME)

clean :
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

bonus :
	make BONUS=1 all

re : fclean all

.PHONY: all clean fclean re bonus
