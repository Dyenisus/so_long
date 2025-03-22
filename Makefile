# Executable name
NAME := so_long

# Compiler and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror -g
INCLUDES := -I ./ -I libft -I minilibx

# Frameworks (Linux için)
MLX := minilibx/libmlx.a
FRAMEWORK := -Lminilibx -lmlx -lX11 -lXext -lm # for linux

# Source and object setup
SRC_DIR := src
OBJ_DIR := obj
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Libraries
LIBFT := libft/libft.a

# Colors
GREEN := \033[0;32m
YELLOW := \033[0;33m
RESET := \033[0m

# Default target
all: $(LIBFT) $(MLX) $(NAME)

# Linking
$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(FRAMEWORK) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

# Compile objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create obj directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Build libft
$(LIBFT):
	@make -C libft

# Build MiniLibX
$(MLX):
	@echo "$(YELLOW)Compiling MiniLibX...$(RESET)"
	@make -C minilibx

# Cleaning rules
clean:
	@rm -f $(OBJS)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
