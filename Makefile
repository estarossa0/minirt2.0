NAME = minirt2.0
FLAGS =  -Wall -Wextra -Werror
SRC_FOLDER = ./src
HEADER_FOLDER = ./header
LIBFT_HEADER = ./libft/header
LIBFT_FOLDER = ./libft
OBJECT_FOLDER = ./objects
SDL2_HEADER = SDL2_header
LINUX_FLAGS = -lSDL2 -lSDL2_image -lm -lpthread
MACOS_FLAGS = -L lib -l SDL2-2.0.0 -L lib_image -l SDL2_image-2.0.0
LIBFT_LIB = libft.a
RED = \033[0;31m
GOLD = \033[0;33m
RESET = \033[0m

SRC_FILES =		main.c \
						error.c \
						allocation_functions.c \
						allocation_functions_2.c \
						camera.c \
						color.c \
						here_we_go.c \
						init_light.c \
						init_light_2.c \
						intersect_obj.c \
						parsing_main.c \
						parsing_obj.c \
						parsing_obj_2.c \
						parsing_obj_3.c \
						utils.c \
						cylinder_inters.c \
						vector_op.c \
						vector_op_2.c \
						phong_shitting.c \
						shitting_math.c \
						shadows.c \
						triangle_inters.c \
						save_bmp.c \
						hooks.c \
						squar_inters.c \
						rotation_pars.c \
						rotation.c \
						translation.c \
						put_cap.c \
						cube_parsing.c \
						pyramid_pars.c \
						thread.c \
						anti_aliasing.c \
						camera_mov.c \
						objects_mov.c \
						hardcode_object_rotation.c \
						hardcode_object_translation.c \
						filter.c \
						cone_intersect.c \
						stereoscopy.c \
						texture.c \

OBJECT_FILES = $(SRC_FILES:.c=.o)
OBJECT_FILES := $(addprefix $(OBJECT_FOLDER)/, $(OBJECT_FILES))
LIBFT_FILE := $(LIBFT_FOLDER)/$(LIBFT_LIB)

.PHONY = all clean fclean re credit

ifeq ($(OS),Windows_NT)
	@echo Not windows compatible.
endif
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CFLAGS += $(LINUX_FLAGS)
endif
ifeq ($(UNAME_S),Darwin)
	CFLAGS += $(MACOS_FLAGS)
endif
all: credit $(NAME)

LIB_RULE:
	@make -C $(LIBFT_FOLDER)/

$(NAME): LIB_RULE $(OBJECT_FILES)
	@gcc -g $(OBJECT_FILES) $(LIBFT_FOLDER)/$(LIBFT_LIB) $(CFLAGS) -o $@
	@echo
	@echo $(NAME)" created $(GOLD)successfully$(RESET)"

$(OBJECT_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@(mkdir $(OBJECT_FOLDER) 2> /dev/null && echo "creating "$(OBJECT_FOLDER)" folder $(GOLD){OK}$(RESET)") || true
	@gcc $(FLAGS) -g -I $(HEADER_FOLDER) -I $(LIBFT_HEADER) -I $(SDL2_HEADER) -o $@ -c $< && echo "creating" $< "object $(GOLD){OK}$(RESET)"

clean:
	@(rm $(OBJECT_FILES) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(OBJECT_FILES)) || true
	@(rm -r $(OBJECT_FOLDER) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(OBJECT_FOLDER)) || true
	@make -C $(LIBFT_FOLDER) clean

fclean: clean
	@(rm $(NAME) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(NAME)) || true
	@(rm $(LIBFT_FOLDER)/$(LIBFT_LIB) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(LIBFT_LIB)) || true

re: fclean $(NAME)

credit:
	@printf "					$(RED)_minirt made by:_$(RESET)\n"
	@echo "███████╗ ██████╗████████╗ █████╗ ██████╗  █████╗  ██████╗ ██████╗ █████╗"
	@echo "██╔════╝██╔════╝╚══██╔══╝██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔════╝██╔══██╗"
	@echo "█████╗  ╚█████╗    ██║   ███████║██████╔╝██║  ██║╚█████╗ ╚█████╗ ███████║"
	@echo "██╔══╝   ╚═══██╗   ██║   ██╔══██║██╔══██╗██║  ██║ ╚═══██╗ ╚═══██╗██╔══██║"
	@echo "███████╗██████╔╝   ██║   ██║  ██║██║  ██║╚█████╔╝██████╔╝██████╔╝██║  ██║"
	@echo "╚══════╝╚═════╝    ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝"
