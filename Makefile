



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
_SRCS	=	buffer.c \
			build_map.c \
			build_map_utils.c \
			check_file.c \
			check_format.c \
			convert.c \
			display_3d_down.c \
			display_3d_up.c \
			display_all.c \
			display_all_reverse.c \
			display_all_utils.c \
			draw_line.c \
			fitter.c \
			flooding.c \
			floor_ceil_part.c \
			fov.c \
			free_parsing.c \
			init_img.c \
			main.c \
			move_w_s.c \
			pixel_and_color.c \
			player.c \
			read_file.c \
			rotate.c \
			start_3D.c \
			texture_part.c \
			texture_part_utils.c \
			toggle.c \
			valid_wall.c \
			xpm_correction.c \
			xpm_first.c \
			xpm_parse.c
# --------------------------------- end srcs --------------------------------- #




SRC            = $(addprefix $(SRCDIR)/, $(_SRCS))
OBJ            = $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
HEADER         = $(addprefix $(INCDIR)/, $(NAME).h)
LIBX           = -L minilibx/ 
LIBXFLAGS      = -lmlx -lXext -lX11 -lz -lm




##### Makefile work ####
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	@mkdir -p $(@D)
	@$(CC) -c $(CFLAGS) -I$(LIBDIR) -I$(INCDIR) $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo -e "Baking $(LIBDIR)..."
	@make -s -C $(LIBDIR)
	@echo -e "$(GREEN)OK!$(END)"
	
	@echo -e "Baking $(LIBDIR)..."
	@make --no-print-directory -C minilibx
	@echo -e "$(GREEN)OK!$(END)"
	
	@echo -e "Baking $(NAME)..."
	@$(CC) -I$(INCDIR) -I$(LIBDIR) -o $@ $^ $(LIBDIR)/$(LIBNAME) $(CFLAGS) $(LIBX) $(LIBXFLAGS)
	@echo -e "$(GREEN)OK!$(END)"
	
	@echo -e "$(BOLD_GREEN)$(NAME) READY !$(END)"

clean:
	@echo -e "Removing objects..."
	@make clean -s -C $(LIBDIR)
	@make clean --no-print-directory -C minilibx
	@rm -rf $(OBJDIR)
	@echo -e "$(GREEN)Done!$(END)"

fclean: clean
	@echo -e "Cleaning everything..."
	@make fclean -s -C $(LIBDIR)
	@rm -f $(NAME)
	@echo -e "$(GREEN)Done!$(END)"
	@echo -e "$(BOLD_GREEN)Everything is clean!$(END)"

re: fclean all

-include ${DEPS}






