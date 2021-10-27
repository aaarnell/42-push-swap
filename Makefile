SRC_LIB		=	./libft
LIBFT		=	libft.a

NAME 	= 	push_swap

NAME_B 	= 	checker

HD		=	push_swap.h

FLAGS	= 	-Wall -Werror -Wextra

SRS		= 	main.c			utils_chk.c			utils_swap.c	\
			utils_add.c		utils_add2.c		sort_3_items.c	\
			sort_6_items.c	sort_100_items.c

SRS_B	= 	main_ck.c		utils_chk.c			utils_swap.c	\
			utils_add.c

OBJS	=	$(SRS:.c=.o)

OBJS_B	=	$(SRS_B:.c=.o)

all		:	$(NAME)

bonus	:	$(NAME_B)

%.o		:	%.c $(HD)
			gcc $(FLAGS) -g -c $< -o $@ -I $(HD)

$(NAME)	: 	$(OBJS)
			$(MAKE) -C $(SRC_LIB)
			gcc $(FLAGS) -g $(OBJS) $(SRC_LIB)/$(LIBFT) -o $(NAME)

$(NAME_B) :	$(OBJS_B)
			$(MAKE) -C $(SRC_LIB)
			gcc $(FLAGS) -g $(OBJS_B) $(SRC_LIB)/$(LIBFT) -o $(NAME_B)

clean	:
			$(MAKE) clean -C $(SRC_LIB)
			rm -f $(OBJS) $(OBJS_B)

fclean	:	clean
			$(MAKE) fclean -C $(SRC_LIB)
			rm -f $(NAME) $(NAME_B)

re		:	fclean all

re_bns	:	fclean bonus

.PHONY: all clean fclean re re_bns
