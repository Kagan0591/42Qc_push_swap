###_*_*_*_*_*_*_*_*_*_*_*_*_Makefile_ft_printf_*_*_*_*_*_*_*_*_*_*_*_*_###
## Pour compiler les bonus, si il y a en a, d/commenter les lignes B_SRCS_FILES,
## B_SRCS_DIR, B_SRCS et dans les instructions de la ligne OBJS_FILES,
## décommenter $(B_SRCS_FILES:.c=.o)

###-------------------------# VARIABLES ##-------------------------###
NAME = push_swap

SRCS_FILES 		=	push_swap.c \
					push_swap_utils.c \
					push_swap_stack_functions.c \
					push_swap_sort_functions.c \
					push_swap_algo1.c \
					#radix_sort.c \
					#quicksort.c \

#B_SRCS_FILES	= 	 \

## Nommer les fichiers objets
OBJS_FILES 	= $(SRCS_FILES:.c=.o) #$(B_SRCS_FILES:.c=.o) # Utilise les noms de fichier de la variable SRCS_FILES et interprète le suffix .c en .o

### Repertoires ###
SRCS_DIR 	= srcs/
#B_SRCS_DIR 	= bonus_srcs/
OBJS_DIR	= objs/
INCLUDE_DIR = include/
LIBFT_DIR 	= 42Qc_libft/

SRCS 		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
#B_SRCS 		= $(addprefix $(B_SRCS_DIR), $(B_SRCS_FILES))
OBJS 		= $(addprefix $(OBJS_DIR), $(OBJS_FILES))
VPATH 		= $(SRCS_DIR) $(B_SRCS_DIR)

### Compilations et archivage ###
CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra -g
AR 			= ar -cr

### Autres Fonctions ###
RM 			= @rm -rf
NORMINETTE 	= norminette
LIBFT		= $(MAKE) bonus -C $(LIBFT_DIR)

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

$(OBJS_DIR)%.o:%.c
	${CC} ${CFLAGS} -I${LIBFT_DIR} -I${INCLUDE_DIR} -o $@ -c $<

$(NAME): $(OBJS)
	${LIBFT}
	${CC} ${OBJS} -L${LIBFT_DIR} -lft -o ${NAME}
	@echo "${OBJS} ${GREEN} ${BOLD}\n\nObjects files are created successfully\n${END}"

#bonus: $(NAME) $(BONUS_OBJS)
#	@${ARCHIVE} ${NAME} ${BONUS_OBJS}
#	@echo "${BONUS_OBJS} ${GREEN} ${BOLD}\n\nObjects files And bonus objects files are added to the archive libftprintf.a correctly\n${END}"

obj:
	@mkdir -p ${OBJS_DIR}

test: norm
	${CC} ${CFLAGS} -Og -L${LIBS_DIR} -lft -I${INCLUDE_DIR} -o test ${SRCS}
	valgrind ./test

norm:
	$(NORMINETTE)

clean:
	${RM} ${OBJS}
	@make -C $(LIBFT_DIR) fclean
	@echo "${BONUS_OBJS} ${GREEN} ${BOLD}\n\nObjects files, possibly bonus objects files have been deleted correctly\n${END}"

fclean:	clean
	${RM} ${NAME} ${OBJS_DIR}
	@echo "${GREEN} ${BOLD}\nThe executable file have been deleted too\n${END}"

re:	fclean all

phony:all norm test exec clean fclean re bonus
