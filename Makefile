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
	render/raycast.c \
	render/render_minimap.c \
	render/render_view.c \
	render/render_utils.c \
	hooks/mouse.c \
	hooks/key.c \
	error_handler/error_handler.c \
	parse/parse.c \
	parse/parse_texture/parse_texture.c \
	parse/parse_texture/parse_texture_functions/parse_north.c \
	parse/parse_texture/parse_texture_functions/parse_south.c \
	parse/parse_texture/parse_texture_functions/parse_east.c \
	parse/parse_texture/parse_texture_functions/parse_west.c \
	parse/parse_texture/parse_texture_functions/parse_floor.c \
	parse/parse_texture/parse_texture_functions/parse_ceiling.c \
	parse/parse_texture/parse_texture_utils/get_rgb.c \
	parse/parse_map/parse_map.c \
	parse/parse_map/parse_map_utils/allocate_map.c \
	parse/parse_map/parse_map_utils/labeling_map.c \
	parse/parse_map/parse_map_utils/make_list_map.c \
	parse/parse_map/parse_map_utils/measure_map_size.c \
	parse/parse_map/parse_map_utils/set_player_position.c \
	parse/validate_map/validate_map.c \
	parse/validate_map/validate_map_utils/check_map_is_closed.c \
	parse/validate_map/validate_map_utils/check_player_is_duplicated.c \
	parse/validate_map/validate_map_utils/check_player_is_exist.c \
	parse/validate_map/validate_map_utils/copy_map.c \
	parse/validate_map/validate_map_utils/free_copied_map.c \
	init_params/init_params.c \
	init_params/init_params_utils/create_image.c \
	init_params/init_params_utils/init_background.c \
	init_params/init_params_utils/init_minimap.c \
	init_params/init_params_utils/init_mlx_params.c \
	init_params/init_params_utils/init_view.c \
	init_params/init_params_utils/init_viewing_angle.c \
	init_params/init_params_utils/init_wall_image.c \
	utils/count_strings.c \
	utils/free_strings.c \
	utils/ft_strcmp.c \
	utils/ft_isspace.c
SRC_BONUS = main_bonus.c \
			render/raycast_bonus.c \
			render/render_minimap_bonus.c \
			render/render_view_bonus.c \
			render/render_utils_bonus.c \
			render/is_near_door_bonus.c \
			hooks/mouse_bonus.c \
			hooks/key_bonus.c \
			error_handler/error_handler_bonus.c \
			parse/parse_bonus.c \
			parse/parse_texture/parse_texture_bonus.c \
			parse/parse_texture/parse_texture_functions/parse_north_bonus.c \
			parse/parse_texture/parse_texture_functions/parse_south_bonus.c \
			parse/parse_texture/parse_texture_functions/parse_east_bonus.c \
			parse/parse_texture/parse_texture_functions/parse_west_bonus.c \
			parse/parse_texture/parse_texture_functions/parse_floor_bonus.c \
			parse/parse_texture/parse_texture_functions/parse_ceiling_bonus.c \
			parse/parse_texture/parse_texture_functions/parse_door_bonus.c \
			parse/parse_texture/parse_texture_functions/parse_object_bonus.c \
			parse/parse_texture/parse_texture_utils/get_rgb_bonus.c \
			parse/parse_map/parse_map_bonus.c \
			parse/parse_map/parse_map_utils/allocate_map_bonus.c \
			parse/parse_map/parse_map_utils/labeling_map_bonus.c \
			parse/parse_map/parse_map_utils/make_list_map_bonus.c \
			parse/parse_map/parse_map_utils/measure_map_size_bonus.c \
			parse/parse_map/parse_map_utils/set_player_position_bonus.c \
			parse/validate_map/validate_map_bonus.c \
			parse/validate_map/validate_map_utils/check_door_position_bonus.c \
			parse/validate_map/validate_map_utils/check_map_is_closed_bonus.c \
			parse/validate_map/validate_map_utils/check_player_is_duplicated_bonus.c \
			parse/validate_map/validate_map_utils/check_player_is_exist_bonus.c \
			parse/validate_map/validate_map_utils/copy_map_bonus.c \
			parse/validate_map/validate_map_utils/free_copied_map_bonus.c \
			init_params/init_params_bonus.c \
			init_params/init_params_utils/create_image_bonus.c \
			init_params/init_params_utils/init_background_bonus.c \
			init_params/init_params_utils/init_minimap_bonus.c \
			init_params/init_params_utils/init_mlx_params_bonus.c \
			init_params/init_params_utils/init_view_bonus.c \
			init_params/init_params_utils/init_viewing_angle_bonus.c \
			init_params/init_params_utils/init_wall_image_bonus.c \
			init_params/init_params_utils/init_door_image_bonus.c \
			init_params/init_params_utils/init_object_image_bonus.c \
			utils/count_strings_bonus.c \
			utils/free_strings_bonus.c \
			utils/ft_strcmp_bonus.c \
			utils/ft_isspace_bonus.c
GNL_SRC = get_next_line.c \
		get_next_line_utils.c
SRCS = $(addprefix $(SRC_DIR), $(SRC)) $(addprefix $(GNL_DIR), $(GNL_SRC))
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS:.c=.o)) $(addprefix $(GNL_DIR), $(GNL_SRC:.c=.o))

ifdef SANITIZE
	CFLAGS += -fsanitize=address -g3
	LDFLAGS += -fsanitize=address -g3
endif

ifdef BONUS
	SRCS = $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS)) $(addprefix $(GNL_DIR), $(GNL_SRC))
	OBJS = $(SRCS:.c=.o)
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
