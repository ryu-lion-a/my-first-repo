/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryutaro <kryutaro@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:41:41 by kryutaro          #+#    #+#             */
/*   Updated: 2025/05/21 11:55:52 by kryutaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct
{
	int		num;
	int		che;

}			t_number;

typedef struct
{
	int		*a;
	int		a_size;
	int		*b;
	int		b_size;
	int		count;
	int		remain;
	int		*sizedata_a;
	int		*sizedata_b;
	int		sizedata_alen;
	int		sizedata_blen;
	int		ahead;
}			t_box;

// typedef struct
// {
// 	int *num;
// 	int *rank;
// }			t_rank;

int			*sorthelp(int pibotnum, int pibot, int *numslot, int l);
int			*makenumslot(int c, char **cslot);
int			*change(int *numslot, int l, int s, int i);
int			*sort(int *numslot, int l, int s);
t_number	ft_atoi(char *c);
int			samenumcheck(int *numslot, int l);
int			*makerank(int *numslot, int *numslotrank, int l);
// t_box sa(t_box result);
// t_box sb(t_box result);
// t_box ss(t_box result);
// t_box	pa(t_box result);
// t_box	pb(t_box result);
// t_box ra(t_box result);
// t_box rb(t_box result);
// t_box rra(t_box result);
// t_box	rrb(t_box result);
// t_box	rr(t_box result);
// t_box	rrr(t_box result);
t_box		sa(t_box result);
t_box		sb(t_box result);
t_box		sah(t_box result);
t_box		sbh(t_box result);
t_box		ss(t_box result);
t_box		pa(t_box result);
t_box		pb(t_box result);
t_box		ra(t_box result);
t_box		rb(t_box result);
t_box		rah(t_box result);
t_box		rbh(t_box result);
t_box		rra(t_box result);
t_box		rrb(t_box result);
t_box		rrah(t_box result);
t_box		rrbh(t_box result);
t_box		rr(t_box result);
t_box		rrr(t_box result);
int			*makeinit(int *longest, int size, int p);
int			*copypush(int *resulti, int *resultj, int size, int pushnum);
int			*lis(int *numbox, int size);
int			*revlis(int *numbox, int size);
int			revsizelis(int *numbox, int size);
int			sizelis(int *numbox, int size);
t_box		atob(t_box result);
t_box		btoa(t_box result);
t_box		pushswap(t_box result);
t_box		pushdata(t_box result, int lissize, int swich);
int			*quicksort(int *numslot, int left, int right);
int			*rrsize(int *sizedata_a, int sizedata_alen);
int			*sizedeltop(int *sizedata_a, int sizedata_alen);
int			*lisZ(int *numbox, int size);
int			longestcheck(int *result, int size);
t_box		makelong(t_box result, int move);
int			rlongestcheck(int *result, int size);
t_box		pushswap2(t_box result);

#endif