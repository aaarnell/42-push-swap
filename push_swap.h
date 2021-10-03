#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

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

t_list	*ft_crtlst(char **argv);
int		chk_ord(t_list *lst);
void	srch_minmax(t_list *lst, int *min, int *max);

void	ft_lstswp(t_list **lst);
void	ft_lstpush(t_list **lst1, t_list **lst2);
void	ft_lstrot(t_list **lst);
void	ft_lstrev(t_list **lst);
void	ft_pushswap(t_list **lst1, t_list **lst2, char *op);
void	ft_pushswap2(t_list **lst1, t_list **lst2, char *op, char *l_op);
void	ft_pushswap4_2(t_list **lst1, t_list **lst2, enum Ops op, enum Ops *l_op);
void	ft_put_op(char *op, char *l_op);
void	ft_put_op4_2(enum Ops *op, enum Ops *l_op);
t_list	*sort1(t_list *lst);
t_list	*sort2(t_list *lst);
t_list	*sort3(t_list *lst);
t_list	*sort3a(t_list *lst);
t_list	*sort4(t_list *lst);
t_list	*sort4_1(t_list *lst);
t_list	*sort4_2(t_list *lst);

#endif
