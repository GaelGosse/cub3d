##### COLOR #####
BLACK = \033[1;30m
REDBG = \033[30;41m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
END = \033[0m

##### Names #####
NAME		= cub3d
LIBNAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
MLXFLAGS	= -L libs/minilibx-linux/ -lmlx -lXext -lX11 -lz -lm

SRCSDIR		= srcs
OBJSDIR		= objs
INCSDIR		= incs
LIBDIR		= libft

_SRCS	=	main.c \

SRCS	= $(addprefix $(SRCSDIR)/, $(_SRCS))
OBJS	= $(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)
HEADER = $(addprefix $(INCSDIR)/, $(NAME).h)

##### Makefile work ####

$(OBJSDIR)/%.o:$(SRCSDIR)/%.c $(HEADER)
	@mkdir -p $(OBJSDIR)
	@$(CC) -c $(CFLAGS) -I$(INCSDIR) -I$(LIBDIR) $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@echo "Baking $(LIBDIR)..."
	@make -s -C $(LIBDIR)
	@echo "$(GREEN)OK!$(END)"
	@echo "Baking $(NAME)..."
	@$(CC) -I$(INCSDIR) -I$(LIBDIR) -o $@ $^ $(CFLAGS)
	@echo "$(GREEN)OK!$(END)"
	@echo "$(BLUE)READY !$(END)"

clean:
	@echo "Removing objects..."
	@make clean -s -C $(LIBDIR)
	@rm -r $(OBJSDIR) || true
	@echo "$(GREEN)Done!$(END)"

fclean: clean
	@echo "Cleaning everything..."
	@make fclean -s -C $(LIBDIR)
	@rm -f $(NAME)
	@echo "$(GREEN)Done!$(END)"
	@echo "$(BLUE)Everything is clean!$(END)"

re:	fclean all

.PHONY: all clean fclean re