
SRC_LIB		=	./libft
LIBFT		=	libft.a

NAME 	= 	push_swap

HD		=	push_swap.h

FLAGS	= 	-Wall -Werror -Wextra

SRS		= 	main.c		utils_add.c		utils_swap.c	\
			sort1.c		sort2.c			sort3.c			\


OBJS	=	$(SRS:.c=.o)

all : 		$(NAME)

%.o :		%.c $(HD)
			gcc $(FLAGS) -g -c $< -o $@ -I $(HD)

$(NAME)	: 	$(OBJS)
			$(MAKE) -C $(SRC_LIB)
			gcc $(FLAGS) -g $(OBJS) $(SRC_LIB)/$(LIBFT) -o $(NAME)

clean :
			$(MAKE) clean -C $(SRC_LIB)
			rm -f $(OBJS)

fclean : 	clean
			$(MAKE) clean -C $(SRC_LIB)
			rm -f $(NAME)

re :		fclean all

.PHONY: all clean fclean re