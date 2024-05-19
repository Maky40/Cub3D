NAME		=	cub3d

CC			=	cc

FLAG		=	-Wall -Wextra -Werror -g

LIBFT_PATH	=	./libraries/libft/
LIBFT_FILE	=	libft.a
LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

PRINTF_PATH	=	./libraries/ft_printf/
PRINTF_FILE	=	printf.a
PRINTF_LIB	=	$(addprefix $(PRINTF_PATH), $(PRINTF_FILE))

GNL_PATH	=	./libraries/gnl/
GNL_FILE	=	gnl.a
GNL_LIB		=	$(addprefix $(GNL_PATH), $(GNL_FILE))

MLX_PATH	=	./libraries/mlx/
MLX_FILE	=	libmlx.a
MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

SRC_DIR		=	./src/
OBJ_DIR		=	./obj/

SRC			=	$(wildcard $(SRC_DIR)*.c)
OBJ			=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

lib:
	@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)\n"
	@make -C $(LIBFT_PATH)
	@echo "\033[1;32mLIBFT_lib created\n"

gnl:
	@echo "\033[0;33m\nCOMPILING $(GNL_PATH)\n"
	@make -C $(GNL_PATH)
	@echo "\033[1;32mGNL_lib created\n"

printf:
	@echo "\033[0;33m\nCOMPILING $(PRINTF_PATH)\n"
	@make -C $(PRINTF_PATH)
	@echo "\033[1;32mPRINTF_lib created\n"

mlx:
	@echo "\033[0;33m\nCOMPILING $(MLX_PATH)\n"
	@make -C $(MLX_PATH)
	@echo "\033[1;32mMLX_lib created\n"

$(NAME): lib gnl printf mlx $(OBJ)
	@echo "\033[0;33m\nCOMPILING cub3d...\n"
	$(CC) $(OBJ) $(LIBFT_LIB) $(GNL_LIB) $(PRINTF_LIB) ${MLX_LIB} -lXext -lX11 -lm -o $(NAME)
	@echo "\033[1;32m./cub3d created\n"

clean:
	@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[0;31mDeleting Obj file in $(GNL_PATH)...\n"
	@make clean -sC $(GNL_PATH)
	@echo "\033[0;31mDeleting Obj file in $(PRINTF_PATH)...\n"
	@make clean -sC $(PRINTF_PATH)
	@echo "\033[0;31mDeleting Obj file in $(MLX_PATH)...\n"
	@make clean -sC $(MLX_PATH)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting cub3d object...\n"
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting cub3d executable..."
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(GNL_PATH)
	@make fclean -C $(PRINTF_PATH)
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: all clean fclean re
