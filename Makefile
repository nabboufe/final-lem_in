NAME		=		lem-in

LIBFT_A		=		libft.a

INCLUDES	=		-Iinclude

SRCS		=		srcs/display_instructions.c				\
					srcs/bfs_functions.c					\
					srcs/ants_repartition.c					\
					srcs/find_best_paths.c					\
					srcs/free_functions.c					\
					srcs/main.c								\
					srcs/initialize.c						\
					srcs/links_functions.c					\
					srcs/param_functions.c					\
					srcs/parser_functions.c					\
					srcs/parser.c							\
					srcs/path_functions.c					\
					srcs/queue_functions.c					\
					srcs/room_functions.c


OBJ			=		$(SRCS:.c=.o)

CC			=		gcc

CFLAGS		=		-Wall -Wextra -Werror -g3

DECHET		=		*.dSYM

all			:		$(LIBFT_A) $(NAME)

$(LIBFT_A)	:		
	@make -C libft/ all clean >/dev/null
	@echo "libft compilation is done !\n"
	@mv libft/libft.a .

$(NAME)		:		$(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(LIBFT_A) $(OBJ) $(INCLUDES) -o $(NAME)
	@rm -rf $(DECHET)

clean		:
	@rm -rf $(OBJ) $(DECHET)
	@echo "clean completed !"

fclean		:		clean
	@rm -rf $(NAME) $(LIBFT_A) $(DECHET) &>/dev/null
	@echo "fclean completed !\n"

re			:		fclean all

.PHONY		:		fclean all
