NAME = cub3D
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
	  init/init_texture/init_east.c \
	  init/init_texture/init_floor.c \
	  init/init_texture/init_north.c \
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
	  hooks/mouse.c \
	  hooks/key.c \
	  error_handler/error_handler.c
SRC_BONUS = main_bonus.c \
	  init/init_bonus.c \
	  init/init_background/init_background_bonus.c \
	  init/init_map/allocate_map_bonus.c \
	  init/init_map/init_map_bonus.c \
	  init/init_map/init_map_size_bonus.c \
	  init/init_map/init_player_position_bonus.c \
	  init/init_map/init_viewing_angle_bonus.c \
	  init/init_map/labeling_map_bonus.c \
	  init/init_map/make_list_map_bonus.c \
	  init/init_minimap/init_minimap_bonus.c \
	  init/init_mlx/init_mlx_bonus.c \
	  init/init_texture/init_ceiling_bonus.c \
	  init/init_texture/init_door_bonus.c \
	  init/init_texture/init_east_bonus.c \
	  init/init_texture/init_floor_bonus.c \
	  init/init_texture/init_north_bonus.c \
	  init/init_texture/init_object_bonus.c \
	  init/init_texture/init_south_bonus.c \
	  init/init_texture/init_texture_bonus.c \
	  init/init_texture/init_west_bonus.c \
	  init/init_utils/count_strings_bonus.c \
	  init/init_utils/create_image_bonus.c \
	  init/init_utils/free_strings_bonus.c \
	  init/init_utils/get_rgb_bonus.c \
	  init/init_utils/is_direction_character_bonus.c \
	  init/init_utils/put_pixel_bonus.c \
	  init/init_view/init_view_bonus.c \
	  init/validate_map/check_door_position_bonus.c \
	  init/validate_map/check_map_has_all_texture_bonus.c \
	  init/validate_map/check_map_is_closed_bonus.c \
	  init/validate_map/check_player_is_duplicated_bonus.c \
	  init/validate_map/check_player_is_exist_bonus.c \
	  init/validate_map/copy_map_bonus.c \
	  init/validate_map/free_copied_map_bonus.c \
	  init/validate_map/validate_map_bonus.c \
	  render/raycast_bonus.c \
	  render/render_minimap_bonus.c \
	  render/render_view_bonus.c \
	  render/render_utils_bonus.c \
	  render/is_near_door_bonus.c \
	  hooks/mouse_bonus.c \
	  hooks/key_bonus.c \
	  error_handler/error_handler_bonus.c
GNL_SRC = get_next_line.c \
		get_next_line_utils.c
SRCS = $(addprefix $(SRC_DIR), $(SRC)) $(addprefix $(GNL_DIR), $(GNL_SRC))
OBJS = $(SRCS:.c=.o)
OBJ = $(addprefix $(SRC_DIR), $(SRC:.c=.o)) $(addprefix $(GNL_DIR), $(GNL_SRC:.c=.o))
OBJ_BONUS = $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS:.c=.o)) $(addprefix $(GNL_DIR), $(GNL_SRC:.c=.o))

ifdef SANITIZE
	CFLAGS += -fsanitize=address -g3
	LDFLAGS += -fsanitize=address -g3
endif

ifdef BONUS
	SRCS = $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS)) $(addprefix $(GNL_DIR), $(GNL_SRC))
	OBJS = $(OBJ_BONUS)
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
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

bonus :
	make BONUS=1 all

re : fclean all

sanitize :
	make SANITIZE=1 re

.PHONY: all clean fclean re bonus sanitize
