#-------------------------------- VARIABLES --------------------------------#

NAME			=	pipex
NAME_DEBUG		=	pipex_debug
CC		 		=	cc
CFLAGS			=	-Wall -Wextra -Werror
DEBUG_FLAGS		=	-Wmissing-prototypes -Wno-padded -Wall -Wextra -g3
DEP_FLAGS		=	-MMD -MP

#-------------------------------- DIRECTORIES --------------------------------#

LIBFT_DIR		=	./lib/libft
INCLUDE_DIR		=	include
MAIN_DIR		=	./src/
OBJ_DIR			=	.obj/
OBJ_DIR_DEBUG	=	.obj_debug/


#-------------------------------- INCLUDES & FLAGS --------------------------------#

INCLUDES		=	-I $(INCLUDE_DIR) \
					-I ./lib/libft/include \

#-------------------------------- LIBRARIES --------------------------------#

LIBFT			=	$(LIBFT_DIR)/libft.a

#-------------------------------- SOURCE FILES --------------------------------#

MAIN_SRCS		=	main.c parsing.c exec.c heredoc.c utils.c pipex.c

SRCS			=	$(addprefix $(MAIN_DIR), $(MAIN_SRCS))

#-------------------------------- OBJECTS --------------------------------------#

OBJS			=	$(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))
OBJS_DEBUG		=	$(patsubst %.c,$(OBJ_DIR_DEBUG)%.o,$(SRCS))

DEPENDENCIES	=	$(OBJS:.o=.d)

#-------------------------------- PROGRESS BAR --------------------------------#

TOTAL_FILES		:=	$(shell find $(SRCS) -type f -name "*.c" -newer $(NAME) 2>/dev/null | wc -l)
ifeq ($(TOTAL_FILES),0)
	TOTAL_FILES =	$(words $(SRCS))
endif
CURRENT_FILE	:=	0
BAR_LENGTH		:=	50

#-------------------------------- COLORS --------------------------------#

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
	printf "] $(BOLD)%3d%%$(RESET) (%d/%d)" $$pct $$n $$total; \
	if [ $$n = $$total ]; then printf "\n"; fi
endef

#-------------------------------- RULES --------------------------------#


all: $(NAME)

$(LIBFT): libft

libft:
	@$(MAKE) --silent -C $(LIBFT_DIR)
	
$(NAME): $(LIBFT) $(OBJS)
	@printf "$(BLUE)$(BOLD)Linking objects...$(RESET)\n"
	@$(CC) $(OBJS) -o $(NAME) $(DEP_FLAGS) $(LIBFT)
	@printf "$(GREEN)$(BOLD)Build successful!$(RESET) Created $(BOLD)$(NAME)$(RESET)\n"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	$(call draw_progress_bar)
	@$(CC) $(DEFINE) $(INCLUDES)  -c $< -o $@
	@if [ $(CURRENT_FILE) = $(TOTAL_FILES) ]; then echo; fi

debug: $(NAME_DEBUG)

$(NAME_DEBUG): $(LIBFT) $(OBJS_DEBUG)
	@printf "$(BLUE)$(BOLD)Linking objects...$(RESET)\n"
	@$(CC) $(DEBUG_FLAGS) $(OBJS_DEBUG) -o $(NAME_DEBUG) $(DEP_FLAGS) $(LIBFT)
	@printf "$(GREEN)$(BOLD)Build successful!$(RESET) Created $(BOLD)$(NAME_DEBUG)$(RESET)\n"

$(OBJ_DIR_DEBUG)%.o: %.c
	@mkdir -p $(dir $@)
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	$(call draw_progress_bar)
	@$(CC) $(DEBUG_FLAGS) $(DEFINE) $(INCLUDES)  -c $< -o $@
	@if [ $(CURRENT_FILE) = $(TOTAL_FILES) ]; then echo; fi

clean:
	@printf "$(BLUE)Cleaning object files from $(NAME)...$(RESET)\n"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) --silent -C $(LIBFT_DIR) $@

fclean:
	@$(MAKE) --silent -C $(LIBFT_DIR) $@
	@printf "$(BLUE)Removing executable from $(NAME)...$(RESET)\n"
	@rm -f $(NAME)
	@printf "$(BLUE)Cleaning object files from $(NAME)...$(RESET)\n"
	@rm -rf $(OBJ_DIR)
	@printf "$(GREEN)Clean complete $(NAME)!$(RESET)\n"

re: fclean
	@$(MAKE) --silent all

print-%:
	@echo $($(patsubst print-%,%,$@))

-include $(DEPENDENCIES)

.PHONY: all clean fclean re libft print-%