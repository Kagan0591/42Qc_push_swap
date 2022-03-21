/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:31:09 by tchalifo          #+#    #+#             */
/*   Updated: 2022/02/28 13:31:09 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "libft.h"

typedef enum t_bool
{
	false,
	true
}			t_bool;

typedef struct t_dlinklst
{
	long long int		arg;
	int					*arg_binary;
	struct t_dlinklst	*next;
	struct t_dlinklst	*previous;
}				t_dlinklst;

typedef struct t_container
{
	t_dlinklst	*stack_a;
	t_dlinklst	*stack_b;
	int			dualmouv_flag;
}				t_container;

t_container		*initmem(void);
t_container		*clearmem(t_container *p_data);
void			clear_int_tab(int **tab, int size);
void			clear_char_tab(char **tab, int size);
long long int	ft_atoll(const char *str);
int				str_isnumber(char *str);
int				nbr_isint(long long int nb);
int				nbr_isequal(long long int nb1, long long int nb2);
int				lst_nodevalues_isunique(t_dlinklst *lst);
int				arg_isunique_doublyll(char *argument, t_dlinklst *stack);
t_dlinklst		*ft_stknew_dlink(long long int nbr, int *arg_binary);
t_dlinklst		*stkadd(t_dlinklst *p_stk, long long int nbr, int *arg_bin);
t_dlinklst		*stkadd_b(t_dlinklst *p_stk, long long int nbr, int *arg_bin);
void			ft_stkdelone_dlink(t_dlinklst *p_stk);
void			ft_stkclear_dlink(t_dlinklst *p_stk);
void			secure_del(t_dlinklst *p_stk);
t_bool			ft_stk_isempty_dlink(t_dlinklst *p_stk);
int				ft_stksize_dlink(t_dlinklst *p_stk);
void			ft_print_node_dlink(t_dlinklst *p_stk);
void			ft_print_stack_dlink(t_dlinklst *p_stk);
t_dlinklst		*return_to_top(t_dlinklst *p_stk);
t_dlinklst		*swap_a(t_dlinklst *p_stk);
t_dlinklst		*swap_b(t_dlinklst*p_stk);
void			push_to_a(t_container *p_data);
void			push_to_b(t_container *p_data);
t_dlinklst		*rotate_a(t_dlinklst *p_stk, int flag);
t_dlinklst		*rotate_b(t_dlinklst *p_stk, int flag);
t_dlinklst		*reverse_rotate_a(t_dlinklst *p_stk, int flag);
t_dlinklst		*reverse_rotate_b(t_dlinklst *p_stk, int flag);
void			reverse_rotate_ab(t_container *p_data);
void			rotate_ab(t_container *p_data);
t_dlinklst		*micro_sort(t_dlinklst *stack);
t_dlinklst		*mini_sort(t_container *p_data);
t_dlinklst		*big_sort(t_container *p_data);

#endif
