#-------------------------------- VARIABLES --------------------------------#
NAME	=	libft.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
AR		= 	ar rcs 
RM		= 	rm -f

#-------------------------------- DIRECTORIES --------------------------------#
INCLUDE_DIR		= include
LIST_DIR		= ./src/list/
TAB_DIR			= ./src/free_tab/
LIST_DB_CIR_DIR	= ./src/list_db_cir/
CHAR_DIR		= ./src/char/
STRING_DIR		= ./src/string/
IO_DIR			= ./src/io/
MEMORY_DIR		= ./src/memory/
ADVANCE_DIR		= ./src/advance/
OBJ_DIR			= .obj/

#-------------------------------- SOURCE FILES --------------------------------#

LIST_SRCS			=	ft_lstadd_front.c ft_lstlast.c \
						ft_lstadd_back.c ft_lstsize.c \
						ft_lstdelone.c ft_lstclear.c \
						ft_lstiter.c ft_lstmap.c \
						ft_lstnew.c 

TAB_SRCS			=	free_tab.c

LIST_DB_CIR_SRCS	=	ft_lstadd_back_db_cir.c ft_lstsize_db_cir.c \
						ft_lstclear_db_cir.c \
						ft_lstnew_db_cir.c ft_lstadd_front_db_cir.c

CHAR_SRCS			=	ft_isalpha.c ft_isdigit.c ft_isascii.c \
						ft_isprint.c ft_isalnum.c ft_toupper.c \
						ft_tolower.c 

STRING_SRCS			=	ft_strlen.c ft_strchr.c ft_strrchr.c \
						ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
						ft_strncmp.c ft_strjoin.c ft_str_free_to_join.c \
						ft_strtrim.c ft_strmapi.c ft_striteri.c \
						ft_strdup.c ft_substr.c 
					
IO_SRCS				=	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
						ft_putnbr_fd.c print_digit.c print_pointer.c 

MEMORY_SRCS			=	ft_memset.c ft_bzero.c ft_memcpy.c \
						ft_memchr.c ft_memcmp.c ft_memmove.c \
						ft_calloc.c 

ADVANCE_SRCS		=	ft_atoi.c ft_split.c ft_itoa.c \
						get_next_line.c ft_printf.c 

SRCS			=	$(addprefix $(LIST_DIR), $(LIST_SRCS)) \
					$(addprefix $(TAB_DIR), $(TAB_SRCS)) \
					$(addprefix $(CHAR_DIR), $(CHAR_SRCS)) \
					$(addprefix $(STRING_DIR), $(STRING_SRCS)) \
					$(addprefix $(IO_DIR), $(IO_SRCS)) \
					$(addprefix $(MEMORY_DIR), $(MEMORY_SRCS)) \
					$(addprefix $(ADVANCE_DIR), $(ADVANCE_SRCS)) \
					$(addprefix $(LIST_DB_CIR_DIR), $(LIST_DB_CIR_SRCS)) \


#-------------------------------- OBJECTS --------------------------------#
OBJS			=	$(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))
DEPENDENCIES	=	$(OBJS:.o=.d)

#-------------------------------- PROGRESS BAR --------------------------------#
TOTAL_FILES		:= $(shell find $(SRCS) -type f -name "*.c" -newer $(NAME) 2>/dev/null | wc -l)
ifeq ($(TOTAL_FILES),0)
	TOTAL_FILES = $(words $(OBJS))
endif
CURRENT_FILE	:= 0
BAR_LENGTH		:= 25

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
	@printf "\r$(CYAN)$(BOLD)Compiling libft: $(RESET)["
	@n=$(CURRENT_FILE); \
	total=$(TOTAL_FILES); \
	pct=$$(expr $$n '*' 100 / $$total); \
	fill=$$(expr $$n '*' $(BAR_LENGTH) / $$total); \
	empty=$$(expr $(BAR_LENGTH) - $$fill); \
	printf "$(GREEN)%*s$(RESET)" $$fill "" | tr ' ' '='; \
	printf "%*s" $$empty "" | tr ' ' ' '; \
	if [ $$n -eq $$total ]; then \
		printf "] $(BLUE)$(BOLD)%3d%%$(RESET) (%d/%d)" $$pct $$n $$total; \
	else \
		printf "] $(BOLD)%3d%%$(RESET) (%d/%d)" $$pct $$n $$total; \
	fi; \
	if [ $$n = $$total ]; then printf "\n"; fi
endef


#-------------------------------- RULES --------------------------------#

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n$(BLUE)$(BOLD)[INFO]$(RESET) $(WHITE)Creating library...$(RESET)\n"
	@$(AR) $(NAME) $(OBJS)
	@printf "$(GREEN)$(BOLD)[SUCCESS]$(RESET) $(WHITE)Library built successfully!$(RESET)\n"


$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	$(call draw_progress_bar)
	@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -MMD -MP -c $< -o $@

clean:
	@printf "$(ORANGE)$(BOLD)[CLEAN]$(RESET) $(WHITE)Cleaning object files from libft...$(RESET)\n"
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@printf "$(ORANGE)$(BOLD)[CLEAN]$(RESET) $(WHITE)Removing library...$(RESET)\n"
	@$(RM) $(NAME)
	@printf "$(GREEN)$(BOLD)[DONE]$(RESET) $(WHITE)Clean complete libft!$(RESET)\n"

re: fclean
	@$(MAKE) --silent all

print-%:
	@echo $($(patsubst print-%,%,$@))

-include $(DEPENDENCIES)

.PHONY: all clean fclean re print-%
