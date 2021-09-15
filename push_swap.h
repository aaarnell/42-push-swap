#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void	wr_wr(void *cnt);	//Функция для печати цифры из контента. Удалить при публикации
void	wr_prl_st(t_list *lst1, t_list *lst2);	//Функция для печати контента стеков. Удалить при публикации
t_list	*ft_crtlst(char **argv);
int		chk_ord(t_list *lst);
void	srch_minmax(t_list *lst, int *min, int *max);

t_list	*ft_lstswp(t_list *lst);
void	ft_lstpush(t_list **lst1, t_list **lst2);
t_list	*ft_lstrot(t_list *lst);
t_list	*ft_lstrev(t_list *lst);
t_list	*sort1(t_list *lst);
t_list	*sort2(t_list *lst);
t_list	*sort3(t_list *lst);




#endif
