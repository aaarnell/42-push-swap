#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

enum	e_Ops {
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

typedef struct s_vrb
{
	t_list		*st1;
	t_list		*st2;
	t_list		*tmp;
	int			min;
	int			avg;
	int			max;
	int			ln1;
	int			ln2;
	int			dp1;
	int			dp2;
	int			dp1_t;
	int			dp2_t;
	int			mv;
	int			c_op;
	int			c_op_t;
	int			s_drc;
	enum e_Ops	op1;
	enum e_Ops	op2;
}	t_vrb;

t_list	*ft_crtlst(char **argv);
int		ft_chkord(t_list *lst);
void	srch_mnavmx(t_list *lst, int *min, int *avg, int *max);
void	ft_trnstmnx(t_vrb *vr, int n_st, int s_mnx);

int		ft_chkdup(char **argv);
int		ft_chknbr(char **argv);
int		ft_chkmnxint(char **argv);

void	ft_lstswp(t_list **lst);
void	ft_lstpush(t_list **lst1, t_list **lst2);
void	ft_lstrot(t_list **lst);
void	ft_lstrev(t_list **lst);
void	ft_pswp(t_vrb *vr, enum e_Ops op);
void	ft_putsop(enum e_Ops *op);
void	srt_3itm(t_vrb *vr);
void	srt_6itm(t_vrb *vr);
void	srt100(t_vrb *vr);
int		ft_cnt_dp(t_list *lst, int elm, int n_st, int cnt);
void	ft_chkmv(t_vrb *vr);

#endif
