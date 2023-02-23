NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = $(LIBFT) -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

LIB_DIR = lib/
LIBFT_DIR = $(LIB_DIR)libft/
GNL_DIR = $(LIB_DIR)get_next_line/
MLX_DIR = $(LIB_DIR)minilibx_opengl/
SRC_DIR = src/
SRC_BONUS_DIR = src_bonus/

LIBFT_NAME = libft.a
MLX_NAME = libmlx.a

LIBFT = $(LIBFT_DIR)$(LIBFT_NAME)
MLX = $(MLX_DIR)$(MLX_NAME)

SRC = main.c \
	  init/init.c \
	  init/init_background/init_background.c \
	  init/init_map/allocate_map.c	\
	  init/init_map/init_map.c \
	  init/init_map/init_map_size.c \
	  init/init_map/init_player_position.c \
	  init/init_map/init_viewing_angle.c \
	  init/init_map/labeling_map.c \
	  init/init_map/make_list_map.c \
	  init/init_minimap/init_minimap.c \
	  init/init_mlx/init_mlx.c \
	  init/init_texture/init_ceiling.c \
	  init/init_texture/init_door.c \
	  init/init_texture/init_east.c \
	  init/init_texture/init_floor.c \
	  init/init_texture/init_north.c \
	  init/init_texture/init_object.c \
	  init/init_texture/init_south.c \
	  init/init_texture/init_texture.c \
	  init/init_texture/init_west.c \
	  init/init_utils/count_strings.c \
	  init/init_utils/create_image.c \
	  init/init_utils/free_strings.c \
	  init/init_utils/get_rgb.c \
	  init/init_utils/is_direction_character.c \
	  init/init_utils/put_pixel.c \
	  init/init_view/init_view.c \
	  init/validate_map/check_door_position.c \
	  init/validate_map/check_map_has_all_texture.c \
	  init/validate_map/check_map_is_closed.c \
	  init/validate_map/check_player_is_duplicated.c \
	  init/validate_map/check_player_is_exist.c \
	  init/validate_map/copy_map.c \
	  init/validate_map/free_copied_map.c \
	  init/validate_map/validate_map.c \
	  render/raycast.c \
	  render/render_minimap.c \
	  render/render_view.c \
	  render/render_utils.c \
	  render/is_near_door.c \
	  hooks/mouse.c \
	  hooks/key.c \
	  error_handler/error_handler.c
SRC_BONUS = 
GNL_SRC = get_next_line.c \
		get_next_line_utils.c
SRCS = $(addprefix $(SRC_DIR), $(SRC)) $(addprefix $(GNL_DIR), $(GNL_SRC))
OBJS = $(SRCS:.c=.o)

ifdef SANITIZE
	CFLAGS += -fsanitize=address -g3
	LDFLAGS += -fsanitize=address -g3
endif

ifdef BONUS
	SRCS = $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS)) $(addprefix $(GNL_DIR), $(GNL_SRC))
endif

all : $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) bonus -j6

$(MLX):
	@$(MAKE) -C $(MLX_DIR) all -j6

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

sanitize :
	make SANITIZE=1 re

.PHONY: all clean fclean re bonus sanitize
