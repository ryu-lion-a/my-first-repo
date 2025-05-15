/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryutaro <kryutaro@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:52:05 by kryutaro          #+#    #+#             */
/*   Updated: 2025/05/15 17:29:56 by kryutaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char *argv[])
{
	int	*numslot;
	int *numslotrank;
	int *rank;
	t_box result;
	result.count = 0;

	numslot = makenumslot(argc, argv);
	numslotrank = makenumslot(argc, argv);
	if (numslot == NULL)
	{
		write(1, "er", 2);
		return (-1);
	}
	numslot = sort(numslot, argc - 1, 0);
	if(samenumcheck(numslot,argc - 1) == -1){
		write(1, "er", 2);
		return (-1);
	}
	rank = makerank(numslot,numslotrank,argc - 1);
	
	result.a = rank;
	result.b = (int *)malloc(sizeof(int)*(argc - 1));
	result.a_size = argc - 1;
	result.b_size = 0;
	result = rra(result);
	//result = ra(result);
	// numslot = change(numslot, 3, 0, 3);
	// printf("%d\n", numslot[0]);
	// printf("%d\n", numslot[1]);
	// printf("%d\n", numslot[2]);
	// printf("%d\n", numslot[3]);
	// printf("%d\n", numslot[4]);
	// printf("%d\n", numslot[5]);
	printf("%d\n",result.a_size);
	printf("%d\n",result.b_size);
	printf("%d ", result.a[0]);
	printf("%d ", result.a[1]);
	printf("%d ", result.a[2]);
	printf("%d ", result.a[3]);
	printf("%d ", result.a[4]);
	printf("%d\n", result.a[5]);
	// printf("%d ", result.b[0]);
	// printf("%d ", result.b[1]);
	// printf("%d ", result.b[2]);
	// printf("%d ", result.b[3]);
	// printf("%d ", result.b[4]);
	// printf("%d\n", result.b[5]);

	free(rank);
	free(numslot);
}

int *makerank(int *numslot,int *numslotrank,int l){
int i = 0;
int *rank;
rank = (int *)malloc(sizeof(int)*l);
while(i < l){
	int j = 0;
	while(j < l){
		if(numslot[j] == numslotrank[i]){
			rank[i] = j;
			break;
		}
		j++;
	}
	i++;
}
return rank;
}

int samenumcheck(int *numslot,int l){
	int i = 0;
	while(i < l - 1){
		if(numslot[i] == numslot[i + 1]){
			return -1;
		}
		i++;
	}
	return 0;
}

int	*makenumslot(int c, char **cslot)
{
	int			*numslot;
	int			i;
	t_number	box;

	i = 1;
	numslot = (int *)malloc(sizeof(int) * (c - 1));
	if (!numslot)
		return (NULL);
	while (i < c)
	{
		box = ft_atoi(cslot[i]);
		if (box.che == -1)
		{
			return (NULL);
		}
		numslot[i - 1] = box.num;
		i++;
	}
	return (numslot);
}

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}
int	intmincheck(char *c)
{
	int	i;

	if (ft_strlen(c) != 11)
		return (-1);
	i = 0;
	if (c[0] == '-' && c[1] == '2' && c[2] == '1' && c[3] == '4')
		i++;
	if (c[4] == '7' && c[5] == '4' && c[6] == '8' && c[7] == '3')
		i++;
	if (c[8] == '6' && c[9] == '4' && c[10] == '8' && c[11] == '\0')
		i++;
	if (i == 3)
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}
t_number	atoisupo(char *c, int i)
{
	t_number	result;

	result.che = 0;
	result.num = 0;
	while (c[i] != '\0')
	{
		if ((result.num > (2147483647 - (c[i] - '0')) / 10) || ((c[i] < '0')
				|| ('9' < c[i])))
		{
			result.che = -1;
			result.num = 0;
			return (result);
		}
		result.num = (c[i] - '0') + result.num * 10;
		i++;
	}
	return (result);
}

t_number	ft_atoi(char *c)
{
	int			i;
	int			sign;
	t_number	result;

	i = 0;
	sign = 1;
	result.che = 0;
	result.num = 0;
	if (intmincheck(c) == 0)
	{
		result.num = -2147483648;
		return (result);
	}
	if (c[0] == '-')
	{
		sign = -1;
		i++;
	}
	else if (c[0] == '+')
		i++;
	result = atoisupo(c, i);
	result.num = result.num * sign;
	return (result);
}

int	check(int *numslot, int l, int s)
{
	int	i;

	i = s;
	while (i < l - 1)
	{
		if (numslot[i + 1] < numslot[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

// int	*sorthelp(int pibotnum, int pibot, int *numslot, int l)
// {
// 	while (f != 0)
// 	{
// 		f = 0;
// 		i = l - 1;
// 		while (pibotnum < i)
// 		{
// 			if (numslot[i] < pibot)
// 			{
// 				numslot[pibotnum] = numslot[i];
// 				numslot[i] = pibot;
// 				pibotnum = i;
// 				f = 1;
// 				break ;
// 			}
// 			i--;
// 		}
// 		i = 0;
// 		while (i < pibotnum)
// 		{
// 			if (numslot[i] > pibot)
// 			{
// 				numslot[pibotnum] = numslot[i];
// 				numslot[i] = pibot;
// 				pibotnum = i;
// 				f = 1;
// 				break ;
// 			}
// 			i++;
// 		}
// 	}
// }

int	*sort(int *numslot, int l, int s) // sは個数
{
	int i;
	int pibot;
	int pibotnum;
	int f;
	pibotnum = s;
	pibot = numslot[pibotnum];

	while (f != 0)
	{
		f = 0;
		i = l - 1;
		while (pibotnum < i)
		{
			if (numslot[i] < pibot)
			{
				numslot[pibotnum] = numslot[i];
				numslot[i] = pibot;
				pibotnum = i;
				f = 1;
				break ;
			}
			i--;
		}
		i = 0;
		while (i < pibotnum)
		{
			if (numslot[i] > pibot)
			{
				numslot[pibotnum] = numslot[i];
				numslot[i] = pibot;
				pibotnum = i;
				f = 1;
				break ;
			}
			i++;
		}
	}

	if (check(numslot, l, s) == -1)
	{
		if(pibotnum != s)
		numslot = sort(numslot, pibotnum, s);
		if(pibotnum + 1 != l)
		numslot = sort(numslot, l, pibotnum + 1);
	}
	return (numslot);
}


