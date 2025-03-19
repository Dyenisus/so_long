# Executable name
NAME := so_long

# Compiler and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror
FRAMEWORK := -framework OpenGL -framework AppKit

# Directories
SRC_DIR := src
OBJ_DIR := obj
LIBFT := libft/libft.a
MLX := minilibx/libmlx.a
INCLUDES := -I ./ -I libft -I minilibx

# Source files
SRCS := $(shell find $(SRC_DIR) -name "*.c")
OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

# Colors for output
GREEN := \033[0;32m
YELLOW := \033[0;33m
RESET := \033[0m

# Default rule: Compile so_long
all: $(LIBFT) $(MLX) $(NAME)

# Linking so_long with libft and MiniLibX
$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(MLX) $(OBJS) $(FRAMEWORK) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

# Compiling .c files to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create obj directory if not exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile libft (which includes get_next_line + ft_printf)
$(LIBFT):
	@make -C libft

# Compile MiniLibX
$(MLX):
	@echo "$(YELLOW)Compiling MiniLibX...$(RESET)"
	@make -C minilibx

# Clean object files
clean:
	@rm -f $(OBJS)
	@make -C libft clean

# Full clean (removes everything)
fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

# Recompile everything
re: fclean all
