
##### Colors #####
BLACK=\033[0;30m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
END=\033[0m

##### bold colors #####
BOLD_BLACK=\033[1;30m
BOLD_RED=\033[1;31m
BOLD_GREEN=\033[1;32m
BOLD_YELLOW=\033[1;33m
BOLD_BLUE=\033[1;34m
BOLD_PURPLE=\033[1;35m
BOLD_CYAN=\033[1;36m
BOLD_WHITE=\033[1;37m

##### Names #####
NAME	= cub3D
LIBNAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -lreadline -g3 -MMD -MP
SRCDIR	= srcs
OBJDIR	= objs
INCDIR	= incs
LIBDIR	= libft

# ----------------------------------- srcs ----------------------------------- #
_SRCS	=	check_file.c \
			floor_ceil_part.c \
			free_parsing.c \
			main.c \
			read_file.c \
			texture_part.c \
			valid_wall.c
# --------------------------------- end srcs --------------------------------- #

SRC            = $(addprefix $(SRCDIR)/, $(_SRCS))
OBJ            = $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
HEADER         = $(addprefix $(INCDIR)/, $(NAME).h)

##### Makefile work ####
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	@mkdir -p $(@D)
	@$(CC) -c $(CFLAGS) -I$(LIBDIR) -I$(INCDIR) $< -o $@
all: $(NAME)
$(NAME): $(OBJ) $(HEADER)
	@echo "Baking $(LIBDIR)..."
	@make -s -C $(LIBDIR)
	@echo "$(GREEN)OK!$(END)"
	@echo "Baking $(NAME)..."
	@$(CC) -I$(INCDIR) -I$(LIBDIR) -o $@ $^ $(LIBDIR)/$(LIBNAME) $(CFLAGS)
	@echo "$(GREEN)OK!$(END)"
	@echo "$(BOLD_GREEN)$(NAME) READY !$(END)"
clean:
	@echo "Removing objects..."
	@make clean -s -C $(LIBDIR)
	@rm -rf $(OBJDIR)
	@echo "$(GREEN)Done!$(END)"
fclean: clean
	@echo "Cleaning everything..."
	@make fclean -s -C $(LIBDIR)
	@rm -f $(NAME)
	@echo "$(GREEN)Done!$(END)"
	@echo "$(BOLD_GREEN)Everything is clean!$(END)"
re: fclean all
-include ${DEPS}


