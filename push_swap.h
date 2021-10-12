#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <stdarg.h>

void	wr_wr(void *cnt);	//Функция для печати цифры из контента. Удалить при публикации
void	wr_prl_st(t_list *lst1, t_list *lst2);	//Функция для печати контента стеков. Удалить при публикации
void	wr_st(t_list *lst);	//Функция для печати контента стека. Удалить при публикации

enum	Ops {
	NaN,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	SA,
	SB,
	SS
};

//void	chk_op(t_list *lst1, t_list *lst2, enum Ops *op); //Чекер - принимает команду, меняет элементы в стеках, и чекает, соответствует ли это оригинальным стекам

typedef struct s_vrb
{
	//Для чекнуть ошибки
	t_list		*st_1;
	t_list		*st_2;
	int			n_st;
	int			mstk1;
	int			mstk2;
	//Для чекнуть ошибки
	t_list		*st1;
	t_list		*st2;
	t_list		*tmp;
	int			ln1;
	int			ln2;
	int			dp1;
	int			dp2;
	int			mv;
	int			c_op;
	enum Ops	op1;
	enum Ops	op2;
} t_vrb;


/*
static char *OpNms[] = {
	"NaN",
	"pa\n",
	"pb\n",
	"ra\n",
	"rb\n",
	"rr\n",
	"rra\n",
	"rrb\n",
	"rrr\n",
	"sa\n",
	"sb\n",
	"ss\n"
};*/

t_list	*ft_crtlst(char **argv);
int		chk_ord(t_list *lst);
int		cnt_chs(t_list *lst);
void	srch_minmax(t_list *lst, int *min, int *max);

void	ft_lstswp(t_list **lst);
void	ft_lstpush(t_list **lst1, t_list **lst2);
void	ft_lstrot(t_list **lst);
void	ft_lstrev(t_list **lst);
//void	ft_pushswap(t_list **lst1, t_list **lst2, char *op);
//void	ft_pushswap2(t_list **lst1, t_list **lst2, char *op, char *l_op);
void	ft_pushswap4_2(t_list **lst1, t_list **lst2, enum Ops op, enum Ops *l_op);
void	ft_pushswap4_3(t_vrb *vr, enum Ops op, enum Ops *l_op);
//void	ft_put_op(char *op, char *l_op);
void	ft_put_op4_2(enum Ops *op, enum Ops *l_op);
//t_list	*sort1(t_list *lst);
//t_list	*sort2(t_list *lst);
//t_list	*sort3(t_list *lst);
//t_list	*sort3a(t_list *lst);
//t_list	*sort4(t_list *lst);
//t_list	*sort4_1(t_list *lst);
int		pr_srt_1it(t_list **lst1, t_list **lst2, enum Ops *l_op);
t_list	*srt_3itm(t_list *lst);
t_list	*srt_6itm(t_list *lst);
t_list	*srt100t(t_list *lst);
t_list	*srt100t_2(t_list *lst);
t_list	*srt100t_3(t_list *lst);
t_list	*srt100t_4(t_vrb *vr);
int		ft_cnt_dp(t_list *lst, int elm, int n_st);
void	ft_chk_mv(t_list **st1, t_list **st2, enum Ops *l_op);
void	ft_chk_mv2(t_vrb *vr, enum Ops *l_op);

#endif
