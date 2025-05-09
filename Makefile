#-------------------------------- VARIABLES ----------------------------------#

NAME			=	pipex
NAME_DEBUG		=	pipex_debug
NAME_BONUS		=	pipex_bonus
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
DEBUG_CFLAGS	=	-Wmissing-prototypes -Wno-padded -Wall -Wextra -g3 -o3 
DEP_FLAGS		=	-MMD -MP

#-------------------------------- DIRECTORIES --------------------------------#

LIBFT			=	$(LIBFT_DIR)/libft.a
LIBFT_DIR		=	./lib/libft
INCLUDE_DIR		=	include
MAIN_DIR		=	./src/
OBJ_DIR			=	.obj/
OBJ_DIR_MAIN	=	$(OBJ_DIR)obj_main/
OBJ_DIR_BONUS	=	$(OBJ_DIR)obj_bonus/
OBJ_DIR_DEBUG	=	$(OBJ_DIR)obj_debug/


#-------------------------------- INCLUDES & FLAGS ---------------------------#

INCLUDES		=	-I $(INCLUDE_DIR) \
					-I ./lib/libft/include \

#-------------------------------- LIBRARIES ----------------------------------#

LIBFT			=	$(LIBFT_DIR)/libft.a

#-------------------------------- SOURCE FILES -------------------------------#

MAIN_SRCS		=	main.c parsing.c init.c utils.c pipex.c prepare_cmd.c wait_childs.c

BONUS_SRCS		=	main_bonus.c parsing.c init.c utils.c pipex.c prepare_cmd.c wait_childs.c

SRCS_PATH		=	$(addprefix $(MAIN_DIR), $(MAIN_SRCS))
SRCS_PATH_BONUS	=	$(addprefix $(MAIN_DIR), $(BONUS_SRCS))

#-------------------------------- OBJECTS ------------------------------------#

OBJS_MAIN		=	$(patsubst %.c,$(OBJ_DIR_MAIN)%.o,$(SRCS_PATH))
OBJS_BONUS		=	$(patsubst %.c,$(OBJ_DIR_BONUS)%.o,$(SRCS_PATH_BONUS))
OBJS_DEBUG		=	$(patsubst %.c,$(OBJ_DIR_DEBUG)%.o,$(SRCS_PATH))

DEPENDENCIES	=	$(OBJS_MAIN:.o=.d)

#-------------------------------- PROGRESS BAR -------------------------------#

TOTAL_FILES		:=	$(shell find $(SRCS_PATH) -type f -name "*.c" -newer $(NAME) 2>/dev/null | wc -l)
ifeq ($(TOTAL_FILES),0)
	TOTAL_FILES =	$(words $(SRCS_PATH))
endif
CURRENT_FILE	:=	0
BAR_LENGTH		:=	25

#-------------------------------- COLORS -------------------------------------#

BLACK		:=	\033[38;2;0;0;0m
RED			:=	\033[38;2;220;20;60m
GREEN		:=	\033[38;2;46;139;87m
BLUE		:=	\033[38;2;30;144;255m
YELLOW		:=	\033[38;2;255;215;0m
MAGENTA		:=	\033[38;2;186;85;211m
CYAN		:=	\033[38;2;0;206;209m
WHITE		:=	\033[38;2;255;255;255m
ORANGE		:=	\033[38;2;255;140;0m
PURPLE		:=	\033[38;2;147;112;219m
RESET		:=	\033[0m
BOLD		:=	\033[1m

define draw_progress_bar
	@printf "\r$(CYAN)$(BOLD)Compiling $(NAME): $(RESET)["
	@n=$(CURRENT_FILE); \
	total=$(TOTAL_FILES); \
	pct=`expr $$n '*' 100 / $$total`; \
	fill=`expr $$n '*' $(BAR_LENGTH) / $$total`; \
	empty=`expr $(BAR_LENGTH) - $$fill`; \
	printf "$(GREEN)%*s$(RESET)" $$fill "" | tr ' ' '='; \
	printf "%*s" $$empty "" | tr ' ' ' '; \
	if [ $$n -eq $$total ]; then \
		printf "] $(BLUE)$(BOLD)%3d%%$(RESET) (%d/%d)" $$pct $$n $$total; \
	else \
		printf "] $(BOLD)%3d%%$(RESET) (%d/%d)" $$pct $$n $$total; \
	fi; \
	if [ $$n = $$total ]; then printf "\n"; fi
endef

#-------------------------------- RULES --------------------------------------#

all: libft $(NAME)

libft:
	@$(MAKE) --silent -C $(LIBFT_DIR)
	
$(NAME): $(LIBFT) $(OBJS_MAIN)
	@printf "$(BLUE)$(BOLD)[INFO]$(RESET) $(WHITE)Linking objects...$(RESET)\n"
	@$(CC)  $(OBJS_MAIN) -o $(NAME) $(LIBFT)
	@printf "$(GREEN)$(BOLD)[SUCCESS]$(RESET) $(WHITE)Build successful!$(RESET) Created $(BOLD)$(CYAN)$(NAME)$(RESET)\n"

$(OBJ_DIR_MAIN)%.o: %.c
	@mkdir -p $(dir $@)
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	$(call draw_progress_bar)
	@$(CC) $(CFLAGS) $(DEFINE) $(INCLUDES) $(DEP_FLAGS) -c $< -o $@
	@if [ $(CURRENT_FILE) = $(TOTAL_FILES) ]; then echo; fi

bonus: libft $(NAME_BONUS)


$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
	@printf "$(MAGENTA)$(BOLD)[DEBUG]$(RESET) $(WHITE)Linking objects...$(RESET)\n"
	@$(CC) $(OBJS_BONUS) -o $(NAME_BONUS) $(LIBFT)
	@printf "$(GREEN)$(BOLD)[SUCCESS]$(RESET) $(WHITE)Build successful!$(RESET) Created $(BOLD)$(CYAN)$(NAME_BONUS)$(RESET)\n"

$(OBJ_DIR_BONUS)%.o: %.c
	@mkdir -p $(dir $@)
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	$(call draw_progress_bar)
	@$(CC) $(CFLAGS) $(DEFINE) $(INCLUDES) $(DEP_FLAGS) -c $< -o $@
	@if [ $(CURRENT_FILE) = $(TOTAL_FILES) ]; then echo; fi

debug: libft $(NAME_DEBUG)

$(NAME_DEBUG): $(LIBFT) $(OBJS_DEBUG)
	@printf "$(MAGENTA)$(BOLD)[DEBUG]$(RESET) $(WHITE)Linking objects...$(RESET)\n"
	@$(CC) $(OBJS_DEBUG) -o $(NAME_DEBUG) $(LIBFT)
	@printf "$(GREEN)$(BOLD)[SUCCESS]$(RESET) $(WHITE)Build successful!$(RESET) Created $(BOLD)$(CYAN)$(NAME_DEBUG)$(RESET)\n"

$(OBJ_DIR_DEBUG)%.o: %.c
	@mkdir -p $(dir $@)
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	$(call draw_progress_bar)
	@$(CC) $(DEBUG_CFLAGS) $(DEFINE) $(INCLUDES) $(DEP_FLAGS) -c $< -o $@
	@if [ $(CURRENT_FILE) = $(TOTAL_FILES) ]; then echo; fi

clean:
	@printf "$(ORANGE)$(BOLD)[CLEAN]$(RESET) $(WHITE)Cleaning object files from $(CYAN)$(NAME)$(RESET)...\n"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) --silent -C $(LIBFT_DIR) $@

fclean:
	@$(MAKE) --silent -C $(LIBFT_DIR) $@
	@printf "$(ORANGE)$(BOLD)[CLEAN]$(RESET) $(WHITE)Removing executables...$(RESET)\n"
	@rm -f $(NAME)
	@rm -f $(NAME_DEBUG)
	@rm -f $(NAME_BONUS)
	@printf "$(ORANGE)$(BOLD)[CLEAN]$(RESET) $(WHITE)Cleaning object files from $(CYAN)$(NAME)$(RESET)...\n"
	@rm -rf $(OBJ_DIR)
	@printf "$(GREEN)$(BOLD)[DONE]$(RESET) $(WHITE)Clean complete!$(RESET)\n"

re: fclean
	@$(MAKE) --silent all

print-%:
	@echo $($(patsubst print-%,%,$@))

-include $(DEPENDENCIES)

.PHONY: all clean fclean re libft print-% debug
