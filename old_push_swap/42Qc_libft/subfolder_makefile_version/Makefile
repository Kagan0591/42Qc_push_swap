###_*_*_*_*_*_*_*_*_*_*_*_*_Makefile_libft_*_*_*_*_*_*_*_*_*_*_*_*_###


###-------------------------# VARIABLES ##-------------------------###
NAME = libft.a

SRCS_FILES 		=	ft_atoi.c\
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_numlen.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putstr_nl.c \
			ft_split.c \
			ft_strchr.c \
			ft_strcpy.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \

B_SRCS_FILES	= 	ft_lstnew.c \
			ft_lstsize.c \
			ft_lstadd_front.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

### Nommer les fichiers objets ###
OBJS_FILES 	= $(SRCS_FILES:.c=.o) $(B_SRCS_FILES:.c=.o) # Utilise les noms de fichier de la variable SRCS_FILES et modifie le suffix .c en .o

### Repertoires ###
SRCS_DIR 	= srcs/
B_SRCS_DIR 	= bonus/srcs/
OBJS_DIR	= objs/
INCLUDE_DIR = include/

SRCS 		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
B_SRCS 		= $(addprefix $(B_SRCS_DIR), $(B_SRCS_FILES))
OBJS 		= $(addprefix $(OBJS_DIR), $(OBJS_FILES))
VPATH 		= $(SRCS_DIR) $(B_SRCS_DIR)

### Compilations et archivage ###
CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra
AR 			= ar -cr

### Autres Fonctions ###

RM 			= rm -rf
NORMINETTE 	= norminette

### Colour var ###

END			= \033[0m
BOLD		= \033[1m
ITALIC		= \033[3m
URL			= \033[4m
BLINK		= \033[5m
BLINK2		= \033[6m
SELECTED	= \033[7m

BLACK		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
VIOLET		= \033[35m
BEIGE		= \033[36m
WHITE		= \033[37m


###--------------------------## REGLES ##--------------------------###

all: obj $(NAME)
	@echo "$(RED)Red Color$(END)"

$(OBJS_DIR)%.o:%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ -c $< 

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

obj:
	@mkdir -p $(OBJS_DIR)

norm:
	$(NORMINETTE) $(SRCS) $(B_SRCS) include/*

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME) $(OBJS_DIR)

re:	fclean all

phony: clean fclean all re bonus norm
